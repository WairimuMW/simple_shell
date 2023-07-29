#include "shell.h"

/**
 * split_input - splits a string into tokens
 * @input: string to be split
 *
 * Description: Splits the input into tokens, excluding the delimiters, then stores these tokens in an array.
 * Return: array of tokens
 */
char **split_input(char *input)
{
	int buffsize = BUFFER_SIZE, pos = 0;
	char *token, *tok_delim = TOK_DELIM;
	char **tok_arr = malloc(sizeof(char) * buffsize);
	if (!tok_arr)
	{
		perror("Allocation Error");
		exit(EXIT_FAILURE);
	}

	/* break the input string into tokens */
	token = strtok(input, tok_delim);

	/* loop through the tokens */
	while (token != NULL)
	{
		tok_arr[pos] = token;
		pos++;

		if (pos >= buffsize)
		{
			buffsize += BUFFER_SIZE;
			tok_arr = realloc(tok_arr, sizeof(char) * buffsize);
			if (!tok_arr)
			{
				perror("Allocation Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, tok_delim);
	}
	tok_arr[pos] = NULL; /* null terminator for the array */
	return (tok_arr);
}