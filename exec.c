#include "shell.h"

int exec(char **save)
{
	char *cmnd = NULL;
	char *real_cmnd = NULL;
	pid_t child_pid;
	int status;

		cmnd = save[0];
		real_cmnd = directions(cmnd);
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
		return (1);

}
