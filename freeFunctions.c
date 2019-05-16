#include "monty.h"

void freeAll(void)
{
	free(gv.line);
	free(gv.mfile);
}
