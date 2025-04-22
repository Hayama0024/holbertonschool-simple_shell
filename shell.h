#ifndef SHELL_H
#define SHELL_H

/* ライブラリ */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/* 環境変数 */
extern char **environ;

/* プロンプトと入力 */
void display_prompt(void);
char *read_input(void);

/* コマンドの分割と実行 */
char **split_line(char *line);
int execute_command(char **args);

/* メモリ解放やユーティリティ */
void free_args(char **args);
int _strlen(const char *s);
void print_error(char *prog_name, char *cmd);


char *which_path(char *command);
char *_get_path(void);
int handle_builtin(char **args);
int check_and_run_builtin(char **args);
char *get_command_path(char *command);
void print_not_found_error(char *command);
char **split_lines_by_newline(char *line);
#endif /* SHELL_H */
