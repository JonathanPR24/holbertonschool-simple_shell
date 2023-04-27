#include "shell.h"

/**
 * main - Entry Point
 * @ac: variable not used
 * @argv: variable not used
 * Return: 0 on SUCCESS
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t char_read;
	char **save = NULL;

	while (1)
	{
		save = NULL;
		n = 0;
		lineptr = NULL;
		
		if (isatty(0))
			printf("%s", prompt);

		if (getline(&lineptr, &n, stdin) == EOF)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(lineptr, "exit") == 1)
		{
			free(lineptr);
			exit(0);
			
		}
		else if (strcmpt(linepre, "env") == 1)
		{
			print_env();
			free(lineptr);
		}
		else
		{
			save = parser(lineptr, " \n");
			excution(save);
			free(lineptr);
		}
		
	}
	return (0);
}
