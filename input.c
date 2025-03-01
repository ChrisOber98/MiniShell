#include "shell.h"

char* get_user_input()
{
    // Allocate memory for buffer
    char* buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL)
    {
        perror("Memory allocation failed.");        
        exit(1);
    }

    // Get input from stdin
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL)  // Use BUFFER_SIZE, not sizeof(buffer)
    {
        return buffer;
    }
    else
    {
        perror("Error reading input.");
        free(buffer);
        exit(1);
    }
}

char** tokenize_input(char* input)
{
    // Remove trailing newline
    input[strcspn(input, "\n")] = '\0';

    // Count number of tokens
    int i = 0, arg_count = 1;
    while (input[i] != '\0')
    {
        if (input[i] == ' ')
        {
            arg_count++;
        }
        i++;
    }

    // Allocate memory for token array (+1 for NULL terminator)
    char** tokens = malloc(sizeof(char*) * (arg_count + 1));
    if (tokens == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    // Tokenize input string
    i = 0;
    char* token = strtok(input, " ");
    while (token != NULL)
    {
        tokens[i] = malloc(strlen(token) + 1);
        if (tokens[i] == NULL)
        {
            perror("Memory allocation failed");

            // Free already allocated tokens
            for (int j = 0; j < i; j++)
            {
                free(tokens[j]);
            }
            free(tokens);
            exit(1);
        }
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, " ");
    }

    // Null-terminate the token array
    tokens[i] = NULL;
    
    return tokens;
}

