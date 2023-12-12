#include "simpleShell.h"

/**
 * command_builtin - to check if the command is built-in
 * @comd: command
 * Return: 1 (true) or 0 (false)
 */
int command_builtin(char **comd)
{
	char *arr[] = {"exit", "env", NULL};
	int i;

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(comd[0], arr[i]) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

/**
 * exe_builtin - execute the built-in
 * @comd: command
 * @argv: argument
 * Return: nothing
 */

void exe_builtin(char **comd, char **argv)
{
	int stattus, i;
	(void)argv;

	if (_strcmp(comd[0], "exit") == 0)
	{
		if (comd[1])
		{
			stattus = _atoi(comd[1]);
			free_arr(comd);
			exit(stattus);
		}
		free_arr(comd);
		exit(0);
	}
	if (_strcmp(comd[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free_arr(comd);
	}
}
