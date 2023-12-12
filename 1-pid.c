#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t process_id, parent_id;
	
	parent_id = getppid();
	process_id = getpid();
	
	printf("Procces id: %u\n", process_id);
	printf("Parent id: %u\n", parent_id);
	return (0);
}
