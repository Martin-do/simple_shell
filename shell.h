#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

extern int exitcode;
extern int errorcount;

int _putchar(char c);

int no_of_paths(char *path_arr_env);
char **get_path_array(char **env);
char *find_path(char **env, char *command);
void command_error(char *NAME, char *command, int error_count);
int count_args(char *user_input);
char **command_string_array(char *input, char **path_array, char *PROG_NAME);
int check_env(char *user_input);
int _strlen(const char *string);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);



#endif /* SHELL_H */
