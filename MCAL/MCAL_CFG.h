#ifndef MCAL_CFG_H
#define MCAL_CFG_H


/*Chip Platform Definition*/
#define X86 0
#define STM32F10X 1
#define ESP32_C3 2
#define CALTERAH 3//只是测试串口用的//Just for testing the serial port
#define PLATFORM_CONFIG ESP32_C3

#define SOKET_RESPONSE_TIME 20
#define SOKET_SINGLE_RESPONSE_TIME 1


#if PLATFORM_CONFIG == X86
#include "X86/MCAL_Core.h"
#include "X86/MCAL_CAN.h"
#include "X86/MCAL_UART.h"
#include "X86/MCAL_EEPROM.h"
#include "X86/MCAL_Flash.h"
#include "X86/MCAL_Etherent.h"
#elif PLATFORM_CONFIG == STM32F10X

#elif PLATFORM_CONFIG == ESP32_C3
#include "ESP32_C3/Core/MCAL_Core.h"
#include "ESP32_C3/EEPROM/MCAL_EEPROM.h"
#include "ESP32_C3/Flash/MCAL_Flash.h"
#include "ESP32_C3/UART/MCAL_UART.h"
#include "ESP32_C3/CAN/MCAL_CAN.h"
#include "ESP32_C3/Ethernet/MCAL_Ethernet.h"
#include "ESP32_C3/WIFI/MCAL_Wifi.h"
#elif PLATFORM_CONFIG == CALTERAH
#include "CALTERAH/Core/MCAL_Core.h"
#include "CALTERAH/EEPROM/MCAL_EEPROM.h"
#include "CALTERAH/Flash/MCAL_Flash.h"
#include "CALTERAH/UART/MCAL_UART.h"
#include "CALTERAH/CAN/MCAL_CAN.h"
#include "CALTERAH/Ethernet/MCAL_Ethernet.h"
#else
#error "Please define the platform you are using"
#endif

#endif/*MCAL_CFG_H*/
