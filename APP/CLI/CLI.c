/*
 * CLI.c
 *  通过外部接口对大语言模型进行调用,
 *  UART走AT指令
 *   CAN走UDS协议
 *  其他接口走自定义协议
 *
 *  本文件实现对CLI_UART,CLI_CAN,CLI_CUSTOM的统一封装
 *  实现上层APP的统一调用
 *  Created on: 2023年10月13日
 *      Author: jinxinyang
 */

#include "CLI.h"
#include "CLI_UART.h"


void CLI_PARSE_TASK(CLI_COMM_TYPE type)
{
    switch (type)
    {
    case CLI_COMM_UART:
        CLI_UART_PARSE_TASK();
        break;
    case CLI_COMM_CAN:
        //CLI_CAN_PARSE_TASK();
        break;
    case CLI_COMM_CUSTOM:
        //CLI_CUSTOM_PARSE_TASK();
        break;
    default:
        break;
    }
}
