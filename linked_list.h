#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char* data;
	struct Node* next;
} Node;

Node* ll_create_node(char* val);

void ll_display(Node *head);

void ll_push(Node **head, char* val);

#endif // LINKED_LIST_H