#include "shell.h"
/**
 * directions - function to get path
 * @cmnd: user input
 * Return: full path to execute
**/
char *directions(char *cmnd)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmnd_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		cmnd_len = strlen(cmnd);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_len = strlen(path_token);

			file_path = malloc(cmnd_len + dir_len + 2);
			if (file_path != NULL)
			{
				strcpy(file_path, path_token);
				strcat(file_path, "/");
				strcat(file_path, cmnd);
				file_path[strlen(file_path)] = '\0';
			}
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(cmnd, &buffer) == 0)
			return (cmnd);
		return (NULL);
	}
	return (NULL);
}
