/*
    * MCAL_UART.c
    *  esp32的串口通信封装
    *  
    *  Created on: 2023.9.22
*/

#include "MCAL_UART.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "string.h"




int UART_Init(int baud);
int UART_SendString(char *str,int len);
int UART_ReceiveString(char *str, int max_len);

//串口初始化
int UART_Init(int baud)
{
    const uart_config_t uart_config = {
        .baud_rate = baud,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_1, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    return 0;
}
//串口发送字符串
int UART_SendString(char *str,int len)
{
    const int txBytes = uart_write_bytes(UART_NUM_1, str, len);
    return txBytes;
}

//串口接收字符串
int UART_ReceiveString(char *str, int max_len)
{
    uint8_t* data = (uint8_t*) malloc(max_len+1);
    const int rxBytes = uart_read_bytes(UART_NUM_1, data, max_len, 1000 / portTICK_PERIOD_MS);
    if (rxBytes > 0) {
        data[rxBytes] = 0;
        memcpy(str,data,rxBytes);
    }
    free(data);
    return rxBytes;
}
