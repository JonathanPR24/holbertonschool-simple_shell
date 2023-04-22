#include "shell.h"

int main(__attribute__((unused)) int ac ,__attribute__((unused))char **argv)
{
	char *prompt = "$";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t char_read;
	
	while(1)
		{
			printf("%s", prompt);
			char_read = getline(&lineptr, &n, stdin);
			
			if (char_read == -1)
			{
				printf("Exit\n");
				return(-1);
			}
			parser(lineptr, argv);			
			printf("%s\n", lineptr);
			
			free(lineptr);
		}
		
		return (0);
}
