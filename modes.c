#include "shell.h"

/**
 * interact_mode - command line interpreter in interactive mode
 *
 * Return: none
 */
void interact_mode(void)
{
    	char *input;
    	char **args;
    	int status = -1;

    	do
    	{
        	print_prompt();	/* print prompt string */
        	input = read_input_interact(); /* read the next line of input */
        	args = split_input(input); /* tokenize */
        	status = map_cmd(args);
        	/* free memory */
        	free(input);
        	free(args);
        	/* exit with status */
        	if (status >= 0)
        	{
            		exit(status);
        	}
    	} while (status == -1);
}

/**
 * non_interact_mode - command line interpreter in non-interactive mode
 *
 * Return: none
 */
void non_interact_mode(void)
{
    	char *input;
    	char **args;
    	int status = -1;

    	do
    	{
        	input = read_input_non_interact();
        	args = split_input(input); /* tokenize */
        	status = map_cmd(args);
        	/* free memory */
        	free(input);
        	free(args);
        	/* exit with status */
        	if (status >= 0)
        	{
            		exit(status);
        	}
    	} while (status == -1);
}
