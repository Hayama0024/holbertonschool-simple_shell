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
|[builtins.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/builtins.c)|Functions for built-in commands|
| [executor.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/executor.c) | Execution function |
|[input.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/input.c) |Functions for reading user input|
|[main.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/main.c)| main function|
[shell.h](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/shell.h)|Prototypes functions and headers|
|[split_line.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/split_line.c) |Functions for splitting and processing commands|
|[utils.c](https://github.com/Hayama0024/holbertonschool-simple_shell/blob/main/utils.c)|Auxiliary functions (e.g. prompt display, momory freeing) etc...)


## Feautures :sparkles:
- Custom interactive shell prompt
- Executes commands found in the system's PATH
- Supports commands with arguments (e.g., ls -l, echo hello)
- Gracefully handles command not found errors
- Handles EOF (Ctrl+D) for clean shell exit
- Built-in support for:<br>
    exit — exits the shell<br>
    env — displays the current environment<br>

## Limitations :no_entry_sign:

 - No support for semicolons ;, pipes |, redirections < >, or
   backgrounding &
 - No handling of special characters like ", ', \, *, #, etc.
 - No cursor movement or line editing features
 - No implementation of additional built-in commands (e.g., cd, alias,
   etc.)

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
**Interactive mode:**
 /bin/ls
```
$ /bin/ls
AUTHORS  README.md  executor.c  hsh  input.c  main.c  shell.h  utils.c
```
**Non-interactive mode:** echo "/bin/ls" | ./hsh<br>
```
$ echo "/bin/ls" | ./hsh
AUTHORS    builtins.c  hsh      main.c   utils.c
README.md  executor.c  input.c  shell.h
```
**External Commands:** ls , pwd, echo etc...<br>
```
$ ls
AUTHORS    builtins.c  hsh      main.c   utils.c
README.md  executor.c  input.c  shell.h
$ ls -l
total 60
-rw-r--r-- 1 emi emi   147 Apr 15 09:38 AUTHORS
-rw-r--r-- 1 emi emi  4212 Apr 23 10:37 README.md
-rw-r--r-- 1 emi emi  1133 Apr 23 10:32 builtins.c
-rw-r--r-- 1 emi emi  1941 Apr 22 13:06 executor.c
-rwxr-xr-x 1 emi emi 21800 Apr 23 13:35 hsh
-rw-r--r-- 1 emi emi  3075 Apr 23 10:32 input.c
-rw-r--r-- 1 emi emi   895 Apr 23 10:32 main.c
-rw-r--r-- 1 emi emi   895 Apr 22 13:57 shell.h
-rw-r--r-- 1 emi emi  2151 Apr 22 08:50 utils.c
$ pwd
/home/emi/holbertonschool-simple_shell
$ echo Hello
Hello
```
**Built-in commands:**
Simple shell supports two built-in commands - exit and env.<br>
1. exit
```
julien@ubuntu:~/holbertonschool-simple_shell$ ./hsh
$ exit
julien@ubuntu:~/holbertonschool-simple_shell$
```
2. env
```
julien@ubuntu:~/holbertonschool-simple_shell$ ./hsh
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$
```

## Man page :book:
```
$ man . /man_1_simple_shell
```
## Flow chart :round_pushpin:

![Image](https://github.com/user-attachments/assets/51cd72be-0631-4e98-b36e-47c3ca66cd93)


## Authors :bookmark:
[Ryota Higa](https://github.com/Hayama0024)<br>
[Emi Hatano](https://github.com/Emi-H106)
