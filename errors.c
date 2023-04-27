#include "shell.h"

/**
 * command_error - prints error message when command is not found
 * @PROG_NAME: PROG_NAME of program
 * @command: command not found
 * @error_count: the error counter set in the main file
 *
 */

void command_error(char *PROG_NAME, char *command, int error_count)
{
	write(STDERR_FILENO, PROG_NAME, _strlen(PROG_NAME));
	write(STDERR_FILENO, ": ", 2);
	_putchar(error_count + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 13);

}
