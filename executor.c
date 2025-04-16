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
	char *cmd_path;

	if (args[0] == NULL) /*in case of an empty command*/
	{
		return (1);
	}

	cmd_path = which_path(args[0]);
	if (cmd_path == NULL)
	{
		perror("Command not found");
		return (1);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0) /*if the current prosess is a child process*/
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("execve");
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	else /*for the parent process*/
	{
		waitpid(pid, &status, 0); /*wait for child process to finish*/
	}
	free(cmd_path);
	return (1);/*continue the shell*/
}
