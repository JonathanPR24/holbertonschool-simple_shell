#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

char **parser(char *token, char *delim);
int exec(char **argv);
char *directions(char *cmnd);
void free_array(char **token);
void print_env(char **environ);
int goodbye(char **save);
int check_input(char **save, char **env);

#endif
