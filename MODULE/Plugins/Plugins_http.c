/*
 * Plugins_http.c
 *
 *  Created on: 2023年9月27日
 *      Author: jinxinyang
 */
#include <string.h>
#include <stdio.h>
#include "Plugins_http.h"
#include "../../MCAL/MCAL_CFG.h"

char http_buff[MAX_HTTP_POST_LEN];
char* HTTP_Post(const char* url,const char* web_path,const char* port,const char* headers,const char* data);

char* HTTP_Post(const char* url,const char* web_path,const char* port,const char* headers,const char* data)
{
	int s;
    sprintf(http_buff,
            "POST %s HTTP/1.1\r\n"
            "Host: %s:%s\r\n"
            "%s"
            "Content-Length: %zu\r\n"
            "\r\n"
            "%s",
			web_path,url,port,headers, strlen(data), data);

    s=socket_init(url);
    if(s<0)
    {
        return 0;
    }

    if(socket_write(s,http_buff)<0)
    {
        return 0;
    }

    return socket_read(s);
}

