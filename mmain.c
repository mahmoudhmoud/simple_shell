#include "main.h"

/**
 * main - is the main function
 * @ac: is use for dakchi
 * @argv: is use for hadakchi
 *
 * Return: walo
 */

int main(int ac, char **argv)
{

	char *prompt = "(sh) $ ";
	char *ptrline = NULL;
	ssize_t r;
	size_t size = 0;
	char **commands;
	int j;

	(void)ac;
	(void)argv;


	while (1)
	{

	printf("%s", prompt);
	r = getline(&ptrline, &size, stdin);
	if (r == -1)

	return (-1);


	commands = str_tokeniz(ptrline);
	if (!commands)
	continue;

	for (j = 0; commands != NULL; j++)
	{
	printf("%s\n", commands[j]);
	}

	}

}

