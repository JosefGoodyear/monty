#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file1;
	char *line = NULL;
	size_t len = 0;
	ssize_t line_size;
	file1 = fopen(argv[1], "r");	
	line_size = getline(&line, &len, file1);
	while (line_size >= 0)
	{
		printf("%s", line);
		line_size = getline(&line, &len, file1);
	}
	return (0);
}
