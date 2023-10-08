#ifndef OUTPUT_PARSERS_H
#define OUTPUT_PARSERS_H

#include "cJSON.h"

#define MAX_JSON_LAYER 20
#define MAX_JSON_COUNT 10

//对齐字节数
#define ALIGN_SIZE 4

extern char * OutputParserJson(char* input, const char* key, ...);

#endif /* OUTPUT_PARSERS_H */
