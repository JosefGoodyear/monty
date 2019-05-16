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
	unsigned int line_number = 0;
	char *value;

	gv.stack = NULL;
	gv.mfile = NULL;
	gv.line = NULL;
	gv.token = NULL;
	if (argc != 2)
		errorHandler(2, line_number);
	gv.filename = argv[1];
	gv.mfile = fopen(argv[1], "r");
	if (!gv.mfile)
		errorHandler(3, line_number);
	while (getline(&gv.line, &len, gv.mfile) != EOF)
	{
		line_number++;
		gv.token = strtok(gv.line, " \n");
		if (!gv.token)
			continue;
		if (strcmp(gv.token, "push") == 0)
		{
			value = strtok(NULL, " \n");
			if (!value)
				errorHandler(1, line_number);
			gv.num = atoi(isNumber(value, line_number));
		}
		compare(gv.token, &gv.stack, line_number);
		free(gv.line);
		gv.line = NULL;
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

