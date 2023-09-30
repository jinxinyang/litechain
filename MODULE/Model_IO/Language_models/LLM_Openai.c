/*
* @file  LLM_Openai.c
* @brief Openai的接口实现
         Interface implementation for Openai   
* @date 2021.9.25
*/
#include "LLM_Base.h"
#include "LLM_Openai.h"
#include "../../Plugins/Plugins_http.h"
#include <stdio.h>

static LLM Openai_llm;
// 定义足够大的空间给headers
static char headers[256];
// 定义足够大的空间给data
static char data[GPT_3_5_TURBO_16K_0613_MAX_TOKEN];

LLM *Openai_init(const char *llm_type,float temperature,uint16_t max_token,const char *api_key,const char *api_base);

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
static char *Openai_run(char *api_type,char *input)
{
    //检查输入长度
    int input_len = strlen(input);
    //Check the input length
    if (input_len < 0 || input_len > GPT_3_5_TURBO_16K_0613_MAX_TOKEN)
    {
        return 0;
    }
    //获取配置,这里可以实现多个实例自动获取
    llm_config cfg = Openai_llm.config;



    // 拼接headers字符串
    snprintf(headers, sizeof(headers), "Content-Type: application/json\r\nAuthorization: Bearer %s\r\n", cfg.api_key);

    // 拼接data字符串
    snprintf(data, sizeof(data), "{\"model\": \"%s\", \"messages\": [{\"role\": \"system\", \"content\": "
             "\"You are a helpful assistant.\"}, {\"role\": \"user\", \"content\": \"%s\"}]}", cfg.llm_type, input);

    //发送请求
    //Send request
    char * output = HTTP_Post(cfg.api_base,api_type,headers,data);

    return output;
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
 *  - 0: 失败
 *          Failure
 * *******************************************************************************************/
LLM *Openai_init(const char *llm_type,float temperature,uint16_t max_token,const char *api_key,const char *api_base)
{

    //检测参数长度是否超标
    //Check if the parameter length is exceeded
	int type_len = strlen(llm_type);
	int key_len = strlen(api_key);
	int base_len = strlen(api_base);
    if((type_len>MAX_LLM_NAME_LEN)||(key_len>MAX_API_KEY_LEN||base_len>MAX_API_BASE_LEN))
    {
        return 0;
    }

    Openai_llm.run = Openai_run;
    memcpy(Openai_llm.config.llm_type, llm_type, type_len);
    memcpy(Openai_llm.config.api_key, api_key, key_len);
    memcpy(Openai_llm.config.api_base, api_base, base_len);
    Openai_llm.config.temperature=temperature;
    Openai_llm.config.maxTokens=max_token;
    return &Openai_llm;
}
