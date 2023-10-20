#include "shell.h"  // Include the "shell.h" header file for function prototypes and declarations.

/**
 * print_env - print current environment for a simple shell
 * @environ: env variable
 **/
void print_env(char **environ)
{
	char **env = environ;  // Initialize a pointer 'env' to the provided 'environ' variable.

	while (*env)  // Iterate through the environment variables until a NULL pointer is encountered.
	{
		printf("%s\n", *env);  // Print the current environment variable.
		env++;  // Move to the next environment variable.
	}
}