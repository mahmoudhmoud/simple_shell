#include "simpleShell.h"

/**
 * main - is the main function
 * @ac: is use for dakchi
 * @argv: is use for hadakchi
 *
 * Return: wallo
 */

int main(int ac, char **argv)
{

	char *ptrline = NULL;
	ssize_t r;
	size_t size = 0;
	char **commands;
	int status = 0;

	(void)ac;


	while (1)
	{

		prompt();
		r = getline(&ptrline, &size, stdin);
		if (r == -1)
		{
			free(ptrline);
			return (status);
		}

		commands = str_tokeniz(ptrline);
		if (!commands)
		{
			free(ptrline);
			continue;
		}

		status = exe_comd(commands, argv);

	}
	free(ptrline);
	return (0);
}
