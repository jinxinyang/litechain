#ifndef MCAL_CFG_H
#define MCAL_CFG_H


/*Chip Platform Definition*/
#define X86 0
#define STM32F10X 1
#define ESP32 2
#define PLATFORM_CONFIG X86

#if PLATFORM_CONFIG == X86
#include "x86/MCAL_Core_CFG.h"
#include "x86/MCAL_CAN_CFG.h"
#include "x86/MCAL_UART_CFG.h"
#include "x86/MCAL_EEPROM_CFG.h"
#include "x86/MCAL_Flash_CFG.h"
#include "x86/MCAL_Etherent_CFG.h"
#elif PLATFORM_CONFIG == STM32F10X

#elif PLATFORM_CONFIG == ESP32

#else
#error "Please define the platform you are using"
#endif

#endif/*MCAL_CFG_H*/