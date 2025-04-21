#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_input - Read a full line of input from stdin
 *
 * This function uses getline() to read an entire line from the user
 * input including the newline character. It returns a pointer to the
 * read line, which must be freed by the caller.
 *
 * Return: Pointer to the input line, or NULL on EOF or error
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * split_line - Split a line into tokens (words) by whitespace
 *
 * This function takes a string and splits it into tokens based on
 * delimiters like space, tab, carriage return, and newline.
 * It dynamically allocates memory to hold the resulting array
 * of strings (words).
 *
 * @line: The input string to split
 *
 * Return: A NULL-terminated array of strings (tokens),
 *         or NULL on failure
 */

char **split_line(char *line)
{
	char *token;
	char **tokens = NULL;
	int bufsize = 64;
	int i = 0;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;

		if (i >= bufsize)
		{
			bufsize *= 2;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
