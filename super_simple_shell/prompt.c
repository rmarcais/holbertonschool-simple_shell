#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
* main - prompt
*
* Return: Always 0.
*/
int main(int ac, char **av)
{
	(void)av;
	(void)ac;
	char  *lineptr = NULL, *token = NULL, *delim = " ";
	size_t n;
	int read;

	printf("$ ");
	read = getline(&lineptr, &n, stdin);

	if (read != -1)
	{
		printf("%s", lineptr);

		token = strtok(lineptr, delim);
		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, delim);
		}
	}

	return (0);
}
