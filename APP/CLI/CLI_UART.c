/*
 * CLI_UART.c
 *  通过外部AT指令对大语言模型进行调用,
 *  本文件实现对CLI_UART的统一封装
 *  Created on: 2023年10月13日
 *      Author: jinxinyang
 */

#include <stdio.h>
#include <string.h>
#include "../litechain/MODULE/MODULE_CFG.h"

#define MAX_INPUT_LEN 256
#define MAX_RESPONSE_LEN 1024*16

// 定义AT指令的前缀和分隔符
#define AT_PREFIX "AT+"
#define AT_SEPARATOR ","

// 定义AT指令的响应前缀和分隔符
#define AT_RESPONSE_PREFIX "OK,"
#define AT_RESPONSE_SEPARATOR ","

// 定义AT指令的错误响应前缀和分隔符
#define AT_ERROR_PREFIX "ERROR,"
#define AT_ERROR_SEPARATOR ","

// 定义AT指令的最大长度
#define AT_MAX_LEN 64

// 定义AT指令的缓冲区
char at_buf[AT_MAX_LEN];

// 定义输入和响应的缓冲区
char input_buf[MAX_INPUT_LEN];
char response_buf[MAX_RESPONSE_LEN];

// 定义Openai模型的指针
LLM *openai_llm;

// 初始化Openai模型
static void openai_init(const char *llm_type, float temperature, uint16_t max_token, const char *api_key, const char *api_base)
{
    openai_llm = Openai_init(llm_type, temperature, max_token, api_key, api_base);
}

// 运行Openai模型
static char *openai_run(char *api_type, char *input)
{
    return openai_llm->run(api_type, input);
}

// 解析AT指令
static void parse_at_command(char *at_command)
{
    // 检查AT指令前缀
    if (strncmp(at_command, AT_PREFIX, strlen(AT_PREFIX)) != 0)
    {
        printf("%s%s\n", AT_ERROR_PREFIX, "Invalid command.");
        return;
    }

    // 解析AT指令
    char *token = strtok(at_command + strlen(AT_PREFIX), AT_SEPARATOR);
    if (strcmp(token, "OPENAI_INIT") == 0)
    {
        // 初始化Openai模型
        char *llm_type = strtok(NULL, AT_SEPARATOR);
        float temperature = atof(strtok(NULL, AT_SEPARATOR));
        uint16_t max_token = atoi(strtok(NULL, AT_SEPARATOR));
        char *api_key = strtok(NULL, AT_SEPARATOR);
        char *api_base = strtok(NULL, AT_SEPARATOR);
        openai_init(llm_type, temperature, max_token, api_key, api_base);
        printf("%s%s\n", AT_RESPONSE_PREFIX, "Openai model initialized.");
    }
    else if (strcmp(token, "OPENAI_RUN") == 0)
    {
        // 运行Openai模型
        char *api_type = strtok(NULL, AT_SEPARATOR);
        char *input = strtok(NULL, AT_SEPARATOR);
        char *response = openai_run(api_type, input);
        if (response != NULL)
        {
            snprintf(response_buf, MAX_RESPONSE_LEN,"%s%s%s\n",AT_RESPONSE_PREFIX,AT_RESPONSE_SEPARATOR, response);
            UART_SendString(response_buf, strlen(response_buf));
        }
        else
        {
            printf("%s%s\n", AT_ERROR_PREFIX, "Failed to generate response.");
        }
    }
    else
    {
        printf("%s%s\n", AT_ERROR_PREFIX, "Invalid command.");
    }
}

// AT指令解析任务
void CLI_UART_PARSE_TASK()
{
    int input_len = 0;
    while (1)
    {
        // 读取输入
        char *input_ptr = input_buf + input_len;
        int remaining_len = MAX_INPUT_LEN - input_len;
        int received_len = UART_ReceiveString(input_ptr, remaining_len);
        if (received_len <= 0)
        {
            continue;
        }
        input_len += received_len;

        // 检查是否接收到完整的指令
        if (input_buf[input_len - 1] != '\n')
        {
            // 指令未接收完整，继续等待
            continue;
        }

        // 去掉换行符
        input_buf[input_len - 1] = 0;

        // 解析AT指令
        parse_at_command(input_buf);

        // 重置输入缓冲区
        input_len = 0;
        memset(input_buf, 0, MAX_INPUT_LEN);
    }
}
