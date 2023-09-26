/* HTTP GET Example using plain POSIX sockets

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

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
#include "esp32_c3_http.h"

static const char *TAG = "example";

void app_main(void)
{

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_ERROR_CHECK(example_connect());


    char* url = "api1.t-chat.cn";
    char* web_path = "/v1/chat/completions";
    char* headers = "Content-Type: application/json\r\n"
                    "Authorization: Bearer sk-q6iEheCNMGxHlhQd04702713Ba7143A28997D1C2F9A32a27\r\n";

    char* data = "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"system\", \"content\": "
                     "\"You are a helpful assistant.\"}, {\"role\": \"user\", \"content\": \"Who is the president of the United States in 2016?\"}]}";
    // 开始计时
    uint64_t start_time = esp_timer_get_time();

    ESP_LOGI(TAG, "... done reading from socket. Last read return=%s.", esp32_c3_http_post(url,web_path,headers,data));
    // 结束计时
    uint64_t end_time = esp_timer_get_time();
    // 计算运行时间（以微秒为单位）
    uint64_t execution_time = end_time - start_time;
    ESP_LOGI(TAG, "Execution time: %lld microseconds", execution_time);
}
