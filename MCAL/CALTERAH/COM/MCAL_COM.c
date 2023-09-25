/*
* @file  MCAL_COM.c
* @brief 用于通信的接口
         An interface for communication   
* @date 2021.9.22
*/
#include "MCAL_COM.h"

int COM_Init(com_type type, unsigned int baud)
{
    if (type == UART)
    {
        UART_Init(baud);
    }
    else if (type == CAN)
    {

    }
    else if (type == Ethernet)
    {

    }
    else
    {
        return -1;
    }
    return 0;
}

int COM_SendString(unsigned char *str, unsigned int len)
{
    int ret = 0;
    UART_SendString(str, len);
    return ret;
}

int COM_ReceiveString(char *str, unsigned int *len)
{
    int ret = 0;
    ret = UART_ReceiveString(str, len);
    return ret;
}

