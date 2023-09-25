#ifndef HTTP_H_
#define HTTP_H_

#include "../../MCAL/MCAL_CFG.h"



typedef struct {
    const char* host;
    const char* path;
    const char* method;
    const char* headers;
    const char* body;
}HttpRequest;

int http_post(const HttpRequest* request, char** response);

#endif /* HTTP_H_ */
