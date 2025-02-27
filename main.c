#include "mini_shell.h"
#include <stdio.h>

int main()
{
    char* string = prompt_user();

    printf("%s\n", string);

    return 0;
}