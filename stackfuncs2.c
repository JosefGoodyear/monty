#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	temp = (*stack)->next;

	if (temp->next != NULL)
		temp->next->prev = curr;
	curr->next = temp->next;
	temp->next = curr;
	temp->prev = NULL;
	*stack = temp;
}

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

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
}
