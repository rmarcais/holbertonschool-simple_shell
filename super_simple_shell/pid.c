#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t ppid;

	my_pid = getpid();
	ppid = getppid();
	printf("%u\n", my_pid);
	printf("%u\n", ppid);
	printf("%u\n", PID_MAX_LIMIT);
	return (0);
}

