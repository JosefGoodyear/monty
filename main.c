#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file1;
	char *line = NULL;
	size_t len = 0;
	ssize_t line_size;
	char *token = NULL;
	char *global = NULL;

	file1 = fopen(argv[1], "r");	
	line_size = getline(&line, &len, file1);
	token = strtok(line, " ");
	if (strcmp(token, "push") == 0)
		global = strtok(NULL, " ");
	printf("global = %s\n", global);
	while (line_size >= 0)
	{	
		printf("%s\n", token);
		line_size = getline(&line, &len, file1);
		token = strtok(line, " ");
		if (strcmp(token, "push") == 0)
			global = strtok(NULL, " ");
		printf("global = %s\n", global);
	}

	(void)argc;
	return (0);
}



