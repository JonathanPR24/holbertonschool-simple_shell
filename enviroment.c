#include "shell.h"

/**
 * print_env - print current enviroment for simple shell
 */

extern char **environ;

void print_env()
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
