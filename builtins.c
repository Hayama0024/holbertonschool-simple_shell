#include "shell.h"


/**
 * check_and_run_builtin - Checks and executes a built-in command
 * @args: Array of command arguments
 *
 * If the command is a built-in ("exit" or "env"), it executes it.
 * If the command is "exit", the shell process is terminated.
 *
 * Return: -1 if not a built-in, 0 if "exit"
 */

int check_and_run_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
		exit(0);

	if (strcmp(args[0], "env") == 0)
	{
		int i = 0;

		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (0);
	}

	return (-1);
}
