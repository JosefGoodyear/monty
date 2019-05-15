#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file1;
	char *line = NULL;
	size_t len = 0;
	ssize_t line_size;
	char *token = NULL;
	stack_t **stack = NULL;
	unsigned int line_number = 0;
	extern gbv gv;
	
	(void)argc;
	file1 = fopen(argv[1], "r");	
	while (line_size >= 0)
	{		
		line_number++;
		line_size = getline(&line, &len, file1);
		token = strtok(line, " ");
		if (strcmp(token, "push") == 0)
			gv.num = atoi(strtok(NULL, " "));
		(*compare(token))(stack, line_number);
	}
	return (0);
}

