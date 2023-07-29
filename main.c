#include "shell.h"

/**
 * main - checks if the shell has been called
 *
 * Description: If there is an open terminal, the interactive shell mode is called.
 *              If there is no open terminal, the noninteractive shell mode is called.
 * Return: 0 on success
 */
int main(void)
{
    /* determines if file descriptor is associated with a terminal */
    if (isatty(STDIN_FILENO) == 1)
        interact_mode(); /* interactive shell mode is initialized */
    else
        non_interact_mode(); /* non_interactive shell mode is initialized */
    return (0);
}