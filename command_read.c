#include<string.h>
/**
 * command_read -reads command for input
 * @s: - points to the string of the command input
 * Return (execute(cmd_array))
 */
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
