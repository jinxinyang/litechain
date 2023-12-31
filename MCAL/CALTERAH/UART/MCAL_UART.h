#ifndef MCAL_UART_H
#define MCAL_UART_H

#include "../../MCAL_CFG.h"

extern int UART_Init(int baud);
extern int UART_SendString(char *str,int len);
extern int UART_ReceiveString(char *str);

#endif /* MCAL_UART_H */
