#ifndef PROMPTS_H
#define PROMPTS_H

#define MAX_PROMPT_LEN 16*1024

extern char* prompt_format(char* buffer, const char* format, ...);

#endif /* PROMPTS_H */
