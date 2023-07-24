#include "shell.h"

/**
 * __cd - changes the working dir
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int __cd(char **args)
{
    	if (args[1] == NULL)
    	{
        	perror("expected argument to \"cd\"\n");
    	}
    	else
    	{
        	if (chdir(args[1]) != 0)
            		perror("error while changing directory");
    	}
    	return (-1);
}

/**
 * __env - prints environment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int __env(char **args)
{
    	int i = 0;
    	(void)(**args);

    	while (environ[i])
    	{
        	write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        	write(STDOUT_FILENO, "\n", 1);
        	i++;
    	}
    	return (-1);
}

/**
 * __exit - terminates a process
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int __exit(char **args)
{
    	/* exit with status */
    	if (args[1])
    	{
        	return (atoi(args[1]));
    	}
    	/* exit success */
    	else
    	{
        	return (0);
    	}
}
