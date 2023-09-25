/*
* @file  http.c 
* @brief http的简易接口
         A simple interface to http
* @date 2021.9.25
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

/*初始化http的底层硬件接口*/
int http_init(com_type type)
{
    if(type == UART)
    {
        COM_Init(type,115200);
    }
    else if (type == CAN)
    {
        
    }
    else if(type == ETHERNET)
    {

    }
    else
    {

    }
}


int http_post(const HttpRequest* request, char** response) 
{
    // 创建socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create socket");
        return -1;
    }
    
    // 解析host地址
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    if (inet_pton(AF_INET, request->host, &(server_address.sin_addr)) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }
    
    // 连接到服务器
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        return -1;
    }
    
    // 构建请求
    char request_buffer[BUFFER_SIZE];
    snprintf(request_buffer, BUFFER_SIZE, "%s %s HTTP/1.1\r\nHost: %s\r\n%s\r\n\r\n%s", 
        request->method, request->path, request->host, request->headers, request->body);
    
    // 发送请求
    if (send(client_socket, request_buffer, strlen(request_buffer), 0) < 0) {
        perror("Failed to send request");
        return -1;
    }
    
    // 接收响应
    char response_buffer[BUFFER_SIZE];
    int total_size = 0;
    int received_size;
    while ((received_size = recv(client_socket, response_buffer, BUFFER_SIZE - 1, 0)) > 0) {
        response_buffer[received_size] = '\0';
        *response = realloc(*response, total_size + received_size + 1);
        memcpy(*response + total_size, response_buffer, received_size);
        total_size += received_size;
    }
    
    // 处理响应
    if (received_size < 0) {
        perror("Failed to receive response");
        return -1;
    }
    
    // 关闭socket
    close(client_socket);
    
    // 返回响应大小
    return total_size;
}
