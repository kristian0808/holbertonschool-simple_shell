#include "shell.h"
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>

/**
 * main -entry point,displays prompt,reads command and reacts
 * @argc: -holds the value of the nr of arguments of the command
 * @argv: -double pointer,points to the array of pointers of the command strings
 * Return (0)
 */

int main (int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL;
	size_t buf_size = 0;
	size_t characters = 0;
	name = argv[0];

	while (1)
	{
		write(1, "$ ", 2);
		characters = getline (&line, &buf_size, stdin);
		if (characters == -1)
		{
			perror("Error");
			break;
		}
		if (line[characters -1] == '\n')
		{
			line[characters -1] = '\0';
		}
		if (*line =='\0')
		{
			continue;
		}
		if (command_read(line) == 2)
		{
			break;
		}
	}
		free(line);
	return (0);
}
