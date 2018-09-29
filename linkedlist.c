#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node * next;
}node_t;

node_t * newnode(int val){						
	node_t * new = malloc(sizeof(node_t));
	
	if (new == NULL){
		fprintf(stderr, "Cannot allocate memory. Returning NULL!");
		return NULL;
	}
	new->value = val;
	new->next = NULL;
	
	return new;
}

void append(node_t * current, int val){	
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = newnode(val);
	
	if(current->next == NULL){
		fprintf(stderr, "Cannot append! Exiting!\n");
		exit(3);
	}
}

void freelist(node_t * head){
	while(head != NULL){
		node_t * iterator = head->next;
		free(head);
		head = iterator;
	}
}

void printlist(node_t * head){
	if(head == NULL){
		fprintf(stderr, "Pointing to null, invalid list to print.\n");
		return;
	}
	
	fprintf(stderr, "Printing linked list:\n");
	for(;head->next != NULL; head = head->next){
		printf("%d\n", head->value);
	}
}
