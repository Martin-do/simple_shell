#include "shell.h"


/**
 * count_args - counts the number of arguments
 * @input: the string to be counted
 * Return: returns the number of arguments
*/
int count_args(char *input)
{
	int i = 0, num = 0;

	for (; *(input + i) != '\0' && *(input + i) != '\n'; i++)
	{
		if (*(input + i) == ' ' && *(input + (i + 1)) != '\n')
		{
			num++;
		}
	}
	num += 1;
	return (num);
}



/**
 * command_string_array - parses input to create an array of strings
 * @input: string to parse
 * @path_array: array of directories in PATH
 * @PROG_NAME: name of program
 *
 * Return: an array of arguments
 */
char **command_string_array(char *input, char **path_array, char *PROG_NAME, int errorcount)
{
	int i = 0, j = 0, k = 0, arg_count = 0;
	char *i_str, **commands, *command_path = NULL;

	i_str = malloc(sizeof(char) * 30);
	if (i_str == NULL)
		return (NULL);
	arg_count = count_args(input);
	commands = malloc(sizeof(char *) * (arg_count + 1));
	if (commands == NULL)
		return (NULL);
	for (i = 0; input[i] != '\0' && input[i] != '\n'; i++)
	{
		for (j = 0; input[i + j] != ' ' && input[i + j] != '\n'; j++)
			i_str[j] = input[i + j];
		i += j;
		if (k < arg_count)
			commands[k] = i_str;
		i_str = calloc(20, 20);
		k++;
	}
	command_path = find_path(path_array, commands[0]);
	if (command_path == NULL)
	{
		/*free_array(path_array);*/
		command_error(PROG_NAME, commands[0], errorcount);
		free(commands);
		return (NULL);
	}
	else if (_strcmp("no_access", command_path) == 0)
	{
		free(commands);
		/*free_array(path_array);*/
		return (NULL);
	}
	commands[0] = _strdup(command_path);
	commands[k] = NULL;
	return (commands);
}


