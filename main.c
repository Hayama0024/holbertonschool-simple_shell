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
	int status = 1;

	while (1)
	{
		display_prompt();
		line = read_input();

		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = split_line(line);
		if (args[0] != NULL)
		{
			status = execute_command(args);
			if (status != 0)
			{
				printf("something went wrong\n");
			}
		}

		free(line);
		free_args(args);
	}
	return (0);
}
