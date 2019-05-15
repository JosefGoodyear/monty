#include "monty.h"

void compare(char *token, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t func_list[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; func_list[i].opcode != NULL; i++)
		if(strcmp(token, func_list[i].opcode) == 0)
		{
			func_list[i].f(stack, line_number);
		}
}


