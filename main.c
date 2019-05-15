#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file1;
	char *line = NULL;
	size_t len = 0;
	char *token = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *value;
	extern gbv gv;
	gv.num = 0;	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file1 = fopen(argv[1], "r");
	if (!file1)	
	{
		fprintf(stderr, "Error: can't open file %s", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file1) != EOF)
	{		
		line_number++;
		token = strtok(line, " \n");
		if (strcmp(token, "push") == 0)
		{
			value = strtok(NULL, " \n");
			if (!value)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			gv.num = atoi(isNumber(value, line_number));
		}
		compare(token, &stack, line_number);
	}
	free(line);
	fclose(file1);
	return (0);
}

char *isNumber(char *value, unsigned int line_number)
{
	unsigned int i = 0;
	
	if ((value[i] < '0' || value[i] > '9') && value[i] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);		
	}
	i++;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);		
		}
		i++;	
	}
	return (value);
}
