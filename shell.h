#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern int exitcode;
extern int errorcount;

int _putchar(char c);

int no_of_paths(char *path_arr_env);
char **get_path_array(char **env);
char *find_path(char **env, char *command);
void print_env(char **env);

void command_error(char *PROG_NAME, char *command, int error_count);

int count_args(char *input);
char **command_string_array(char *input, char **path_array, char *PROG_NAME, int errorcount);

int check_env(char *user_input);
int check_exit(char *input);

int _strlen(const char *string);
char *_strdup(char *str);
int same_len_cmp(char *a, char *b, int cnt);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

void exec_command(char **commands, char **env, char *PROG_NAME);


#endif /* SHELL_H */
