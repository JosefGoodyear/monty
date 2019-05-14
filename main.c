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
	
	(void)argc;
	file1 = fopen(argv[1], "r");	
	do {		
		line_number++;
		line_size = getline(&line, &len, file1);
		token = strtok(line, " ");
		if (strcmp(token, "push") == 0)
			new_num = atoi(strtok(NULL, " "));
		(*compare(token))(stack, line_number);
	} while (line_size >= 0);
	return (0);
}
