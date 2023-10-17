#ifndef LLM_CHATGML_H
#define LLM_CHATGML_H

#include "../../../MCAL/MCAL_CFG.h"
#include "LLM_Base.h"

//LLM类型列表
//LLM type list
#define CHATGML2_6B 0

#define CHATGML2_6B_MAX_TOKEN 16*1024


//大型语言模型初始化
//Large language model initialization
extern LLM *Chatgml_init(const char *llm_type,float temperature,uint16_t max_token,const char *api_key,const char *api_base);

#endif /* LLM_CHATGML_H */
