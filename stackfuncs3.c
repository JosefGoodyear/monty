#include "monty.h"
/**
* sub - subtract the top element from the second element
* @stack: the stack
* @line_number: line number
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
		errorHandler(6, line_number);
	(*stack) = (*stack)->next;
	diff = (*stack)->prev->n - (*stack)->n;
	(*stack)->n = diff;
       	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
* sub - subtract the top element from the second element
* @stack: the stack
* @line_number: line number
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
		errorHandler(7, line_number);
	(*stack) = (*stack)->next;
	product = (*stack)->prev->n * (*stack)->n;
	(*stack)->n = product;
       	free((*stack)->prev);
	(*stack)->prev = NULL;
}
