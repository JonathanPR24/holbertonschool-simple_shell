#include "shell.h"

/**
 * main - Entry Point
 * @ac: variable not used
 * @argv: variable not used
 * Return: 0 on SUCCESS
 * @env: env variable
 */

int main(int ac, char **argv __attribute__((unused)), char **env)
{
	char *prompt = "$ ", *lineptr = NULL, **save = NULL;
	ssize_t char_read;
	size_t n = 0;
	(void) ac;

	while (1)
	{
		save = NULL;
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
			if (check_input(save, env) == 0)
				continue;
		}
		else
			free(save);
	}
	free(lineptr);
	free_array(save);
	return (0);
}

/**
 * check_input - validate the user input
 * @save: user input
 * @env: env variable
 * Return: 0 for env input or 1 on execution
 */

int check_input(char **save, char **env)
{
	int i = 0;

	if (strcmp(save[0], "exit") == 0)
	{
		goodbye(save);
		exec(save);
	}
	else if (strcmp(save[0], "env") == 0)
	{
		free_array(save);
		print_env(env);
		return (0);
	}
	else
	{
		exec(save);
	}
	return (1);
}

/**
 * goodbye - free everything once done
 * @save: user input
 * Return: 1 on success
 */
int goodbye(char **save)
{
	if (strcmp(save[0], "exit") == 0)
	{
		free_array(save);
		exit(0);
	}
	return (1);
}
