#include "shell.h"

void run()
{
    char* line;
    char** args;
    int status;

    read_history();

    do
    {
        printf("Minishell> ");
        line = get_user_input();
        if (validate_command(line))
        {
            store_command(line);
        }
        args = tokenize_input(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}

