#include "shell.h"

/**
 * check_type_cmd - checks whether a command is a builtin or a process
 * 
 * @args: command and it's subsequent arguments
 * Description: Checks whether a command matches a builtin function. If it does, it redirects to the specific function.
 * 				If it doesn't, the execute_cmd() function is called.
 * Return: 1 on sucess, 0 otherwise
 */
int check_type_cmd(char **args)
{
    	char *builtin_list[] = {"cd", "env", "exit"};
    	int (*builtin_func[])(char **) = {__cd, __env, __exit};
    	long unsigned int i = 0;

    	if (args[0] == NULL)
    	{
        	/* no command entered */
        	return (-1);
    	}

    	/* check if the command is a builtin */
    	for (; i < sizeof(builtin_list) / sizeof(char *); i++)
    	{
        	/* if there is a match execute the builtin command */
        	if (strcmp(args[0], builtin_list[i]) == 0)
            	return ((*builtin_func[i])(args));
    	}
    	/* if no match create a new process */
    	return (execute_cmd(args));
}

/**
 * locate_path - searches for the path of a command in environment
 * 
 * @cmd: command whose path is searched for
 * Description: Searches for the full path of a command from "$PATH" and restructures it into a suitable format.
 * Return: full path of command, NULL otherwise
 */
char *locate_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy, *path_token, *full_path;
	int cmd_length, dir_length;
	if(path)
	{
		path_copy = strdup(path); /* duplicate path */
		cmd_length = _strlen(cmd); /* find command length */
		path_token = strtok(path_copy, ":"); /* split $PATH */
		while (path_token != NULL)
		{
			dir_length = _strlen(path_token);
			full_path = malloc(cmd_length + dir_length + 2);
			/* copy dir path and concat cmd to it */
			strcpy(full_path, path_token);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			strcat(full_path, "\0");
			/* check if file is executable */
			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			else /* free full_path and check another path */
			{
				free(full_path);
				path_token = strtok(NULL, ":");
			}
		}
		/* if path isn't found, free path_copy */
		free(path_copy);
		/* check if cmd is an executable file */
		if(access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}

/**
 * execute_cmd - initiates a new process and executes a command
 * 
 * @args: array of input tokens
 * Description: Creates a new child process in which the command whose full path has been extracted is executed.
 * Return: 1 if success, appropriate error otherwise
 */
int execute_cmd(char **args)
{
	char *command = NULL;
	char *full_path = NULL;
	pid_t pid;
	int status;
	if(args)
	{
		/* assign command */
		command = args[0];
		/* get path */
		full_path = locate_path(command);
		/* create child process */
		pid = fork();
		if (pid == -1)
		{
			perror("fork() failed");
		}
		else if (pid == 0)
		{
			/* execute command */
			if(execve(full_path, args, NULL) == -1)
				perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* parent process */
			do
        		{
            		waitpid(pid, &status, WUNTRACED);
        		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			free(full_path);
		}
	}
	return (-1);
}
