#ifndef SHELL_H
#define SHELL_H

/* Library */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/* environmental variables */
extern char **environ;

/* prompt and input */
void display_prompt(void);
char *read_input(void);

/* split command and execution */
char **split_line(char *line);
char **realloc_tokens(char **tokens, int *bufsize);
char **split_lines_by_newline(char *line);
int execute_command(char **args);
char *trim_whitespace(char *str);

/* memory freeing and utility */
void free_args(char **args);
int _strlen(const char *s);
void print_error(char *prog_name, char *cmd);

/* path and built-in */
char *which_path(char *command);
char *_get_path(void);
int check_and_run_builtin(char **args);
char *get_command_path(char *command);
void print_not_found_error(char *command);
#endif /* SHELL_H */
