#ifndef LLM_OPENAI_H
#define LLM_OPENAI_H

#include "../../../MCAL/MCAL_CFG.h"
#include "LLM_Base.h"

//LLM类型列表
//LLM type list
#define GPT_3_5_TURBO_16K_0613 0

#define GPT_3_5_TURBO_16K_0613_MAX_TOKEN 16*1024


//大型语言模型初始化
//Large language model initialization
extern LLM *Openai_init(const char *llm_type,float temperature,uint16_t max_token,const char *api_key,const char *api_base);

#endif /* LLM_OPENAI_H */
