#include "simpleShell.h"

/**
 * prompt - to print the the shell prompt
 *
 * Return: Nothing
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

