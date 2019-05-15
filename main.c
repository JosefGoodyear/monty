#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file1;
	char *line = NULL;
	size_t len = 0;
	char *token = NULL;
	stack_t **stack = NULL;
	unsigned int line_number = 0;
	extern gbv gv;
	(void)argc;

	file1 = fopen(argv[1], "r");	
	while (getline(&line, &len, file1) != EOF)
	{		
		line_number++;
		token = strtok(line, " \n");
		if (strcmp(token, "push") == 0)
		{
			gv.num = atoi(strtok(NULL, " \n"));
		}
		compare(token, stack, line_number);
	}
	return (0);
}

