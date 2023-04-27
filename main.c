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
	int should_exit = 0;

	while (!should_exit)
	{
		save = NULL;
		n = 0;
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);

		char_read = getline(&lineptr, &n, stdin);

		if (char_read == -1)
			exit(EXIT_SUCCESS);

		save = parser(lineptr, " \n");
		free(lineptr);

		if (save[0])
		{
			if (strcmp(save[0], "exit") == 0)
				exec_exit();
			else if (strcmp(save[0], "env") == 0)
				print_env();
			else
				exec(save);
		}

		free_array(save);
	}

	free(lineptr);
	return (0);
}
