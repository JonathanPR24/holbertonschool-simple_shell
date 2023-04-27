#include "shell.h"

/**
 * print_env - print current enviroment for simple shell
 */
void print_env(void)
{
	extern char **environ;
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
