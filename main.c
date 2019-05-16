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
	FILE *file1;
	char *line = NULL;
	size_t len = 0;
	char *token = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *value;

	if (argc != 2)
		errorHandler(2, line_number);
	file1 = fopen(argv[1], "r");
	if (!file1)
		errorHandler(3, line_number);
	while (getline(&line, &len, file1) != EOF)
	{
		line_number++;
		token = strtok(line, " \n");
		if (strcmp(token, "push") == 0)
		{
			value = strtok(NULL, " \n");
			if (!value)
				errorHandler(1, line_number);
			gv.num = atoi(isNumber(value, line_number));
		}
		compare(token, &stack, line_number);
	}
	free(line);
	fclose(file1);
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
	
		exit(EXIT_FAILURE);
}









