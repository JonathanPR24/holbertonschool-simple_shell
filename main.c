#include "shell.h"

int main(int ac __attribute__((unused)),  char **argv __attribute__((unused)), char **env)
{
	char *prompt = "$ ", *lineptr = NULL, **save = NULL;
	size_t n = 0;
	int i;

	while (1)
	{
		save = NULL;
		lineptr = NULL;
		n = 0;
		if (isatty(0))
			printf("%s", prompt);

		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		save = parser(lineptr, " \n");
		free(lineptr);
		if (save[0])
		{
			if (strcmp(save[0], "exit") == 0)
			{
				goodbye(save);
				exec(save);
			}
			if (strcmp(save[0], "env") == 0)
			{
				free_array(save);
				print_env();
				continue;
			}
		}
		else
			free(save);
	}
	free(lineptr);
	free_array(save);
	return (0);
}

int goodbye(char **save)
{
	if (strcmp(save[0], "exit") == 0)
	{
		free_array(save);
		exit(0);
	}
	return (1);
}
