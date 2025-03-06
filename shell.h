#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#define BUFFER_SIZE 1024
#define TOK_SIZE 64
#define TOK_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// ----- input.c -----
char* get_user_input();
char** tokenize_input(char* input);

// ----- executor.c -----
int launch(char **args);
int execute(char ** args);

// ----- builtins.c -----
int cd(char **args);
int help();
int minishell_exit();
int num_builtins();

extern char *builtin_str[];
extern int (*builtin_func[])(char **);

// ----- mini_shell.c -----
void run();

#endif // MINI_SHELL_H