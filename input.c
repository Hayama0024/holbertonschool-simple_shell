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
 * is_whitespace - Check if a character is a whitespace character
 * @c: The character to check
 *
 * Return: 1 if the character is a whitespace character, 0 otherwise
 */

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

/**
 * trim_whitespace - Trim leading and trailing whitespace from a string
 * @str: The input string to trim
 *
 * Return: Pointer to the trimmed string
 */

char *trim_whitespace(char *str)
{
	char *end;

	while (is_whitespace(*str))
	{
		str++;
	}

	end = str + strlen(str) - 1;
	while (end > str && is_whitespace(*end))
	{
		end--;
	}

	*(end + 1) = 0;

	return (str);
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

	line = trim_whitespace(line);
	if (*line == '\0')
	{
		free(tokens);
		return (NULL);
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

