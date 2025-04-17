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
 
 	if (!args || !args[0])
 		return (1);
 
 	if (args[0][0] == '/' || args[0][0] == '.')
 	{
 		if (access(args[0], X_OK) == 0)
			cmd_path = strdup(args[0]);
		else
			cmd_path = NULL;
 	}
	else
	{
		cmd_path = which_path(args[0]);
	}

	if (!cmd_path)
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		exit(127);
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
 		perror("execve");
 		exit(127);
 		
 	}
 	else /*for the parent process*/
 	{
 		waitpid(pid, &status, 0); /*wait for child process to finish*/
 	}
	if (cmd_path != args[0])
		free(cmd_path);
 	
	return (1);/*continue the shell*/
 }
