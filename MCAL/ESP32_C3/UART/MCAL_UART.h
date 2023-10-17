#ifndef MCAL_UART_H
#define MCAL_UART_H

#include "../../MCAL_CFG.h"

#define RX_BUF_SIZE 256
#define TXD_PIN 17
#define RXD_PIN 16


extern int UART_Init(int baud);
extern int UART_SendString(char *str,int len);
extern int UART_ReceiveString(char *str, int max_len);


#endif /* MCAL_UART_H */
