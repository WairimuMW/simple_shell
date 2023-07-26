#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#define MAX_PATH_LENGTH 1024
#define INITIAL_BUFFER_SIZE 64
#include <string.h>
#include <sys/wait.h>

int main(void);
char *get_location(char *command);
void execmd(char **args);
void print_environment(void);
char *_strncat(char *dest, const char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void parseInput(char *inputLine, char ***args, int *numTokens);
char *splitInput(char *inputLine);



#endif /* MAIN_H */


