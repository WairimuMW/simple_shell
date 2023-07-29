#include "shell.h"

/**
 * _strncat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: maximum number of characters to be appended
 *
 * Return: pointer to the concatenated string (dest)
 */
char *_strncat(char *dest, const char *src, int n)
{
    int dest_len = strlen(dest);
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';
    return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: integer less than, equal to, or greater than zero if s1 is found,
 *         to be less than, to match, or be greater than s2 respectively
 */
int _strcmp(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] && s2[i]; i++)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed to by dest.
 * @dest: The buffer to copy the string to.
 * @src: The string to be copied.
 *
 * Return: The pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: the string to find the length of
 *
 *Return: the length of the string
 */
int _strlen(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        /* empty body */
    }

    return (i);
}