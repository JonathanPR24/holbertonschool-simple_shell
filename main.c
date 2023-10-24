#include "shell.h"  // Include the "shell.h" header file for function prototypes and declarations.

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
			printf("%s", prompt);  // Print the shell prompt if the program is run in an interactive mode.

		char_read = getline(&lineptr, &n, stdin);  // Read the user's input from the command line.

		if (char_read == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);  // Exit the program if there is an error or end of input.
		}

		save = parser(lineptr, " \n");  // Parse the user input into an array of strings.
		free(lineptr);  // Free the allocated memory for 'lineptr'.

		if (save[0])
		{
			if (check_input(save, env) == 0)
				continue;  // Continue the loop if the input was for the "env" command.
		}
		else
			free(save);  // Free the memory allocated for 'save' if no command was entered.
	}
	free(lineptr);  // Free the allocated memory for 'lineptr'.
	free_array(save);  // Free the memory allocated for 'save' array.

	return (0);  // Return 0 to indicate successful execution of the program.
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
		goodbye(save);  // Handle "exit" command by freeing memory and exiting.
		exec(save);  // Execute the given command.
	}
	else if (strcmp(save[0], "env") == 0)
	{
		free_array(save);  // Free memory used by 'save' array.
		print_env(env);  // Print environment variables.
		return (0);  // Return 0 to indicate that the input was for the "env" command.
	}
	else
	{
		exec(save);  // Execute the given command.
	}
	return (1);  // Return 1 to indicate that the input was for command execution.
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
		free_array(save);  // Free memory used by 'save' array.
		exit(0);  // Exit the program gracefully.
	}
	return (1);  // Return 1 to indicate success.
}