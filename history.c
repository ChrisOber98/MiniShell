#include "shell.h"
#include "linked_list.h"

Node *history = NULL;
int history_count = 0;

void store_command(char* command)
{
	ll_push(&history, command);
	ll_display(history);
	history_count += 1;
}