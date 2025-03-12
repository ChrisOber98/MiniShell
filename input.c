#include "shell.h"

char* get_user_input()
{
    // Allocate memory for buffer
    int buff_size = BUFFER_SIZE;
    int position = 0;
    char* buffer = malloc(BUFFER_SIZE);
    int c;


    if (buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");        
        exit(EXIT_FAILURE);
    }

    // Get input from stdin
    while(1)
    {
        c = getchar();

        // Check for end of input and handle
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        // Check for reallcation
        if (position >= buff_size)
        {
            buff_size += BUFFER_SIZE;
            buffer = realloc(buffer, buff_size);
            if (buffer == NULL)
            {
                fprintf(stderr, "Memory allocation failed.\n");        
                exit(EXIT_FAILURE);
            }
        }
    }
}

int validate_command(const char *str)
{
    // Iterate over each character in the string
    while (*str != '\0') 
    {
        if (!isspace(*str)) 
        {
            return 1; // If a non-space character is found, return false
        }
        str++;
    }
    return 0; // If the string only contains spaces, return true   
}

char** tokenize_input(char* input)
{
    int buff_size = TOK_SIZE;
    int position = 0;

    char **tokens = malloc(buff_size * sizeof(char*));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Begin Parsing of inputs
    token = strtok(input, TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        // Check for Resize
        if (position >= buff_size)
        {
            buff_size += TOK_SIZE;
            tokens = realloc(tokens, buff_size * sizeof(char*));
            if (tokens == NULL)
            {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    // Append NULL to end of tokens list
    tokens[position] = NULL;
    return tokens;
}

