#include "monty.h"

gbv gv;

/**
* main - run the monty compiler
* @argc: argument count
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char **argv)
{
	size_t len = 0;
	char *token = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *value;

	gv.mfile = NULL;
	gv.line = NULL;
	if (argc != 2)
		errorHandler(2, line_number);
	gv.mfile = fopen(argv[1], "r");
	if (!gv.mfile)
		errorHandler(3, line_number);
	while (getline(&gv.line, &len, gv.mfile) != EOF)
	{
		line_number++;
		token = strtok(gv.line, " \n");
		if (strcmp(token, "push") == 0)
		{
			value = strtok(NULL, " \n");
			if (!value)
				errorHandler(1, line_number);
			gv.num = atoi(isNumber(value, line_number));
		}
		compare(token, &stack, line_number);
	}
	freeAll();
	return (0);
}
/**
* isNumber - check if a string is numerical
* @value: string to check
* @line_number: line of code
*
* Return: string, if numerical
*/
char *isNumber(char *value, unsigned int line_number)
{
	unsigned int i = 0;

	if ((value[i] < '0' || value[i] > '9') && value[i] != '-')
		errorHandler(1, line_number);
	i++;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
			errorHandler(1, line_number);
		i++;
	}
	return (value);
}
/**
* errorHandler - handle all errors and call freeEverything
* @errno: error number
*/

void errorHandler(unsigned int errno, unsigned int line_number)
{
	switch(errno)
	{
		case 1: fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		case 2: fprintf(stderr, "USAGE: monty file\n");
			break;
		case 3: fprintf(stderr, "Error: can't open file %s", "test");
			break;
		case 4: fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5: fprintf( stderr, "L%d: can't pint, stack empty\n", line_number);
			break;
	}
		freeAll();	
		exit(EXIT_FAILURE);
}
