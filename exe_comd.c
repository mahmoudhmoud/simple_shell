#include "simpleShell.h"

/**
 * exe_comd - handling the command execution.
 * @comd: array of strings that contains the command and its flags
 * @argv: argument(./shell)
 *
 * Return: status
 */
int exe_comd(char **comd, char **argv)
{

	pid_t pid_child;
	int status;

	pid_child = fork();
	if (pid_child == 0)
	{
		if (execve(comd[0], comd, environ) == -1)
		{
			perror(argv[0]);
			free_arr(comd);
			exit(127);
		}
	}
	else
	{
		waitpid(pid_child, &status, 0);
		free_arr(comd);
	}

	return (WEXITSTATUS(status));
}
