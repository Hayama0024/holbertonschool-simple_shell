#include "shell.h"

/**
 * realloc_tokens - Reallocate memory for a dynamically growing array
 * @tokens: Pointer to the current array of strings
 * @bufsize: Pointer to the current size of the buffer
 *
 * Return: Pointer to the reallocated array of strings
 */

char **realloc_tokens(char **tokens, int *bufsize)
{
	*bufsize *= 2;
	tokens = realloc(tokens, sizeof(char *) * (*bufsize));
	if (!tokens)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	return (tokens);
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
	char *trim_whitespace(char *line);

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

	line = trim_whitespace(line);
	if (*line == '\0')
	{
		free(tokens);
		return (NULL);
	}

	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		if (i >= bufsize)
			tokens = realloc_tokens(tokens, &bufsize);
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	if (i == 0)
	{
		free(tokens);
		return (NULL);
	}
	return (tokens);
}


/**
 * split_lines_by_newline - Split a string into lines by '\n'
 * @line: Input string to split
 * Return: NULL-terminated array of lines
 */


char **split_lines_by_newline(char *line)
{
	char *token;
	char **lines = NULL;
	int bufsize = 16;
	int i = 0;

	lines = malloc(sizeof(char *) * bufsize);
	if (!lines)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, "\n");
	while (token != NULL)
	{
		lines[i++] = strdup(token);
		if (i >= bufsize)
		{
			bufsize *= 2;
			lines = realloc(lines, sizeof(char *) * bufsize);
			if (!lines)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, "\n");
	}
	lines[i] = NULL;
	return (lines);
}
