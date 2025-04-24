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
	return (c == ' ' || c == '\t' || c == '\n');
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
