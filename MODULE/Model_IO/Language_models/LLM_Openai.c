/*
* @file  LLM_Openai.c
* @brief Openai的接口实现
         Interface implementation for Openai   
* @date 2021.9.25
*/
#include "LLM_Base.h"
#include "LLM_Openai.h"

static LLM Openai_llm;


char* Openai_Template(char* data)
{
    
}

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
static int Openai_run(char *input,char *output, uint32_t *output_len)
{
    int ret = 0;
    //检查输入长度
    //Check the input length
    if (input_len > 0 && input_len < GPT_3_5_TURBO_16K_0613_MAX_TOKEN)
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
 * Function: Openai_init
 * Description:  该函数将用作Openai模型的初始化函数
 *              This function will be used as the initialization function of the Openai model
 * Parameters:
 *   - llm_type: llm类型
 *               llm type
 *  - temperature: 温度//随机性
 *                 temperature
 * - api_key: api密钥
 *            api key
 * - api_base: api基地址
 *             api base
 * Return Value:
 *  - LLM *: 成功
 *           Success
 *  - NULL: 失败
 *          Failure
 * *******************************************************************************************/
LLM *Openai_init(uint8_t *llm_type,float temperature,uint16_t max_token,uint8_t *api_key,uint8_t *api_base)
{
    //检测参数长度是否超标
    //Check if the parameter length is exceeded
    if(strlen(api_key)>MAX_API_KEY_LEN||strlen(api_base)>MAX_API_BASE_LEN)
    {
        return NULL;
    }

    Openai_llm->run = Openai_run;
    Openai_llm->config.llm_type = llm_type;
    Openai_llm->config.temperature = temperature;
    Openai_llm->config.maxTokens = max_token;

    return &Openai_llm;
}