/*
 * Plugins_http.h
 *
 *  Created on: 2023年9月27日
 *      Author: jinxinyang
 */

#ifndef PLUGINS_PLUGINS_HTTP_H_
#define PLUGINS_PLUGINS_HTTP_H_

#define MAX_HTTP_POST_LEN 16*1024

extern char* HTTP_Post(const char* url,const char* web_path,const char* headers,const char* data);

#endif /* PLUGINS_PLUGINS_HTTP_H_ */
