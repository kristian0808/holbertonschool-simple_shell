#include"shell.h"
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>

/**
 * execute -substitutes child process with respective program
 * @cmd_arr[]: - points to the array of pointers that point to respective string of command
 * Return: (0)
 */

int execute(char *cmd_arr[])
{
        pid_t pid;
        char *exe_path;
        int status;

        exe_path = command_path(cmd_arr[0]);

        if (exe_path == NULL)
        {
                fprintf(stderr, "%s: %s: not found", name, cmd_arr[0]);
                return (3);
        }
        pid = fork();
        if (pid < 0)
        {
                perror ("Error ...");
                return (-1);
        }
        if (pid > 0)
        {
                wait(&status);
        }
        else
        {
                if(environ)
                {
                        execve(exe_path, cmd_arr, environ);
                }
                else
                {
                        execve(exe_path, cmd_arr, NULL);
                }
        }
        free (exe_path);
        return(0);
}
