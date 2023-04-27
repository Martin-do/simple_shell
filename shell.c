#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * @env: An array of environment variable strings
 *
 * Return: Always 0.
 */
int main(__attribute__((unused))int argc, char **argv, char **env)
{
	char *input = NULL;
	char **commands = NULL;
	char **path_array = NULL;
	size_t no_of_bytes = 0;
	ssize_t read_bytes = 0;
	char *PROG_NAME = argv[0];
	char *prompt = "";
	int errorcount = 0;
	int exitcode = 0;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		errorcount++;
		write(STDOUT_FILENO, prompt, 1);
		read_bytes = getline(&input, &no_of_bytes, stdin);
		if (read_bytes == -1)
			exit(exitcode);
		if (input[strlen(input) - 1] == '\n')
		{
			if (check_exit(input) != 0)
				continue;
			if (blank_check(input) == 1)
				continue;
			if (check_env(input) == 1)
			{
				print_env(env);
				continue;
			}
			path_array = get_path_array(env);
			commands = command_string_array(input, path_array, PROG_NAME, errorcount);
			if (commands != NULL)
				exec_command(commands, env, PROG_NAME);

		}
	}
	return (0);
}
