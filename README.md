# Simple Shell
Simple Shell is a miniature UNIX command-line interpreter written in C.
It mimics the behavior of standard shells like /bin/sh, allowing users to execute basic commands in a controlled environment. This project serves as a hands-on introduction to low-level system programming and process management in UNIX-like systems.

## Description :memo:
This repository is a team project from the foundation class at Holberton School.
The purpose of this project is to understand how the shell works.
(handling input, parsing, process creation, and execution.)

## Environment :computer:
- **Language:** C
- **Operating System:** Ubuntu 24.04
- **git version:**  2.43.0
- **gcc version:** 13.3.0
- **Style guideline:**  [Betty style](https://github.com/holbertonschool/Betty/wiki)

## Files :white_check_mark:

| File | Description |
|--------|--------|
|[AUTHORS](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/AUTHORS) |Contributors in this repository  |
| [README.md](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/README.md) | Information about our repository |
| [executor.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/executor.c) | Execution function |
|[input.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/input.c) |Functions for reading user input|
|[main.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/main.c)| main function|
[shell.h](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/shell.h)|Prototypes functions and headers|
|[utils.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/utils.c)|Auxiliary functions (e.g. prompt display, momory freeing) etc...)


## Feauture:sparkles:
- Custom interactive shell prompt
- Executes commands found in the system's PATH
- Supports commands with arguments (e.g., ls -l, echo hello)
- Gracefully handles command not found errors
- Handles EOF (Ctrl+D) for clean shell exit
- Built-in support for:
    exit — exits the shell
    env — displays the current environ

##Limitations:no_entry_sign:
-No support for semicolons ;, pipes |, redirections < >, or backgrounding &
-No handling of special characters like ", ', \, *, #, etc.
-No cursor movement or line editing features
-No implementation of additional built-in commands (e.g., cd, alias, etc.)

## Install :arrow_down:
```
$ git clone https://github.com/Hayama0024/holbertonschool-simple_shell.git
```

## Compilation :left_right_arrow:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage :bulb:
```
$ . /hsh
```
## Examples :pencil2:
It works like this in interactive mode:
1. /bin/ls
```
$ /bin/ls
AUTHORS  README.md  executor.c  hsh  input.c  main.c  shell.h  utils.c
```
### Exmples Builtin
Simple shell supports two built-in commands:exit and env.


## Man page :book:
```
$ man . /man_1_simple_shell
```
## Flow chart :round_pushpin:

![Image](https://github.com/user-attachments/assets/51cd72be-0631-4e98-b36e-47c3ca66cd93)


## Authors :bookmark:
[Ryota Higa](https://github.com/Hayama0024)<br>
[Emi Hatano](https://github.com/Emi-H106)
