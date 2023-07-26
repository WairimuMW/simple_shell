#include "shell.h"

/**
 * main - checks if the shell has been called
 *
 * Description: Initializes the command line interpreter which reads input, parses and executes it, 
 * 				then loops to read the next command. 
 * Return: 0 on success, appropriate error otherwise
 */
int main(void)
{
	char *prompt = "#cisfun$ ";
	char *input = NULL;
	size_t buffsize = 0;
	char **args, *command;
	int tokens, i;

	if (!isatty(STDIN_FILENO))
		prompt = "";
	
	while (1)
	{
		buffsize = 0;
		write(STDOUT_FILENO, prompt, strlen(prompt));

		if ((getline(&input, &buffsize, stdin)) == -1)
		{
			write(STDOUT_FILENO, "Shell Exiting...\n", 17);
			break;
		}
		
		command = split_input(input);
		while (command != NULL)
		{
			parseInput(command, &args, &tokens);
			if (tokens > 0)
			{
				if (strcmp(args[0], "exit") == 0)
				{
					write(STDOUT_FILENO, "Exiting shell...\n", 17);
					for (i = 0; i < tokens; i++)
						free(args[i]);
					free(args);
					free(input);
					return (0);
				}
				else if (strcmp(args[0], "env") == 0)
				{
					print_environment();
				}
				else
				{
					execmd(args);
				}
			}
			for (i = 0; i < tokens; i++)
				free(args[i]);
			free(args);
			command = split_input(NULL);
		}
		free(input);
	}
	return (0);
}
