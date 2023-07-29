#include "shell.h"

/**
 * execmd - executes a command in a child process
 * @argv: array of arguments containing the command and its arguments
 *
 * Return: None
 */
void execmd(char **argv)
{
	pid_t pid;
	int status;
	if (!argv || !argv[0])
		return;
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return;
	}
	else if (pid == 0) /* Child process */
	{
		char *command = argv[0];
		char *actual_command = get_location(command);
		if (actual_command == NULL)
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		waitpid(pid, &status, 0);
	}
}
