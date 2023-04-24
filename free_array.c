#include "shell.h"

void free_array(char **token)
{
	int i = 0;

	while (token)
	{
		free(token[i]);
		i++;
	}
	free(token);
}
