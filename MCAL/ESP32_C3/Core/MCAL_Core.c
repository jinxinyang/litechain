/*
    * MCAL_Core.c
    *
    *  Created on: 2023.10.4
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "MCAL_Core.h"

void sleep_ms(int ms)
{
    TickType_t ticks = pdMS_TO_TICKS(ms);
    vTaskDelay(ticks);
}

