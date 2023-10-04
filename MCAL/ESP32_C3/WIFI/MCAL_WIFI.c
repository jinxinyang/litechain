/*
 * MCAL_WIFI.c
 *
 *  Created on: 2023年9月27日
 *      Author: jinxinyang
 */
#include <string.h>
#include <stdint.h>
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
#include "MCAL_WIFI.h"
#include "../Core/MCAL_Core.h"

#define MAX_SOCKETS 16
#define RESULT_BUFFER_SIZE 16*1024*5

static const char *TAG = "example";

struct
{
    int socket;
    const char* url;
} connections[MAX_SOCKETS];


int socket_init(const char* url)
{
    const struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
    };
    struct addrinfo *res;
    int s;
    int err = getaddrinfo(url, "80", &hints, &res);
    if(err != 0 || res == 0) {
        ESP_LOGE(TAG, "DNS lookup failed err=%d res=%p", err, res);
        return -1;
    }
    s = socket(res->ai_family, res->ai_socktype, 0);
    if(s < 0) {
        ESP_LOGE(TAG, "... Failed to allocate socket.");
        freeaddrinfo(res);
        return -1;
    }
    if(connect(s, res->ai_addr, res->ai_addrlen) != 0) {
        ESP_LOGE(TAG, "... socket connect failed errno=%d", errno);
        close(s);
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);
    return s;
}

int socket_write(int s, const char* request)
{
    if (write(s, request, strlen(request)) < 0) {
        ESP_LOGE(TAG, "... socket send failed");
        close(s);
        return -1;
    }
    ESP_LOGI(TAG, "... socket send success");
    return 0;
}

char* socket_read(int s)
{
    // 定义超时时间
    struct timeval tv;
    tv.tv_sec = SOKET_RESPONSE_TIME;  // 设置超时
    tv.tv_usec = 0;
    // 使用lwip_setsockopt()函数设置超时时间
    if(lwip_setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0)
    {
        ESP_LOGE(TAG, "... failed to set socket read timeout");
        return 0;
    }

    char recv_buf[MAX_SINGLE_DATA_LENGTH];
    int i = 0;
    int r = 0;
    int total_size = 0;
    char first_read = 0;
    static char result[RESULT_BUFFER_SIZE];  // 创建全局的静态缓冲区

    do {
    	memset(recv_buf, 0, sizeof(recv_buf));
    	sleep_ms(500);
        r = read(s, recv_buf, MAX_SINGLE_DATA_LENGTH);
        ESP_LOGE(TAG, "recv data:%d\n",r);
        if (r > 0)
        {
            if (total_size + r > RESULT_BUFFER_SIZE - 1)
            {  // 检查是否超出缓冲区大小
                ESP_LOGE(TAG, "Result buffer overflow");
                break;
            }
            memcpy(result + total_size, recv_buf, r);
            total_size += r;
            i += r;
        }
        else if (r < 0)
        {
            break;
        }

//        if(first_read == 0)
//        {
//        	first_read = 1;
//			tv.tv_sec = SOKET_SINGLE_RESPONSE_TIME;  // 设置超时
//			tv.tv_usec = 0;
//			// 使用lwip_setsockopt()函数设置超时时间
//			if(lwip_setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
//				ESP_LOGE(TAG, "... failed to set socket read timeout");
//				break;
//			}
//        }
    } while(r==MAX_SINGLE_DATA_LENGTH);

    result[total_size] = '\0';  // 在结果缓冲区末尾添加字符串结束符

    return result;
}



