#include "shell.h"

int main (int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL;
	size_t buf_size = 0;
	size_t characters = 0;
	name = argv[0];
	while (1)
	{
		write(1, "Bobi$", 5);
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
