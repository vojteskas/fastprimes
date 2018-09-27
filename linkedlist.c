node_t * newnode(int val){						
	node_t * new = malloc(sizeof(node_t));
	
	if (new == NULL){
		printf("Chyba tvoreni nove casti linked listu. Vracim NULL!");
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
}

void freelist(node_t * head){
	node_t * iterator = head->next;
	free(head);
	for(node_t * current = iterator; iterator != NULL; current = current->next){
		iterator = current->next;
		free(current);
	}
}

void printlist(node_t * head){
	if(head == NULL){
		printf("Pointing to null, invalid list to print. Exiting!\n");
		return;
	}
		
	printf("Printing linked list:\n");
	for(;head->next != NULL; head = head->next){
		printf("%d\n", head->value);
	}
	return;
}
