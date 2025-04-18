#include "shell.h"


/**
 * print_not_found_error - Prints a standardized error
 *                         when a command is not found
 * @command: The command that failed to execute
 * Return: Nothing (void)
 */

void print_not_found_error(char *command)
{
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * handle_exec_failure - Handles the failure of execve
 * @cmd_path: The command path that failed to execute
 * Return: nothing (void)
 */

void handle_exec_failure(char *cmd_path)
{
	perror("execve");
	free(cmd_path);
	exit(127);
}

/**
 * handle_fork_failure - Handles the failure of fork
 * @cmd_path: The command path that was intended to be executed
 * Return: nothing(void)
 */

void handle_fork_failure(char *cmd_path)
{
	perror("fork");
	free(cmd_path);
}

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
	int status, builtin_result;
	char *cmd_path;

	if (!args || !args[0])
		return (1);

	builtin_result = check_and_run_builtin(args);
	if (builtin_result != -1)
		return (builtin_result);

	cmd_path = get_command_path(args[0]);
	if (!cmd_path)
	{
		print_not_found_error(args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		handle_fork_failure(cmd_path);
		return (-1);
	}

	if (pid == 0) /*if the current prosess is a child process*/
	{
		if (execve(cmd_path, args, environ) == -1)
			handle_exec_failure(cmd_path);
	}
	else /*for the parent process*/
	{
		waitpid(pid, &status, 0);
		if (cmd_path != args[0])
			free(cmd_path);

		 /*check if the operation was successful*/
		return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
	}
	return (-1);/*This line should never be reached*/
}
