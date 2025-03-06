#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#define BUFFER_SIZE 1024
#define TOK_SIZE 64
#define TOK_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----- input.c -----
char* get_user_input();
char** tokenize_input(char* input);

// ----- executor.c -----


// ----- mini_shell.c -----
void run();

#endif // MINI_SHELL_H