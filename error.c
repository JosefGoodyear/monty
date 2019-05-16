#include "monty.h"

/**
   * errorHandler - handle all errors and call freeEverything
   * * @errno: error number
   * * @line_number: the line number of the opcode in the text file
   */

void errorHandler(unsigned int errno, unsigned int line_number)
{
	switch (errno)
	{
			case 1:
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				break;
			case 2:
				fprintf(stderr, "USAGE: monty file\n");
				break;
			case 3:
				fprintf(stderr, "Error: can't open file %s\n", gv.filename);
				break;
			case 4:
				fprintf(stderr, "Error: malloc failed\n");
				break;
			case 5:
				fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
				break;
			case 6:
				fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
				break;
			case 7:
				fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
				break;
			case 8:
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, gv.token);
				break;
			case 9:
				fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
				break;
			case 10:
				fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
				break;
			case 11:
				fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
				break;
		}
		freeAll();
		exit(EXIT_FAILURE);
}

/**
 * errorHandler2 - handle all errors and call freeeverything
 * @errno: errorno
 * @line_number: the line number of the opcode
 *
 */

void errorHandler2(unsigned int errno, unsigned int line_number)
{
	switch (errno)
	{

			case 12:
				fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
				break;

			case 13:
				fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
				break;
			case 14:
				fprintf(stderr, "L%d: division by zero\n", line_number);
				break;
			case 15:
				fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
				break;
			case 16:
				fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
				break;
			case 17:
				fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
				break;
	}
	freeAll();
	exit(EXIT_FAILURE);
}
