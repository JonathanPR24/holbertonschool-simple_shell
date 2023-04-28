#include "shell.h"

/**
 * free_array - deallocate memory used by an array of strings
 *
 * @token: pointer to an array of null-terminated strings
 *
 * Return: none
 */
void free_array(char **token)
{
	int i = 0;

	while (token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
}
