#include "shell.h"
/**
 * parseInput - Parse input line into separate arguments.
 *
 * @inputLine:what is parsed.
 * @args: Pointer to a pointer to store the array of arguments.
 * @numTokens: Pointer to integer storing the number of arguments.
 */
void parseInput(char *inputLine, char ***args, int *numTokens)
{
	const char *delimiter = " \n";
	char *inputLineCopy;
	char *currentToken;
	int index;
	int i;

	inputLineCopy = malloc(sizeof(char) * (strlen(inputLine) + 1));
	if (inputLineCopy == NULL)
	{
		perror("Shell Error: memory allocation");
		return;
	}
	strcpy(inputLineCopy, inputLine);

	*numTokens = 0;

	currentToken = strtok(inputLine, delimiter);
	while (currentToken != NULL)
	{
		(*numTokens)++;
		currentToken = strtok(NULL, delimiter);
	}

	*numTokens = *numTokens + 1;
	*args = (char **)malloc(sizeof(char *) * (*numTokens));
	if (*args == NULL)
	{
		perror("Shell Error: memory allocation");
		free(inputLineCopy);
		return;
	}

	currentToken = strtok(inputLineCopy, delimiter);
	index = 0;
	for (index = 0; currentToken != NULL; index++)
	{
		(*args)[index] = malloc(sizeof(char) * (strlen(currentToken) + 1));
		if ((*args)[index] == NULL)
		{
			perror("Shell Error: memory allocation");
			for (i = 0; i < index; i++)
			{
				free((*args)[i]);
			}
			free(*args);
			free(inputLineCopy);
			return;
		}
		strcpy((*args)[index], currentToken);
		currentToken = strtok(NULL, delimiter);
	}
	(*args)[index] = NULL;

	free(inputLineCopy);
}

