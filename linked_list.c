#include "linked_list.h"

Node* ll_create_node(char * val)
{
	Node* new_node = (Node*)malloc(sizeof(Node*));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	new_node->data = val;
	new_node->next = NULL;

	return new_node;
}

void ll_display(Node *head)
{
	Node* cur = head;

	while(cur != NULL)
	{
		printf("%s -> ", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}

void ll_push(Node **head, char * val)
{
	Node* new_node = ll_create_node(val);
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	new_node->next = *head;
	*head = new_node;
}