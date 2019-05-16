#ifndef _MONTY_H_
#define _MONTY_H_
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct globalvariables - global struct of variables
 * @num: value of node
 * @line: line from getline
 * @mfile: textfile
 * @stack: pointer to the head of stack_t
 * @filename: file name string
 * @token: token
 *
 * Description: variables to share between functions
 */
typedef struct globalvariables
{
	int num;
	char *line;
	FILE *mfile;
	stack_t *stack;
	char *filename;
	char *token;
} gbv;

extern gbv gv;

void errorHandler(unsigned int errno, unsigned int line_number);
void errorHandler2(unsigned int errno, unsigned int line_number);
char *isNumber(char *value, unsigned int line_number);
void compare(char *token, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

void freeAll(void);
void freeLinkedList(stack_t *stack);
#endif
