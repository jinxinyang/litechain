/*
* @file Language_models.c
* @brief 该文件将用作语言模型的接口
         This file is to be used as an interface for the language models
* @date 2021.9.22
*/
#include "Language_models.h"

//大型语言模型的句柄结构体
//Handle structure of large language model
static typedef struct 
{
    uint8_t llm_type;//llm类型//llm type
    void *param;//参数//parameter
    void *run;//运行函数//running function
}LLM;

//大型语言模型的句柄数组
//Handle array of large language model
static llm_group[MAX_LLM_TYPE] = 
{
    {
        .llm_type = GPT_3_5_TURBO_16K_0613,
        .param = NULL,
        .run = GPT_3_5_TURBO_16K_0613_RUN,
    },
};
/******************************************************************************************
 * Function: GPT_3_5_TURBO_16K_0613_RUN
 * Description:  该函数将用作GPT_3_5_TURBO_16K_0613模型的运行函数
 *              This function will be used as the running function of the GPT_3_5_TURBO_16K_0613 model
 * Parameters:
 *   - input: 一个指向输入字符串的指针
 *             A pointer to the input string
 *  - input_len: 输入字符串的长度
 *            The length of the input string
 * - output: 一个指向输出字符串的指针
 *           A pointer to the output string
 * - output_len: 输出字符串的长度
 *             The length of the output string
 * Return Value:
 *  - int:
 *         0: 成功
 *        -1: 失败
 *        0: Success
 *       -1: Failure
 * *******************************************************************************************/
static int GPT_3_5_TURBO_16K_0613_RUN(char *input, uint32_t input_len,char *output, uint32_t *output_len)
{
    int ret = 0;
    //检查输入长度
    //Check the input length
    if (input_len > 0 && input_len < GPT_3_5_TURBO_16K_0613_MAX_LEN)
    {
        return -1;
    }
    //TODO:Here's a wrapper around the http transit api

    //发送请求
    //Send request
    ret = COM_SendString(input,input_len);
    if (ret != 0)
    {
        ret = -1;
    }
    else
    {
        //接收响应
        //Receive response
        ret = COM_ReceiveString(output,output_len);
    }
    return ret;
}
/******************************************************************************************
 * Function: llm_init
 * Description:  该函数将用作语言模型的初始化函数
 *              This function will be used as the initialization function of the language model
 * Parameters:
 *   - llm_type: 一个指向输入字符串的指针
 *             A pointer to the input string
 *  - param: 输入字符串的长度
 *            The length of the input string
 * Return Value:
 *  - LLM*: 一个指向LLM结构体实例的指针
 *         A pointer to the LLM structure instance
 * *******************************************************************************************/
LLM *llm_init(uint8_t llm_type, void *param)
{
    LLM *llm = NULL;
    if(llm_type == GPT_3_5_TURBO_16K_0613)
    {
        return &llm_group[llm_type];
    }
    else
    {
        return NULL;
    }
}