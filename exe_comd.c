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
	char *r_command = NULL;

	r_command = locate_path(comd[0]);

	pid_child = fork();
	if (pid_child == 0)
	{
		if (execve(r_command, comd, environ) == -1)
		{
			perror(argv[0]);
			free_arr(comd);
			free(r_command);
			exit(127);
		}
	}
	else
	{
		waitpid(pid_child, &status, 0);
		free_arr(comd);
		free(r_command);
	}

	return (WEXITSTATUS(status));
}
