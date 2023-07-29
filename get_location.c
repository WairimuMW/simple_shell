#include "shell.h"
/**
 * get_location - Finds full path of command by searching through the PATH
 *                environment variable.
 *
 * Description:
 * get_location takes command name as input and searches for its full path by
 * checking each directory listed in the PATH environment variable. If the command
 * is found in any of the directories, returns ful path. If the command
 * is not found in any directories, it checks if the command itself is a
 * valid path, if so,returns command itself.
 *
 * @command:command name to search for.
 *
 * Return:
 * On success, a pointer to full path of command is returned.
 * If command is not found, NULL is returned.
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;
	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token);
			_strncat(file_path, "/", MAX_PATH_LENGTH);
			_strncat(file_path, command, MAX_PATH_LENGTH);
			strncat(file_path, "\0", MAX_PATH_LENGTH);
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}


