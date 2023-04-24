#include "shell.h"

void exec(char **argv)
{
	char *cmnd = NULL;
	char *real_cmnd = NULL;

	if (argv)
	{
		cmnd = argv[0];
		real_cmnd = directions(cmnd);
		if (execve(real_cmnd, argv, NULL) == -1)
		perror("Error:");
	}

}
