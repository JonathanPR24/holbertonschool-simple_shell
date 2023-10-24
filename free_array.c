#include "shell.h"  // Include the "shell.h" header file for function prototypes and declarations.

/**
 * free_array - deallocate memory used by an array of strings
 *
 * @token: pointer to an array of null-terminated strings
 *
 * Return: none
 */
void free_array(char **token)
{
	int i = 0;  // Initialize a counter variable 'i'.

	while (token[i])  // Iterate through the array until a NULL pointer is encountered.
	{
		free(token[i]);  // Free the memory allocated for the string at index 'i'.
		i++;  // Move to the next string in the array.
	}

	free(token);  // Free the memory allocated for the array of strings itself.
}

These comments explain that the free_array function is used to deallocate the memory used by an array of strings. It iterates through the array of strings, frees each string's memory, and then frees the memory of the array itself.
