#ifndef LANGUAGE_MODELS_H
#define LANGUAGE_MODELS_H

#include "../../../MCAL/MCAL_CFG.h"


#define MAX_LLM_TYPE 10
/*llm_type*/
#define GPT_3_5_TURBO_16K_0613 0

/*llm token mapping*/
#define GPT_3_5_TURBO_16K_0613_MAX_TOKEN 16385

LLM *llm_init(uint8_t llm_type, void *param);

#endif /* LANGUAGE_MODELS_H */
