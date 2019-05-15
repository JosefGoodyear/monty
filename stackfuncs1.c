#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode, *current = *stack;
	
	(void)line_number;
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = gv.num;
	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack)
		current->prev = newNode;
	*stack = newNode;
}


void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

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
