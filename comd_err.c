#include "simpleShell.h"

/**
 * command_err - printing eroor of the command not exist
 * @command: the given command
 * @count: child process count
 * @argv: name of exe file(./hsh)
 * Return: Nothing
 */

void command_err(char **command, char **argv, int count)
{
	if (!command)
		return;

	fprintf(stderr, "%s: %d: %s: not found\n", argv[0], count, command[0]);
}
