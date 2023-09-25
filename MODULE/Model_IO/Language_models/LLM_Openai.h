#ifndef LLM_OPENAI_H
#define LLM_OPENAI_H

#include "../../../MCAL/MCAL_CFG.h"

//LLM类型列表
//LLM type list
#define GPT_3_5_TURBO_16K_0613 0

//大型语言模型初始化
//Large language model initialization
LLM *Openai_init(uint8_t llm_type,float temperature,uint32_t maxTokens,uint8_t *api_key,uint8_t *api_base);

#endif /* LLM_OPENAI_H */
