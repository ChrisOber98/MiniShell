#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#define BUFFER_SIZE 1024
#define TOK_SIZE 64
#define TOK_DELIM " \t\r\n\a"
#define HISTORY_SIZE 100

#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>

// ---- history.c -----
extern Node *history;
extern int history_count;

void store_command(char * command);
void write_history();
void read_history();

// ----- input.c -----
char* get_user_input();
char** tokenize_input(char* input);
int validate_command(const char *str);

// ----- executor.c -----
int launch(char **args);
int execute(char ** args);

// ----- builtins.c -----
int cd(char **args);
int help();
int minishell_exit();
int minishell_history();
int num_builtins();

extern char *builtin_str[];
extern int (*builtin_func[])(char **);

// ----- mini_shell.c -----
void run();

#endif // MINI_SHELL_H