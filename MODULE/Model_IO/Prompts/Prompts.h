#ifndef PROMPTS_H
#define PROMPTS_H

#define MAX_PROMPT_LEN 16*1024
#define MAX_TEMPLATES 10
#define MAX_ARGS 10

// 结构体定义，用于保存模板信息
typedef struct {
	const char* tempStr;//模板地址 //Template address
    int temp_number; // 模板编号 //Template number
    int numArgs; // 参数个数 //Number of parameters
    int argStart[MAX_ARGS]; // 参数起始位置 //Parameter start position
    int argEnd[MAX_ARGS]; // 参数结束位置 //Parameter end position
}TemplateInfo;

extern TemplateInfo prompt_init(const char* templateStr);
extern char* prompt_format(TemplateInfo *temp, char* args[]);

#endif /* PROMPTS_H */
