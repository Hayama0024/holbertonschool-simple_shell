#include "shell.h"

/**
* process_input_line - Splits and processes each line of input
* @line: The full line read from stdin
* @last_status: Pointer to last command's exit status
*/
void process_input_line(char *line, int *last_status)
{
	char **lines = NULL;
	char **args = NULL;
	int i;

	if (line == NULL || *line == '\0' || trim_whitespace(line)[0] == '\0')
	{
	*last_status = 0;
	return;
	}

	lines = split_lines_by_newline(line);
	for (i = 0; lines[i]; i++)
	{
	args = split_line(lines[i]);
	if (args != NULL && args[0] != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			free_args(lines);
			exit(*last_status);
		}
	*last_status = execute_command(args);
	free_args(args);
	}
		else
		{
			if (trim_whitespace(lines[i])[0] == '\0')
			*last_status = 0;
			else
			*last_status = 127;
		}
	}
	free_args(lines);
}

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
	int last_status = 0;

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
		process_input_line(line, &last_status);
		free(line);
	}
	if (!isatty(STDIN_FILENO))
		exit(last_status);

	return (0);
}
