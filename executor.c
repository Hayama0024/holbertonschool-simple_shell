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

	if (args[0] == NULL) /*in case of an empty command*/
	{
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
		/* Pass only the command without additional arguments */
		char *empty_args[2];
		empty_args[0] = args[0];
		empty_args[1] = NULL;	

		/*run without additional arguments*/
		if (execve(args[0], empty_args, environ) == -1)
		{
			perror("args[0]");
			exit(EXIT_FAILURE);
		}
	}
	else /*for the parent process*/
	{
		waitpid(pid, &status, 0); /*wait for child process to finish*/
	}

	return (1);/*continuing the shell*/
}
