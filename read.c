#include "shell.h"

/**
 * read_input_interact - read line of input in interactive mode
 *
 * Return: pointer to the input read
 */
char *read_input_interact(void)
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

/**
 * read_input_non_interact - read a line of input in non-interactive mode
 *
 * Return: pointer to the input read
 */
char *read_input_non_interact(void)
{
    	int buffsize = BUFFER_SIZE, i = 0;
    	char *input = malloc(sizeof(char) * buffsize);
    	int character;

    	if (input == NULL)
    	{
        	perror("Allocation Error");
        	exit(EXIT_FAILURE);
    	}
    	while (1)
    	{
        	character = getchar(); /* read first character from stream */
        	if (character == EOF)
        	{
            		free(input);
            		exit(EXIT_SUCCESS);
        	}
        	else if (character == '\n')
        	{
            		input[i] = '\0';
            		return (input);
        	}
        	else
        	{
            		input[i] = character;
        	}
        	i++;
        	if (i >= buffsize)
        	{
            		buffsize += buffsize;
            		input = realloc(input, buffsize);
            		if (input == NULL)
            		{
                		perror("Reallocation Error");
                		exit(EXIT_FAILURE);
            		}
        	}
    	}
}
