#include "monty.h"

void (*compare(char *token))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t func_list[] = {
		{"push", push_stack},
		{"pint", print_stack},
		{"pop", remove_top},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"nop", nope},
		{NULL, NULL}
	};

	for (i = 0; func_list[i].opcode; i++)
		if(strcmp(token, func_list[i].opcode) == 0)
			return (func_list[i].f);

	return (NULL);
}

void push_stack(stack_t **stack, unsigned int line_number)
{
	
}



