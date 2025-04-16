#include "shell.h"


/**
* execute_command - Executes a command using fork and execve
* @args: an array of strings containing
*       the command (args[0]) to execute
* Return: 1 always
*        (indicates the shell should continue running)
*/


int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;
	struct stat st;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (stat(args[0], &st) != 0)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return (1);
		}
		cmd_path = strdup(args[0]);
	}
	else
	{
		cmd_path = which_path(args[0]);
		if (!cmd_path)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return (1);
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (-1);
	}

	if (pid == 0)
	{
		execve(cmd_path, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	free(cmd_path);
	return (1);
}

