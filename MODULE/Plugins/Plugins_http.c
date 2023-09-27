/*
 * Plugins_http.c
 *
 *  Created on: 2023年9月27日
 *      Author: jinxinyang
 */
#include "../../MCAL/MCAL_CFG.h"


char* HTTP_Post(const char* url,const char* web_path,const char* headers,const char* data)
{
    int s;
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

    s=socket_init(url);
    if(s<0){
        free(request);
        return NULL;
    }

    if(socket_write(s,request)<0){
        free(request);
        return NULL;
    }

    char* result = socket_read(s);

    close(s);
    free(request);

    return result;
}

