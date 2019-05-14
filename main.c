#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file1;
	char *line = NULL;
	size_t len = 0;
	ssize_t line_size;
	char *token = NULL;

	(void)argc;
	
	file1 = fopen(argv[1], "r");	
	while (line_size >= 0)
	{		
		line_size = getline(&line, &len, file1);
		token = strtok(line, " ");
		if (strcmp(token, "push") == 0)
			new_num = atoi(strtok(NULL, " "));
		compare(token);
	}
	return (0);
}
