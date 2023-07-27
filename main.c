#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point for the simple shell program.
 *
 * Description:
 * This function implements a basic shell that repeatedly reads commands from
 * the user or from input redirection, processes them, and executes the
 * corresponding programs. It uses a prompt to indicate user input when reading
 * from the terminal. The shell supports built-in commands "exit" and "env",
 * as well as executing external commands in the system's PATH.
 *
 * Return:
 * 0 on success, or an appropriate error code if an error occurs.
 */
int main(void)
{
    char *shellPrompt = "#cisfun$ ";
    char *inputLine = NULL;
    size_t bufferSize = 0;
    ssize_t numCharsRead;
    char **args;
    int numTokens;
    char *command;
    int i;

    if (!isatty(STDIN_FILENO))
    {
        shellPrompt = "";
    }

    while (1)
    {
        bufferSize = 0;
        write(STDOUT_FILENO, shellPrompt, strlen(shellPrompt));
        numCharsRead = getline(&inputLine, &bufferSize, stdin);

        if (numCharsRead == -1)
        {
            break;
        }

        command = split_input(inputLine);
        while (command != NULL)
        {
            parseInput(command, &args, &numTokens);

            if (numTokens > 0)
            {
                if (strcmp(args[0], "exit") == 0)
                {
                    for (i = 0; i < numTokens; i++)
                    {
                        free(args[i]);
                    }
                    free(args);
                    free(inputLine);
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
            for (i = 0; i < numTokens; i++)
            {
                free(args[i]);
            }
            free(args);

            command = split_input(NULL);
        }

        free(inputLine);
    }

    return (0);
}

