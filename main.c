#include "shell.h"

/**
 * main - Entry Point for the custom shell
 * @ac: The argument count (not used)
 * @argv: The array of arguments (not used)
 * @env: The environment variables
 * Return: Always returns 0
 */
int main(int ac, char **argv __attribute__((unused)), char **env)
{
	char *prompt = "$ ", *lineptr = NULL, **save = NULL;
	ssize_t char_read;
	size_t n = 0;
	(void) ac; // The argument count is not used

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
 * check_input - Validates and processes user input
 * @save: The user input parsed into an array
 * @env: The environment variables
 * Return: 0 if the input is for "env," 1 for execution
 */
int check_input(char **save, char **env)
{
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
 * goodbye - Frees allocated memory when "exit" command is called
 * @save: The user input parsed into an array
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

