#include <stdio.h>
#include "curl/curl.h"

// 用于接收 HTTP 响应的回调函数
size_t write_callback(void* content, size_t size, size_t nmemb, void* userptr) {
    // 在这里对接收到的响应进行处理，例如打印到控制台
    printf("%.*s", (int)(size * nmemb), (char*)content);
    return size * nmemb;
}

int main() {
    CURL* curl = curl_easy_init();
    if (curl) {
        const char* url = "https://www.baidu.com/";

        // 设置要访问的 URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // 设置 SSL 验证，默认情况下会验证证书
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        // 设置响应回调函数
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        // 执行 HTTP 请求
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Failed to send HTTP request: %s\n", curl_easy_strerror(res));
        }

        // 清理资源
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize libcurl\n");
    }

    return 0;
}
