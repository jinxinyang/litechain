/*
 * MCAL_WIFI.h
 *
 *  Created on: 2023年9月27日
 *      Author: jinxinyang
 */

#ifndef MCAL_ESP32_C3_WIFI_MCAL_WIFI_H_
#define MCAL_ESP32_C3_WIFI_MCAL_WIFI_H_

#include "../../MCAL_CFG.h"

#define MAX_SINGLE_DATA_LENGTH 64


extern int socket_init(const char* url);
extern char* socket_read(int s);
extern int socket_write(int s, const char* request);


#endif /* MCAL_ESP32_C3_WIFI_MCAL_WIFI_H_ */
