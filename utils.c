#include "shell.h"
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>

/**
 * display_prompt - Prints the shell prompt to the standard output
 * This function displays a simple "$ " prompt on the terminal,
 * inviting the user to type a command.
 */

void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * free_args - frees args
 * @args:array of characters
 */

void free_args(char **args)
{
	if (args != NULL)
		free(args);
}

/**
 * _get_path - Gets the value of PATH from environ
 * Return: pointer to PATH value or NULL
 */

char *_get_path(void)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}
/**
 * which_path - Searches for a command in
 * the directories listed in PATH
 * @command: The command name (e.g., "ls") to search for
 * Return: A pointer to the full path string if found (must be freed),
 *         or NULL if the command is not found.
 */

char *which_path(char *command)
{
	char *path_env = _get_path();
	char *path_copy = NULL, *dir, *full_path;
	struct stat st;

	if (!path_env || !command)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * get_command_path -　Resolves the full path of a command
 * @command : The command to search
 * Return: pointer to the full path string,or NULL if not found
 */

char *get_command_path(char *command)
{
	char *cmd_path = NULL;

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			cmd_path = strdup(command);
	}
	else
	{
		cmd_path = which_path(command);
	}
	return (cmd_path);
}
