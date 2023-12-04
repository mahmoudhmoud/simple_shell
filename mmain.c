#include "simpleShell.h"

/**
 * main - is the main function
 * @ac: is use for dakchi
 * @argv: is use for hadakchi
 *
 * Return: walo
 */

int main(int ac, char **argv)
{

	char *ptrline = NULL;
	ssize_t r;
	size_t size = 0;
	char **commands;
	int j;

	(void)ac;
	(void)argv;


	while (1)
	{

		prompt();
		r = getline(&ptrline, &size, stdin);
		if (r == -1)
		{
			free(ptrline);
			return (-1);
		}

		commands = str_tokeniz(ptrline);
		if (!commands)
			continue;

		for (j = 0; commands[j] != NULL; j++)
		{
			printf("%s\n", commands[j]);
			free(commands[j]);
		}
		free(commands);
	}
	free(ptrline);
	return (0);
}

