#include "monty.h"

void freeAll(void)
{
	free(gv.line);
	freeLinkedList(gv.stack);
	fclose(gv.mfile);
}

void freeLinkedList(stack_t *stack)
{
	stack_t *nextNode;

	while (stack)
	{
		nextNode = stack->next;
		free(stack);
		stack = nextNode;
	}
}
