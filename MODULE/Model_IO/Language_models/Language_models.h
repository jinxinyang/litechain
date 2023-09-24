#ifndef LANGUAGE_MODELS_H
#define LANGUAGE_MODELS_H

#include "../../../MCAL/MCAL_CFG.h"

//最多支持的LLM种类
//Maximum supported LLM species
#define MAX_LLM_TYPE 10

//LLM类型列表
//LLM type list
#define GPT_3_5_TURBO_16K_0613 0

//GPT_3_5_TURBO_16K_0613模型的最大输入长度
//Maximum input length of GPT_3_5_TURBO_16K_0613 model
#define GPT_3_5_TURBO_16K_0613_MAX_TOKEN 16385

//大型语言模型初始化
//Large language model initialization
LLM *llm_init(uint8_t llm_type, void *param);

#endif /* LANGUAGE_MODELS_H */
