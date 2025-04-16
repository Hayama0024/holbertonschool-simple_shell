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

	if (args[0] == NULL)
		return (1);

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (access(args[0], X_OK) == 0)
			cmd_path = strdup(args[0]);
	}
	else
	{
		cmd_path = which_path(args[0]);  /* custom implementation */
	}

	if (cmd_path == NULL)
	{
		dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
		return (1);  /* no fork*/
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
		/* Child process */
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("execve");
			free(cmd_path);
			exit(127);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}

	free(cmd_path);
	return (1);
}
