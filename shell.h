#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/* standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/* modes.c functions */
void interact_mode(void);
void non_interact_mode(void);

/* prompt.c functions */
void print_prompt(void);

/* read.c functions */
char *read_input_interact(void);
char *read_input_non_interact(void);

/* tokenize.c function */
char **split_input(char *input);

/* execute.c functions */
int map_cmd(char **args);
char *search_path(char *cmd);
int execute_cmd(char **args);

/* builtins.c functions */
int __exit(char **args);
int __env(char **args);
int __cd(char **args);
#endif
