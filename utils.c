#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * display_prompt - Prints the shell prompt to the standard output
 * This function displays a simple "$ " prompt on the terminal,
 * inviting the user to type a command.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * free_args - frees args
 * @args:array of characters
 */
void free_args(char **args)
{
	if (args != NULL)
		free(args);
}
