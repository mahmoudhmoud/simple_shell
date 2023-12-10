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
	int child_cnt = 0;

	(void)ac;

	while (1)
	{
		child_cnt++;
		prompt();
		r = getline(&ptrline, &size, stdin);
		if (r == -1)
		{
			free(ptrline);
			ptrline = NULL;
			return (status);
		}

		commands = str_tokeniz(ptrline);
		if (!commands)
		{
			free(ptrline);
			ptrline = NULL;
			continue;
		}

		status = exe_comd(commands, argv, child_cnt);


	free(ptrline);
	ptrline = NULL;
	}

	return (0);
}

