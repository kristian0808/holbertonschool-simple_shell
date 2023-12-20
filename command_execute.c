#include"shell.h"
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>
/**
 * execute - Function that executes the shell
 * @cmd_array: First operand a pointer
 * Return: Return an int
 */
int execute(char *cmd_array[])
{
	char *exe_path = NULL;
	char *cmd = NULL;
	pid_t pid;
	int status;

	cmd = cmd_array[0];
	exe_path = command_path(cmd);
	if (exe_path == NULL)
	{
		write(2, strcat(cmd, ": Not found\n"), strlen(cmd) + 12);
		return (3);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating child\n");
		return (-1);
	}
	if (pid > 0)
		wait(&status);
	else if (pid == 0)
	{
		execve(exe_path, cmd_array, environ);
		perror("Error");
		exit(1);
	}
	free(exe_path);
	return (0);
}
