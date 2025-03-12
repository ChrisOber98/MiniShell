#include "shell.h"
#include "linked_list.h"

Node *history = NULL;
int history_count = 0;

void store_command(char* command)
{
	ll_push(&history, command);
	history_count += 1;
}

void write_history()
{
	FILE *file_pointer;
	file_pointer = fopen("history_list.txt", "w");
	if (file_pointer == NULL)
	{
			perror("Failed to open File.");
			exit(EXIT_FAILURE);
	}

	Node* cur = history;
	int count = 0;

	while (cur != NULL)
	{
		if (cur->next == NULL)
		{
			fprintf(file_pointer, "%d: %s", count, cur->data);
			count += 1;
			cur = cur->next;
		}
		else
		{
			fprintf(file_pointer, "%d: %s\n", count, cur->data);
			count += 1;
			cur = cur->next;
		}
	}

	fclose(file_pointer);
}

void read_history()
{
	int buff_size = BUFFER_SIZE;
    char* buffer = malloc(buff_size);

	FILE *file_pointer;
	file_pointer = fopen("history_list.txt", "r");
	if (file_pointer == NULL)
	{
			perror("Failed to open File.");
			exit(EXIT_FAILURE);
	}

	while(fgets(buffer, buff_size, file_pointer) != NULL)
	{
		buffer[strcspn(buffer, "\n")] = '\0';

		if (buffer[0] == '\n') continue;
		
		char * command = strchr(buffer, ' ');

		ll_push(&history, command + 1);
	}

	fclose(file_pointer);
}