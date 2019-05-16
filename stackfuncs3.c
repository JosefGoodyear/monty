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
	diff = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = diff;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
* mul - multiply the top element and the second element
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
/**
* divide - divide the second element from the top element
* @stack: the stack
* @line_number: line number
*/
void divide(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
		errorHandler(7, line_number);
	if ((*stack)->n == 0)
		errorHandler(14, line_number);
	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
* mod -  the second elemt by the top element
* @stack: the stack
* @line_number: line number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (*stack == NULL || (*stack)->next == NULL)
		errorHandler(7, line_number);
	if ((*stack)->n == 0)
		errorHandler(14, line_number);
	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
