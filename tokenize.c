#include "shell.h"

/**
 * split_input - splits a string into tokens
 * @input: string to be split
 *
 * Return: pointer to the next token, NULL otherwise
 */
char *split_input(char *input)
{
	static char *command;
	static char *saveptr;
	if (input != NULL)
		command = strtok_r(input, ";", &saveptr);
	else
		command = strtok_r(NULL, ";", &saveptr);
	return (command);
}
