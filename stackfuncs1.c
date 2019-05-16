#include "monty.h"
/**
* push - push num to top of the stack
* @stack: pointer to the head
* @line_number: line of m file
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode, *current = *stack;

	(void)line_number;
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		errorHandler(4, line_number);
	newNode->n = gv.num;
	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack)
		current->prev = newNode;
	*stack = newNode;
}

/**
* pint - print the first int
* @stack: pointer to the head
* @line_number: line of m file
*/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
		errorHandler(5, line_number);
	printf("%d\n", temp->n);
}

/**
* pall - print all of the values in the stack
* @stack: pointer to the head
* @line_number: line of m file
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
