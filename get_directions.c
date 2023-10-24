#include "shell.h"  // Include the "shell.h" header file for function prototypes and declarations.

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

	path = getenv("PATH");  // Get the value of the PATH environment variable.

	if (path)
	{
		path_copy = strdup(path);  // Create a copy of the PATH variable.
		cmnd_len = strlen(cmnd);  // Get the length of the command.
		path_token = strtok(path_copy, ":");  // Tokenize the PATH variable using ':' as a delimiter.
		while (path_token != NULL)
		{
			dir_len = strlen(path_token);  // Get the length of the current directory in PATH.

			// Allocate memory for the full path to the command.
			file_path = malloc(cmnd_len + dir_len + 2);

			if (file_path != NULL)
			{
				strcpy(file_path, path_token);  // Copy the directory path to the file_path.
				strcat(file_path, "/");  // Add a '/' to separate the directory and the command.
				strcat(file_path, cmnd);  // Append the command name.
				file_path[strlen(file_path)] = '\0';  // Ensure the string is null-terminated.
			}

			if (stat(file_path, &buffer) == 0)  // Check if the file exists (executable).
			{
				free(path_copy);
				return (file_path);  // Return the full path to the executable.
			}
			else
			{
				free(file_path);  // Free the allocated memory for file_path.
				path_token = strtok(NULL, ":");  // Move to the next directory in PATH.
			}
		}

		free(path_copy);  // Free the copy of the PATH variable.

		if (stat(cmnd, &buffer) == 0)  // Check if the command is executable in the current directory.
			return (cmnd);  // Return the command itself if it's executable in the current directory.

		return (NULL);  // Return NULL if the command is not found in PATH.
	}

	return (NULL);  // Return NULL if the PATH environment variable is not set.
}