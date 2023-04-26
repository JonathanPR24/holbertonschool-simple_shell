#include "shell.h"


/**
 * main - Entry Point
 * @ac: variable not used
 * @argv: variable not used
 * Return: 0 on SUCCESS
 */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv)
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t char_read;
	char **save = NULL;

	while (1)
	{
		save = NULL;
		lineptr = NULL;
		n = 0;
		if (isatty(0))
			printf("%s", prompt);
		char_read = getline(&lineptr, &n, stdin);

		if (char_read == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		save = parser(lineptr, " \n");
		free(lineptr);

		if (save[0])
		{
			if (strcmp(save[0], "env") == 0)
			{
				print_env();
			}
		else
		{
			exec(save);
		}

		}
		else
		{
			free(save);
		}
	}

	free(lineptr);
	free_array(save);
	return (0);
}
