#ifndef LLM_BASE_H
#define LLM_BASE_H

//最大llm名长度
//Maximum llm name length
#define MAX_LLM_NAME_LEN 32

//最大api密钥长度
//Maximum api key length
#define MAX_API_KEY_LEN 100

//最大api基地址长度
//Maximum api base length
#define MAX_API_BASE_LEN 64


//实现LLM的基本运行函数
//Implement the basic running function of LLM
typedef int (* llm_run)(char *input, uint32_t input_len,char *output, uint32_t *output_len);


//LL的配置结构体,应当是包含所有可能的参数
//LL configuration structure, should contain all possible parameters
typedef struct
{
    uint8_t llm_type[MAX_LLM_NAME_LEN];//llm类型//llm type
    
    float temperature;//温度//temperature

    uint16_t maxTokens;//最大token数//maximum token number

    uint8_t api_key[MAX_API_KEY_LEN];//api密钥//api key

    uint8_t api_base[MAX_API_BASE_LEN];//api基地址//api base

}llm_config;//llm配置//llm configuration


//大型语言模型的句柄结构体
//Handle structure of large language model
typedef struct 
{
    llm_config config;//llm配置//llm configuration
    llm_run run;//运行函数//running function
}LLM;


#endif/*LLM_BASE_H*/