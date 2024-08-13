#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait & execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for(i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
    		{
        		perror("Error:");
        		return (1);
    		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
                	{
                        	perror("Error:");
				return (1);
                	}
		}
		else
			wait(&status);
	}

	return (0);
}
