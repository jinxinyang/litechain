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
TemplateInfo prompt_init(const char* templateStr);
char* prompt_format(TemplateInfo *temp, char* args[]);

/******************************************************************************************
* Function: prompt_init
* Description:  根据模板字符串初始化对应的占位符，并返回 TemplateInfo 结构体实例。
*               Initializes a template with corresponding placeholders and returns a TemplateInfo structure instance.
* Parameters:
*    - templateStr: 一个指向模板字符串的指针 
*               A pointer to the template string.
* Return Value:
*    - TemplateInfo: 
*               初始化后的 TemplateInfo 结构体实例。
*               The initialized TemplateInfo structure instance.
*******************************************************************************************/TemplateInfo prompt_init(const char* templateStr)
{
    // 定义静态变量，记录模板数量
    // Define static variables to record the number of templates
	static int init_number = 0;
    // 定义 TemplateInfo 结构体实例
    // Define TemplateInfo structure instance
    TemplateInfo templateInfo;

    // 初始化参数个数为0
    // Initialize the number of parameters to 0
    templateInfo.numArgs = 0;

    // 遍历模板字符串
    // Traverse the template string
    int i = 0;
    //循环整个字符串
    // Loop through the entire string
    while (templateStr[i] != '\0')
    {
        if (templateStr[i] == '{')
        {
            // 找到占位符的起始位置
            // Find the starting position of the placeholder
            int start = i;

            // 查找占位符的结束位置
            // Find the end position of the placeholder
            int end = start + 1;
            //循环找到占位符的结束位置
            // Loop to find the end position of the placeholder
            while (templateStr[end] != '}' && templateStr[end] != '\0')
            {
                end++;
            }
            // 判断占位符格式是否正确
            // Determine if the placeholder format is correct
            if (templateStr[end] == '}')
            {
                // 记录参数的起始和结束位置
                // Record the start and end positions of the parameters
                templateInfo.argStart[templateInfo.numArgs] = start + 1;
                templateInfo.argEnd[templateInfo.numArgs] = end + 1;
                templateInfo.numArgs++;

                // 更新索引位置
                // Update index position
                i = end; 
            }
            else
            {
                // 处理无效的占位符格式
                // Handle invalid placeholder format
            }
        }
        i++;
    }

    // 判断模板数量是否超出上限
    // Determine if the number of templates exceeds the upper limit
    if(init_number < MAX_TEMPLATES)
    {
    	templateInfo.tempStr = templateStr;
    	templateInfo.temp_number = init_number;
    	init_number++;
    }
    else
    {
    	// 超出模板数量上限
        // Exceed the upper limit of the number of templates
    }

    // 返回 TemplateInfo 结构体实例
    // Return TemplateInfo structure instance
    return templateInfo;
}

/******************************************************************************************
 * Function: prompt_format
 * Description:  根据模板和参数格式化提示词
 *              Format the prompt according to the template and parameters
 * Parameters:
 *   - temp: 一个指向模板的指针
 *          A pointer to the template.
 *  - args: 一个指向参数的指针数组
 *         An array of pointers to the parameters.
 * Return Value:
 *  - char*: 格式化后的提示词
 *         The formatted prompt.
 * *****************************************************************************************/
char* prompt_format(TemplateInfo *temp, char* args[]) {
    static char result[MAX_PROMPT_LEN];
    int resultIndex = 0;
    int tempIndex = 0;
    for (int i = 0; i < temp->numArgs; i++) {
        // 将模板中的静态部分复制到结果字符串中
        // Copy the static part of the template to the result string
        int staticLength = (i == 0) ? temp->argStart[i] - 1 : temp->argStart[i] - temp->argEnd[i - 1] - 1;

        strncpy(result + resultIndex, temp->tempStr + tempIndex, staticLength);
        resultIndex += staticLength;

        // 获取占位符的长度
        // Get the length of the placeholder
        int placeholderLength = strlen(args[i]);

        // 将参数复制到占位符位置
        // Copy the parameter to the placeholder position
        strncpy(result + resultIndex, args[i], placeholderLength);
        resultIndex += placeholderLength;
        tempIndex = temp->argEnd[i];
    }

    // 将模板中的最后一部分复制到结果字符串中
    // Copy the last part of the template to the result string
    int lastStaticLength = strlen(temp->tempStr) - temp->argEnd[temp->numArgs - 1];
    strncpy(result + resultIndex, temp->tempStr + tempIndex, lastStaticLength);

    return result;
}