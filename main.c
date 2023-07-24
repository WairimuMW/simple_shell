#include "shell.h"

/**
 * main - checks if the shell has been called
 *
 * Return: 0 on success
 */
int main(void)
{

	/* determines if file descriptor is associated with a terminal */
    	if (isatty(STDIN_FILENO) == 1)
        	interact_mode(); /* interactive shell mode is initialized */
    	else	
        	non_interact_mode(); /* non_interactive mode is initialized */
    	return (0);
}
