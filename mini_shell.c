#include "mini_shell.h"

char* prompt_user()
{
    // Malloc Space for input buffer
    char* input = malloc(BUFFER_SIZE);
    if (input == NULL)
    {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Print Prompt
    printf("$ ");

    // Get Input
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) 
    {
        // Handle EOF or error
        free(input);
        return NULL;  
    }

    // Remove the newline character, if present
    input[strcspn(input, "\n")] = 0;

    return input;
}