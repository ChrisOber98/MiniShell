#include "shell.h"

void run()
{
    char* input = get_user_input();
    char** tokens = tokenize_input(input);

    int i = 0;

    while (tokens[i] != NULL)
    {
        printf("%s\n", tokens[i]);
        i += 1;
    }
}

