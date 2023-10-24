#include "shell.h"  // Include the "shell.h" header file for function prototypes and declarations.

/**
 * parser - Tokenizes a string into an array of substrings using a delimiter
 *
 * @lineptr: Pointer to the input string to be tokenized
 *
 * @delim: Delimiter character used to split the input string
 *
 * Return: Pointer to an array of strings, with each element containing a
 * substring of the input string separated by the delimiter character.
 *
 * The last element of the array is NULL.
 */
char **parser(char *lineptr, char *delim)
{
	char **cmnds = NULL;  // Declare an array of strings to store the parsed substrings.
	char *cmnd = NULL;    // Declare a temporary string to hold each token.
	int i = 0;            // Initialize an index variable to track the current position in the array.

	cmnds = malloc(sizeof(char *) * 10);  // Allocate memory for an initial array of strings.

	if (cmnds == NULL)
	{
		return (NULL);  // Return NULL if memory allocation fails.
	}

	cmnd = strtok(lineptr, delim);  // Tokenize the input string using the specified delimiter.

	while (cmnd)
	{
		cmnds[i] = malloc(sizeof(char) * strlen(cmnd) + 1);  // Allocate memory for each token.
		if (cmnds[i] == NULL)
		{
			return (NULL);  // Return NULL if memory allocation fails for a token.
		}
		strcpy(cmnds[i], cmnd);  // Copy the token into the array.
		i++;  // Move to the next position in the array.
		cmnd = strtok(NULL, delim);  // Get the next token.
	}
	cmnds[i] = NULL;  // Set the last element of the array to NULL to terminate it.

	free(cmnd);  // Free the memory allocated for the temporary token variable.

	return (cmnds);  // Return the array of parsed substrings.
}