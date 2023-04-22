#include "shell.h"

/**
 * parser - tokenizes string
 * @token:string thats being broken up
 * @argv:used to store an array of strings
 * Return:array of strings that are separated by delimiter in the input string
 */

char **parser(char *token,char **argv)
{
	const char *delim = " \n";
	char *lineptr = NULL;
	char *lineptr_copy = NULL;
	int num_tokens = 0;
	int count;

	delim = " \n";

	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(lineptr_copy, delim);

	for (count = 0; token != NULL; count++)
	{
		argv[count] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[count], token);
		token = strtok(NULL, delim);
	}
	argv[count] = NULL;

	return (argv);
}
