#include "shell.h"

/**
 * handle_builtin - Check and execute built-in commands
 * @args: Arguments entered by the user
 *
 * Return:
 *  0 if shell should exit,
 *  1 if shell should continue,
 * -1 if not a built-in command
 */


int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}
	return (-1);
}


/**
 * check_and_run_builtin - Checks and executes a built-in command
 * @args: Array of command arguments
 *
 * If the command is a built-in ("exit" or "env"), it executes it.
 * If the built-in is "exit", the shell process is terminated.
 *
 * Return: -1 if not a built-in, 0 if "exit", or the built-in's return code
 */

int check_and_run_builtin(char **args)
{
	int result = handle_builtin(args);

	if (result == 0)
		exit(0);

	return (result);
}

