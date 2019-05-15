#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);

	(void)line_number;
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *temp;
	
	curr = *stack;
	temp = (*stack)->next;

	if (temp->next != NULL)
		temp->next->prev = curr;
	curr->next = temp->next;
	temp->next = curr;
	temp->prev = NULL;
	*stack = temp;

	(void)line_number;
}

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	(*stack) = (*stack)->next;

	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
       	free((*stack)->prev);
	(*stack)->prev = NULL;
	
	(void)line_number;
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("nop\n");
}
