#include "shell.h"
/**
 * main - Entry point for the simple shell
 *
 * Displays a prompt, reads input, parses it, and executes commands.
 * Repeats until the user exits or sends EOF (Ctrl+D).
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	char **args = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		display_prompt();

		line = read_input();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			break;
		}

		args = split_line(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				free_args(args);
				exit(0);
			}

			execute_command(args);
		}

		free(line);
		free_args(args);
	}
	return (0);
}
