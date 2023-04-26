#include "shell.h"

/**
 * no_of_paths - counts the number of paths
 * @path_arr_env: the lists of paths
 * Return: returns the number of paths in the lists
*/
int no_of_paths(char *path_arr_env)
{
	int count = 0, path = 0, num = 0;

	for (; *(path_arr_env + count) != '\0'; count++)
	{
		if (*(path_arr_env + count) == '/')
		{
			for (; *(path_arr_env + (count + path)) != ':'
					&& *(path_arr_env + (count + path)) != '\0'; path++)
				continue;
			num++;
			count += path;
			path = 0;
		}
	}
	return (num);
}

/**
 * get_path_array - gets the individual paths from the lists
 * @env: the list of environments variables
 * Return: returns the array of paths
*/
char **get_path_array(char **env)
{
	int i = 0, j = 0, count = 0, count2 = 0, p_index = 0, k = 0, path_match = 0;
	char *path_arr_env, *p, **path_array;
	int path_count = 0;

	while (env[i] != NULL)
	{
		path_match = strncmp(env[i], "PATH", 4);
		if (path_match == 0)
			path_arr_env = strdup(env[i]);
		i++;
	}
	p = malloc(sizeof(char) * 30);
	if (p == NULL)
		return (NULL);
	path_count = no_of_paths(path_arr_env);
	path_array = malloc(sizeof(char *) * (path_count + 1));
	if (path_array == NULL)
		return (NULL);
	while (path_arr_env[j] != '\0')
	{
		if ((*(path_arr_env + count) == '/'))
		{
			for (ip_index = 0, count2 = 0; *(path_arr_env + (count + count2)) != ':'
					&& *(path_arr_env + (count + count2)) != '\0'; count2++)
			{
				p[p_index] = *(path_arr_env + (count + count2));
				p_index++;
			}
			if (k < path_count)
				path_array[k] = p;
			k++;
			p = calloc(20, 20);
			count += (p_index - 1);
			count++;
		}
		j++;
		count++;
	}
	return (path_array);
}

/**
 * find_path - find the PATH of a command
 * @path_array: array of directories in PATH
 * @command: command to find path for
 *
 * Return: path of command, NULL if it fails
 */
char *find_path(char **path_array, char *command)
{
	char *path;
	int i = 0, path_count = 0, j = 0;
	int dir_length, command_len, tot_length, ok_f = 0, ok_x = 0;

	if (path_array == NULL)
		return (NULL);
	for (i = 0; path_array[i] != NULL; i++)
	{
		dir_length = _strlen(path_array[i]);
		command_len = _strlen(command);
		tot_length = dir_length + command_len;
		path = malloc(sizeof(char) * (tot_length + 2));
		if (path == NULL)
			return (NULL);
		j = 0;
		while (j < dir_length)
		{
			path[j] = path_array[i][j];
			j++;
		}
		path[j] = '/';
		j = 0;
		while (j < command_len)
		{
			path[dir_length + j + 1] = command[j];
			j++;
		}
		path[tot_length + 1] = '\0';
		ok_f = access(path, F_OK);
		ok_x = access(path, X_OK);
		if (ok_f == 0)
		{
			if (ok_x == 0)
				return (path);
			free(path);
			return ("no_access");
		}
		free(path);
	}
	return (0);
}
