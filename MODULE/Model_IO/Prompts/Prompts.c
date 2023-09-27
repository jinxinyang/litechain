/*
* @file Prompts.c
* @brief 该文件将用作提示词的接口
         This file is to be used as an interface for the prompts
* @date 2021.9.24
*/

#include "Prompts.h"
#include <string.h>
#include <stdio.h>

// 函数声明
// Function declaration

char* prompt_format(const char* format, ...);

// 定义 prompt_format 函数
char* prompt_format(const char* format, ...)
{
	static char buffer[MAX_PROMPT_LEN];
    va_list args;             // 声明一个 va_list 类型的变量 args

    va_start(args, format);   // 初始化 va_list 变量 args

    // 使用 vsnprintf 将格式化数据写入缓冲区
    vsnprintf(buffer, MAX_PROMPT_LEN, format, args);

    va_end(args);             // 结束可变参数的获取

    return buffer;            // 返回生成的字符串
}
