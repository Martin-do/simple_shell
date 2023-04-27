#include "shell.h"

/**
 * exec_command - executes commands by first forking a child process
 * then executing in that child while the parent process waits
 * @commands: array of strings
 * @env: environment variables
 * @PROG_NAME: name of program
 */

void exec_command(char **commands, char **env, char *PROG_NAME)
{
	pid_t pid;
	int status, exec_check;

	status = 0;
	pid = fork();

	if (pid == -1)
	{
		perror(PROG_NAME);
		_exit(1);
	}

	else if (pid == 0)
	{

		exec_check = execve(commands[0], commands, env);

		if (exec_check < 0)
		{
			perror(commands[0]);
			_exit(126);
		}

		_exit(0);

	}
	wait(&status);
}
