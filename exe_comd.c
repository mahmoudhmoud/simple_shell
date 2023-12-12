#include "simpleShell.h"

/**
 * exe_comd - handling the command execution.
 * @comd: array of strings that contains the command and its flags
 * @argv: argument(./shell)
 * @child_cnt: counter
 *
 * Return: status
 */

int exe_comd(char **comd, char **argv, int child_cnt)
{

	pid_t pid_child;
	int status;
	char *r_command = NULL;

	r_command = locate_path(comd[0]);
	if (r_command == NULL)
	{
		command_err(comd, argv, child_cnt);
		free_arr(comd);
		return (-1);
	}

	pid_child = fork();
	if (pid_child == 0)
	{
		if (execve(r_command, comd, environ) == -1)
		{
			free_arr(comd);
			free(r_command);
		}
	}
	else
	{
		waitpid(pid_child, &status, 0);
		free_arr(comd);
		free(r_command);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}

