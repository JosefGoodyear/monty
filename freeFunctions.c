#include "monty.h"

/**
 * freeAll - function that frees the global getline, stack_t
 * and file if it exists
 *
 * Return: void
 */

void freeAll(void)
{

	free(gv.line);
	freeLinkedList(gv.stack);
	if (gv.mfile)
		fclose(gv.mfile);

}

/**
 * freeLinkedList - a function that frees the linkedlist
 * @stack: a pointer to the head of stack_t
 *
 * Return: void
 */

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
