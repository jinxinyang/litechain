#ifndef MCAL_UART_H
#define MCAL_UART_H

int UART_Init(unsigned int baud);
int UART_SendString(unsigned char *str,unsigned int len);
int UART_ReceiveString(unsigned char *str,unsigned int *len);

#endif /* MCAL_UART_H */
