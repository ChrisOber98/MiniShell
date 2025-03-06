#include "shell.h"

void run()
{
    char* line;
    char** args;
    int status;

    do
    {
        printf("> ");
        line = get_user_input();
        args = tokenize_input(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}

