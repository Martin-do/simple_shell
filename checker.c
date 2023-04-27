#include "shell.h"

/**
 * check_env - checks if command is env
 * @user_input: string to compare to 'env'
 *
 * Return: 1 if string is equal to 'env', otherwise 0
 */

int check_env(char *user_input)
{
	int i = 0;
	char *command = "env";

	if (_strlen(user_input) != 4)
		return (0);

	while (command[i] != '\0')
	{
		if (command[i] != user_input[i])
			return (0);
		i++;
	}
	return (1);
}
/**
 * check_blank - checks if the user did not enter anything
 * @input: blank user input
 * Return: 1 if user_input is equal to '\n', 0 otherwise
*/
int blank_check(char *input)
{
	if (input[0] == '\n')
		return (1);

	return (0);
}

/**
 * check_exit - checks if the user inputs the command exit
 * to exit the shell
 * @user_input: the list of string input from user
 * Return: returns 0 if not exit command and -1 if status not valid
*/
int check_exit(char *user_input)
{
	int i, j, length, size, status;
	char *number;
	char *check = "exit";

	j = 0;
	length = _strlen(user_input);
	size = length - 5;
	status = 0;
	for (i = 0; i < 4; i++)
	{
		if (check[i] != user_input[i])
			return (0);
	}
	if (user_input[4] != '\n' && user_input[4] != ' ')
		return (0);

	if (length > 5)
	{
		number = malloc(sizeof(char) * size);
		for (i = 5; i < length - 1; i++)
		{
			if (user_input[i] >= '0' && user_input[i] <= '9')
			{
				number[j] = user_input[i];
				j++;
			}
			else
			{
				free(number);
				return (-1);
			}
		}
		number[j] = '\0';
		status = atoi(number);
		free(number);
	}
	free(user_input);
	exit(status);
}
