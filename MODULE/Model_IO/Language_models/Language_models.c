/*
* @file Language_models.c
* @brief This file is to be used as an interface for the language models
* @date 2021.9.22
*/
#include "Language_models.h"

/*llm param list*/
static typedef struct 
{
    /*Data*/
    uint8_t llm_type;
    void *param;//Store the parameters of the different models

    /*Function*/
    void *run;
}LLM;

/*Definitions of running functions for different big language models*/
static llm_group[MAX_LLM_TYPE] = 
{
    {
        .llm_type = GPT_3_5_TURBO_16K_0613,
        .param = NULL,
        .run = GPT_3_5_TURBO_16K_0613_RUN,
    },
};

static int GPT_3_5_TURBO_16K_0613_RUN(char *input, uint32_t input_len,char *output, uint32_t *output_len)
{
    int ret = 0;
    if (input_len > 0 && input_len < GPT_3_5_TURBO_16K_0613_MAX_LEN)
    {
        return -1;
    }
    //TODO:Here's a wrapper around the http transit api
    ret = COM_SendString(input,input_len);
    if (ret != 0)
    {
        ret = -1;
    }
    else
    {
        /*Waiting for a response*/
        ret = COM_ReceiveString(output,output_len);
    }
    return ret;
}

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