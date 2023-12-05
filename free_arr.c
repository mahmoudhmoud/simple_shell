#include "simpleShell.h"

/**
 * free_arr - free array of strings
 * @array: array to be freed
 *
 * Return: nothing
 */
void free_arr(char **array)
{
	int j;
	
	if (array == NULL)
		return;

	for (j = 0; array[j]; j++)
	{
            free(array[j]);
        }
        free(array);
}
