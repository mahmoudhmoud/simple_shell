#include "simpleShell.h"

/**
 * locate_path - generate the path for the given command.
 * @command: command
 *
 * Return: path of the entered command
 */

char *locate_path(char *command)
{
	char *path = NULL, *copy_of_path = NULL, *token;
	char *full_path = NULL;
	struct stat stt;

	if (stat(command, &stt) == 0)
	{
		return (strdup(command));
	}

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	copy_of_path = strdup(path);

	token = strtok(copy_of_path, ":");
	if (token == NULL)
	{
		free(copy_of_path);
		return (NULL);
	}
	while (token != NULL)
	{
		full_path = malloc(sizeof(char) * (_strlen(command) + _strlen(token) + 2));
		if (full_path == NULL)
			return (NULL);
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (stat(full_path, &stt) == 0)
		{
			free(copy_of_path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(copy_of_path);
	return (NULL);
}

