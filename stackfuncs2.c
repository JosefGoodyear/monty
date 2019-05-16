#include "monty.h"

/**
 * pop - a function that implements the pop opcode (removes the top
 * element of the stack.
 * @stack: a pointer to the head of the stack_t
 * @line_number: the line number of the command
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
		errorHandler2(15, line_number);
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - a function that implements the swap opcode (swaps the top two
 * elements of the stack_t)
 * @stack: a pointer to the head of the stack_t
 * @line_number: the line number of the opcode from the text file
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *temp;

	if (*stack == NULL || (*stack)->next == NULL)
		errorHandler2(16, line_number);
	curr = *stack;
	temp = (*stack)->next;

	if (temp->next != NULL)
		temp->next->prev = curr;
	curr->next = temp->next;
	temp->next = curr;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add - a function that implements the add opcode (adds the top two elements
 * of the stack_t
 * @stack: a pointer to the head of the stack_t
 * @line_number: the line number of the opcode from the text file
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
		errorHandler2(17, line_number);
	(*stack) = (*stack)->next;

	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;

	(void)line_number;
}

/**
 * nop - a function that implements the nop opcode (does nothing)
 * @stack: a pointer to the head of the stack_t
 * @line_number: the line number of the opcode from the text file
 *
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
