#include "shell.h"

/**
 * print_env - print current enviroment for simple shell
 * @environ: env variable
 **/

void print_env(char **environ)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
