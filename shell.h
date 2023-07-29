#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/* standard libraries */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* modes.c functions */
void interact_mode(void);
void non_interact_mode(void);

/* read.c functions */
char *read_input_interact(void);
char *read_input_non_interact(void);

/* tokenize.c function */
char **split_input(char *input);

/* execute.c functions */
int check_type_cmd(char **args);
char *locate_path(char *cmd);
int execute_cmd(char **args);

/* builtins.c functions */
int __exit(char **args);
int __env(char **args);
int __cd(char **args);

/* helpers.c functions */
char *_strncat(char *dest, const char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif /* MAIN_H */


