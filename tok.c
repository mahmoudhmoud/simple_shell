#include "simpleShell.h"

/**
 * str_tokeniz -  the function to split a given line
 * @line: line to be split
 *
 * Return: array of strings
 */
char **str_tokeniz(char *line)
{
	char *token = NULL;
	char *line_copy = NULL;
	const char *delim = " \n\t";
	int n_tok = 0;
	char **comd = NULL;
	int k;

	line_copy = strdup(line);

	token = strtok(line_copy, delim);
	if (token == NULL)
	{
		free(line_copy);
		return (NULL);
	}
	while (token != NULL)
	{
		n_tok++;
		token = strtok(NULL, delim);
	}

	comd = malloc(sizeof(char *) * (n_tok + 1));
	if (comd == NULL)
	{
		free(line_copy);
		return (NULL);
	}
	token = strtok(line, delim);
	for (k = 0; token != NULL; k++)
	{
		comd[k] = strdup(token);
		token = strtok(NULL, delim);
	}
	comd[k] = NULL;
	free(line_copy);

	return (comd);
}

