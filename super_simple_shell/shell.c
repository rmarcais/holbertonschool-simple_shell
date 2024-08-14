#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - first version of a super simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	char *args[3];
	size_t n;
	int read, status;
	pid_t child_pid;

	while(1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &n, stdin);

		if (read == -1)
			perror("Error");
		else
		{
			child_pid = fork();

			if (child_pid == -1)
                	{
                        	perror("Error");
                        	return (-1);
                	}
                	if (child_pid == 0)
			{
				args[0] = strtok(line, "\n");
				args[0] = strtok(args[0], " ");
				args[1] = strtok(NULL, " ");
				args[2] = NULL;
                        	if (execve(args[0], args, NULL) == -1)
                        	{
                                	perror("Error1");
                                	exit (-1);
                        	}
                	}
                	else
                        	wait(&status);
		}
	}

	return (0);
}
