#ifndef MCAL_COM_H
#define MCAL_COM_H

#include "../CAN/MCAL_CAN.h"
#include "../UART/MCAL_UART.h"
#include "../Ethernet/MCAL_Ethernet.h"


typedef enum {
    UART,
    CAN,
    Ethernet
} com_type;

int COM_Init(com_type type, unsigned int baud);
int COM_SendString(unsigned char *str, unsigned int len);
int COM_ReceiveString(char *str, unsigned int *len);

#endif /* MCAL_UART_H */
