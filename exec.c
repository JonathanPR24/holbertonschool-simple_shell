#include "shell.h"

/**
 * exec - execute a shell command
 *
 * @save: pointer to an array of null-terminated strings
 * representing the shell command and its arguments
 *
 * Return: integer value of 1 upon successful completion of the function
 */
int exec(char **save)
{
	char *real_cmnd = NULL;
	pid_t child_pid;
	int status;

	real_cmnd = directions(save[0]);
	child_pid = fork();
	if (child_pid == -1)
		perror("Error:");
	else if (child_pid == 0)
	{
		if (execve(real_cmnd, save, NULL) == -1)
			perror("Error:");
	}
	else
		wait(&status);

	if (strncmp(save[0], "/bin", 4))
		free_array(save);
	else
		free(save);

	free(real_cmnd);
	return (1);
}
