# The Simple Shell Program

This project is about creating a simple shell that mimics the fundamental features of the [Bash](https://en.wikipedia.org/wiki/Unix_shell) shell.

## Introduction

This `Simple Shell` is a basic Unix shell that provides a user
interface to interact with the operating system. It reads and executes user commands, supports basic built-in commands, and manages processes. While it lacks the complexity of more advanced shells, this Simple Shell serves as a valuable learning tool for understanding core shell concepts.It is build blending user defined functions,syscalls and standard lib functions to achieve such scope.As for a more detailed review of what it does,it takes a command as an input and then parses it into tokens.After receiving the first argument the system browses the PATH environ variable for the executable file linked to the respective command,after finding it a child process is created to be substituted with that specific program via the execve syscall.Then the parent process takes the lead and finalizes the process attaching the rest of the arguments.This simple shell also manages the specific cases of different occurrances,like invalid command or empty command.

The project's purpose is to provide a starting point for individuals new to shell programming or seeking insights into the fundamental aspects of shell operation.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Features](#features)
- [Command Execution](#commandexecution)
- [Examples](#examples)
- [Authors](#authors)

## Requirements

### General
* Allowed editors: `vi`, `vim`, `emacs`
* All files were compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* Betty coding style is followed.
* The simple shell has no known memory leaks

## Installation

Designed to run on `Ubuntu 20.04 LTS`, the simple_shell can be installed as follows:

* Clone the current repository with the command: `git clone` `"https://github.com/romeollangozi/holbertonschool-simple_shell"`
* `cd` in to the cloned directory: `cd holbertonschool-simple_shell`
* Create an executable using: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
* Run the executable using `./hsh`.

## Features
Our simple shell fulfils these features :

* **Prompt Display**: The shell displays a prompt ($ ) where you can input commands.
```
if (isatty(STDIN_FILENO) == 1)
      write(1, "$ ", 2);
```
* **Repeat Prompt:** After executing a command, the shell displays the prompt again for the next command.
* **Command Line:** The shell supports simple command lines and the ones with arguments.
* **Command Not Found:** If an executable cannot be found, the shell prints an error message and displays the prompt again.
* **Error Handling:** The shell handles errors and provides informative error messages.
* **End of File (Ctrl+D):** The shell handles the "end of file" condition (Ctrl+D) and exits the shell.
* **PATH Handling:** The shell uses the PATH environment variable to locate executables.
* **Built-in Commands:** The shell includes two built-in commands:

   * exit: Exits the shell.
   * env: Prints the current environment variables.

## Command Execution
1. The shell displays a prompt ( $ ).
2. Input a command (e.g., ls) and press Enter.
3. The simple shell uses the `fork` system call to create a child process that will execute the command.
3. In the child process, the simple shell uses the `exec` family of functions (execvp) to load the specified executable and its arguments.
4. The parent process (shell) uses the `wait` system call to wait for the child process to terminate, ensuring synchronization.
5. The `exit status` of the child process is obtained and displayed, providing information about whether the command executed successfully.

### Examples

ls command

How is executed in the original shell:
```
root@20290861f1ec:~/holbertonschool-simple_shell# ls
a.out  command_execute.c  command_path.c  command_read.c  env_utils.c  README.md  shell.c  shell.h
```

How is executed in our simple shell:

```
$ ls
a.out  command_execute.c  command_path.c  command_read.c  env_utils.c  README.md  shell.c  shell.h
$
```

ls -la command

How is executed in the original shell:

```
root@20290861f1ec:~/holbertonschool-simple_shell# ls -la
total 52
drwxr-xr-x 3 root root   166 Dec 21 15:41 .
drwx------ 1 root root  4096 Dec 21 15:39 ..
-rwxr-xr-x 1 root root 18144 Dec 21 15:41 a.out
-rw-r--r-- 1 root root   840 Dec 21 15:38 command_execute.c
-rw-r--r-- 1 root root  1011 Dec 21 15:38 command_path.c
-rw-r--r-- 1 root root   498 Dec 21 15:38 command_read.c
-rw-r--r-- 1 root root  1292 Dec 21 15:38 env_utils.c
drwxr-xr-x 8 root root   220 Dec 21 15:38 .git
-rw-r--r-- 1 root root    31 Dec 19 08:20 README.md
-rw-r--r-- 1 root root   700 Dec 21 15:39 shell.c
-rw-r--r-- 1 root root   429 Dec 21 15:38 shell.h
root@20290861f1ec:~/holbertonschool-simple_shell#
```
How is executed in our simple shell:

```
$ ls -la
total 52
drwxr-xr-x 3 root root   166 Dec 21 15:41 .
drwx------ 1 root root  4096 Dec 21 15:39 ..
-rwxr-xr-x 1 root root 18144 Dec 21 15:41 a.out
-rw-r--r-- 1 root root   840 Dec 21 15:38 command_execute.c
-rw-r--r-- 1 root root  1011 Dec 21 15:38 command_path.c
-rw-r--r-- 1 root root   498 Dec 21 15:38 command_read.c
-rw-r--r-- 1 root root  1292 Dec 21 15:38 env_utils.c
drwxr-xr-x 8 root root   220 Dec 21 15:38 .git
-rw-r--r-- 1 root root    31 Dec 19 08:20 README.md
-rw-r--r-- 1 root root   700 Dec 21 15:39 shell.c
-rw-r--r-- 1 root root   429 Dec 21 15:38 shell.h
$
```

### Authors

Remzion Keqi | [@remzionkeqi](https://github.com/Remz97)

Kristian LLeshaj | [@kristianlleshaj](https://github.com/kristian0808)

Enea Milo | [@eneamilo](https://github.com/eneamilo91)

Atilio Sulovari | [@atiliosulovari](https://github.com/a7il10)
