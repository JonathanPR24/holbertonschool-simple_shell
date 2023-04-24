#include "shell.h"

/**
 * parser - tokenizes string
 * @token:string thats being broken up
 * @argv:used to store an array of strings
 * Return:array of strings that are separated by delimiter in the input string
 */

char **parser(char *lineptr, char *delim)
{
	char **cmnds = NULL;
	char *cmnd = NULL;
	int i = 0;

	cmnds = malloc(sizeof(char *) * 10);
	cmnd = strtok(lineptr, delim);
	while (cmnd)
	{
		cmnds[i] = malloc(sizeof(char) * strlen(cmnd) + 1);
		strcpy(cmnds[i], cmnd);
		i++;
		cmnd = NULL;
		cmnd = strtok(NULL, delim);
	}
	cmnds[i] = NULL;
	free(cmnd);
	return (cmnds);
}
