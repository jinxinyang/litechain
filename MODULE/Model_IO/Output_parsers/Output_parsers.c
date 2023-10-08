/*
 * Output_parsers.c
 *
 *  Created on: 2023年10月7日
 *      Author: jinxinyang
 */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "Output_parsers.h"
#include "cJSON.h"

static cJSON* json[MAX_JSON_LAYER];
static char valuestring_buff[MAX_JSON_VALUE_LEN];

static bool isNumeric(const char* str)
{
    if (str == NULL || *str == '\0')
    {
        return false;
    }

    while (*str != '\0')
    {
    	if (!isdigit((int)*str))
        {
            return false;
        }
        str++;
    }

    return true;
}


static char* get_json(char* str)
{
    char *start, *end;

    // 寻找开始和结束的指针
    start = strchr(str, '{');
    end = strrchr(str, '}');

    // 如果没有找到，返回NULL
    if (!start || !end)
    {
        return NULL;
    }

    end[1] = '\0';
    return start;
}

char* OutputParserJson(char* input,const char* key,...)
{
    //第一次调用需要进行初始化
    static bool is_init = false;
    if (!is_init)
    {
        cJSON_InitHooks(NULL);
        is_init = true;
    }

	if(input==NULL)
	{
		return 0;
	}

	char* json_start = get_json(input);
	if(json_start==NULL)
	{
		return 0;
	}

    //读取可变参数
    va_list args;
    va_start(args, key);
    const char* key_str = key;

    cJSON* root = cJSON_Parse(json_start);
    if (root == NULL)
    {
    	printf("Failed to parse JSON\n");
    }

    int LayerNu = 0;
    json[LayerNu] = root;

    while (key_str != NULL)
    {
        if (isNumeric(key_str))
        {
        	json[(LayerNu+1)] = cJSON_GetArrayItem(json[LayerNu], atoi(key_str));
        	LayerNu++;
            printf("int data\n");
            printf("json:%d\n",atoi(key_str));
        }
        else
        {
        	json[(LayerNu+1)] = cJSON_GetObjectItem(json[LayerNu], key_str);
        	LayerNu++;
            printf("string data\n");
            printf("json:%s\n",key_str);
        }

        if (json[LayerNu] == NULL)
        {
            break;
        }

        key_str = va_arg(args, const char*);
    }
    va_end(args);

    strcpy(valuestring_buff, json[LayerNu]->valuestring);

    cJSON_Delete(root);
    return valuestring_buff;
}
