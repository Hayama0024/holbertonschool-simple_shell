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
	char **lines;
	int last_status = 0;
	int i = 0;

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

		lines = split_lines_by_newline(line);

		for (i = 0; lines[i]; i++)
		{
			args = split_line(line);
			if (args[0] != NULL)
			{
				last_status = execute_command(args);

				if (last_status == 0)
				{
					free(line);
					free_args(args);
					free_args(lines);
					exit(0);
				}
			}
			free_args(args);
		}

		free_args(lines);
		free(line);
	}
	return (0);
}
