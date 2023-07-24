#include "shell.h"

/**
 * main - initializes the command line interpreter
 *
 * Return: 0 on success
 */
int main(void)
{

	char *input;
	char **args;
	int status = -1;

	do
	{
		print_prompt();			   /* print prompt string */
		input = read_input();	   /* read the next line of input */
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

	return (0);
}
