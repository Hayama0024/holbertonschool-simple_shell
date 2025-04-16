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

	if (!cmd_path)
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		_exit(127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)/*child process*/
	{
		execve(cmd_path, args, environ);
		perror("./hsh");
		exit(127);
	}
	else/*parent process*/
	{
		waitpid(pid, &status, 0);
	}
	if (cmd_path != args[0])
		free(cmd_path);

	return (1);
}
