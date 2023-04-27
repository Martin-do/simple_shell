#include "shell.h"

/**
* _putchar - prints a single character to stdout
* @c: The character to print
*
* Return: 1 if successful, -1 otherwise
*/
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
