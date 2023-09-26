#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"
#include "esp_timer.h"
#include "sdkconfig.h"

#define MAX_SOCKETS 16
#define RESULT_BUFFER_SIZE 16*1024

static const char *TAG = "example";

struct
{
    int socket;
    const char* url;
} connections[MAX_SOCKETS];


char* esp32_c3_http_post(const char* url,const char* web_path,const char* headers,const char* data)
{
    const struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
    };

    struct addrinfo *res;
    int s, r;

    int data_len = strlen(data);
    char *request = malloc(strlen(web_path) + strlen(url) + strlen("80") + strlen(headers) + 64 + data_len);
    if (!request) {
        ESP_LOGE(TAG, "Failed to allocate memory for full request string");
        return NULL;
    }

    sprintf(request,
            "POST %s HTTP/1.1\r\n"
            "Host: %s:%s\r\n"
            "%s"
            "Content-Length: %zu\r\n"
            "\r\n"
            "%s",
			web_path,url,"80",headers, strlen(data), data);

    int err = getaddrinfo(url, "80", &hints, &res);
    if(err != 0 || res == NULL) {
        ESP_LOGE(TAG, "DNS lookup failed err=%d res=%p", err, res);
        free(request);
        return NULL;
    }

    s = socket(res->ai_family, res->ai_socktype, 0);
    if(s < 0) {
        ESP_LOGE(TAG, "... Failed to allocate socket.");
        freeaddrinfo(res);
        free(request);
        return NULL;
    }

    if(connect(s, res->ai_addr, res->ai_addrlen) != 0) {
        ESP_LOGE(TAG, "... socket connect failed errno=%d", errno);
        close(s);
        freeaddrinfo(res);
        free(request);
        return NULL;
    }

    if (write(s, request, strlen(request)) < 0) {
        ESP_LOGE(TAG, "... socket send failed");
        close(s);
        freeaddrinfo(res);
        free(request);
        return NULL;
    }
    ESP_LOGI(TAG, "... socket send success");


    // 定义超时时间
    struct timeval tv;
    tv.tv_sec = 5;  // 设置5秒超时
    tv.tv_usec = 0;

    // 使用lwip_setsockopt()函数设置超时时间
    if(lwip_setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        ESP_LOGE(TAG, "... failed to set socket read timeout");
        return NULL;
    }

    char recv_buf[2048];
    int i = 0;
    size_t total_size = 0;
    static char result[RESULT_BUFFER_SIZE];  // 创建全局的静态缓冲区
    do {
        memset(recv_buf, 0, sizeof(recv_buf));
        r = read(s, recv_buf, sizeof(recv_buf)-1);
        if (r > 0) {
            if (total_size + r > RESULT_BUFFER_SIZE - 1) {  // 检查是否超出缓冲区大小
                ESP_LOGE(TAG, "Result buffer overflow");
                break;
            }
            memcpy(result + total_size, recv_buf, r);
            total_size += r;
            i += r;
        } else if (r < 0) {
            break;
        }
    } while(r == 2048);

    result[total_size] = '\0';  // 在结果缓冲区末尾添加字符串结束符

    // 其他代码不变
    //close(s);
    free(request);
    freeaddrinfo(res);

    return result;
}
