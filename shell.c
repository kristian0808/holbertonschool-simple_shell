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
int command_read(char *s)
{
	int i;
	char *token = NULL;
	char *cmd_array[100];
	/**if commnad is exit or env*/

	if(strcmp(s, "exit") == 0)
	{
		return 2;
	}
	if (strcmp(s, "env") == 0)
	{
	return _printenv();
	}
	i = 0;
	token = strtok(s, " ");
	while (token != NULL)
	{
		cmd_array[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_array[i] = NULL;
	return (execute(cmd_array));
}
