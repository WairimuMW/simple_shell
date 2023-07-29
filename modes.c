#include "shell.h"

/**
 * interact_mode - command line interpreter in interactive mode
 * 
 * Description: It implements a loop in which a prompt is displayed, the input is read and parsed then executed, 
 * 				and unless the user types "exit"; the prompt is displayed again.
 * Return: none
 */
void interact_mode(void)
{
	char *input;
	char **args;
	int status = -1;
	char *prompt = "($) ";

	do
	{
		write(STDOUT_FILENO, prompt, strlen(prompt)); /* print prompt string */
		input = read_input_interact(); /* read the next line of input */
		args = split_input(input); /* tokenize */
		status = check_type_cmd(args); /* check if cmd is built-in or not, then execute */
		/* free memory */
		free(input);
		free(args);
		/* exit with status */
		if (status >= 0)
			exit(status);
	} while (status == -1);
}

/**
 * non_interact_mode - command line interpreter in non-interactive mode
 * 
 * Description: The commands are entered and executed in noninteractive mode, that is,
 * 				without the use of an open terminal.
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
		status = check_type_cmd(args);
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
