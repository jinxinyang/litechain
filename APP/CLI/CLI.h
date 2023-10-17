/*
 * CLI.h
 *
 *  Created on: 2023年10月13日
 *      Author: jinxinyang
 */

#ifndef APP_CLI_CLI_H_
#define APP_CLI_CLI_H_


//CLI通信类型
typedef enum
{
    //UART通信
    CLI_COMM_UART = 0x00,   
    //CAN通信
    CLI_COMM_CAN = 0x01,   
    //自定义通信
    CLI_COMM_CUSTOM = 0x02,
} CLI_COMM_TYPE;

extern void CLI_PARSE_TASK(CLI_COMM_TYPE type);

#endif /* APP_CLI_CLI_H_ */
