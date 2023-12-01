#include "main.h"

/**
 * str_tokeniz - is the function dyalo
 * @line: is for daklchi
 *
 * Return: walo
 */
	char **str_tokeniz(char *line)
{

	char *token;
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
	free(line);
	return (NULL);
	}
	while (token != NULL)
	{
	n_tok++;
	token = strtok(NULL, delim);
	}
	free(line_copy); /*freed the line_copy bc i only used it to count tokens*/

	comd = malloc(sizeof(char *) * n_tok);
	if (comd == NULL)
	{
	free(line);
	return (NULL);
	}
	token = strtok(line, delim);
	for (k = 0; token != NULL; k++)
	{
	comd[k] = strdup(token);
	token = strtok(NULL, delim);
	}
	comd[k] = NULL;
	free(line);

	return (comd);
}

