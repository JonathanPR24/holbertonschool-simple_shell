#include "shell.h"  // Include the "shell.h" header file for function prototypes and declarations.

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
	char *real_cmnd = NULL;  // Declare a pointer to store the real command path.
	pid_t child_pid;         // Declare a variable to store the child process ID.
	int status;              // Declare a variable to store the status of the child process.

	real_cmnd = directions(save[0]);  // Get the full path of the command using the 'directions' function.

	child_pid = fork();  // Create a child process using 'fork'.

	if (child_pid == -1)
		perror("Error:");  // If fork fails, display an error message.
	else if (child_pid == 0)
	{
		// Inside the child process:
		if (execve(real_cmnd, save, NULL) == -1)
			perror("Error:");  // If 'execve' fails, display an error message.
	}
	else
		wait(&status);  // In the parent process, wait for the child process to finish.

	if (strncmp(save[0], "/bin", 4))
		free_array(save);  // If the command is not in "/bin" directory, free the 'save' array.
	else
		free(save);  // Otherwise, free 'save' array (assumed to be in "/bin").

	free(real_cmnd);  // Free the 'real_cmnd' string.

	return (1);  // Return 1 to indicate successful completion of the function.
}