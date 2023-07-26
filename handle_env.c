#include "shell.h"
/**
 * print_environment - Print the environment variables.
 *
 * Description:
 * This function prints all the environment variables to the standard output.
 * The environment variables are retrieved from the global variable 'environ',
 * which is declared as 'extern char **environ;' in the header file 'unistd.h'.
 * Each environment variable is a string in the format 'key=value', and each
 * variable is printed on a separate line.
 *
 * Note: The 'environ' global variable is a null-terminated array of strings.
 * last element of 'environ' is set NULL, indicating end of array.
 *
 * Return: None (void)
 */
void print_environment(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		size_t length = 0;

		while (environ[i][length] != '\0')
		{
			length++;
		}
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}

