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
    cJSON* json[MAX_JSON_LAYER];
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

        if (json == NULL)
        {
            break;
        }

        key_str = va_arg(args, const char*);
    }
    va_end(args);
    cJSON_Delete(root);
#if 0
    cJSON* choices_array = cJSON_GetObjectItem(json, "choices");
    if (choices_array == NULL || !cJSON_IsArray(choices_array))
    {
    	printf("Invalid JSON format\n");
        cJSON_Delete(root);
    }

    cJSON* choice_object = cJSON_GetArrayItem(choices_array, 0);
    if (choice_object == NULL || !cJSON_IsObject(choice_object))
    {
    	printf("Invalid JSON format\n");
        cJSON_Delete(root);
    }

    cJSON* message_object = cJSON_GetObjectItem(choice_object, "message");
    if (message_object == NULL || !cJSON_IsObject(message_object))
    {
    	printf("Invalid JSON format\n");
        cJSON_Delete(root);
    }

    cJSON* content_string = cJSON_GetObjectItem(message_object, "content");
    if (content_string == NULL || !cJSON_IsString(content_string))
    {
    	printf("Invalid JSON format\n");
        cJSON_Delete(root);
    }

    printf("Content: %s\n", content_string->valuestring);
    while(1);
    cJSON_Delete(root);

    //读取可变参数
    va_list args;
    va_start(args, key);
    const char* key_str = key;

    //通过可变参数逐级获取json对象
    cJSON* json = root;
    printf("json:%s",json->valuestring);

    while (key_str != NULL)
    {
        if (isNumeric(key_str))
        {
            json = cJSON_GetArrayItem(json, atoi(key_str));
            printf("int data");
            printf("json:%d",atoi(key_str));
            //printf("json:%s",json->valuestring);
        }
        else
        {
            json = cJSON_GetObjectItem(json, key_str);
            printf("string data");
            printf("json:%s",key_str);
            //printf("json:%s",json->valuestring);

        }

        if (json == NULL)
        {
            break;
        }

        key_str = va_arg(args, const char*);
    }
    va_end(args);

    //清除cJSON使用的内存
    cJSON_Delete(root);

    //返回结果
    if (json == NULL)
    {
        return NULL;
    }
#endif

    return json[LayerNu]->valuestring;
}
