#include "shell.h"

/**
 * read_input - read line of input
 *
 * Return: pointer to the input read
 */
char *read_input(void)
{
	char *input = NULL;
	size_t buffsize = 0;

	/* get input */
	if(getline(&input, &buffsize, stdin) == -1)
	{
		if(feof(stdin)) /* EOF or Ctrl+D */
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	}

	return(input);
}