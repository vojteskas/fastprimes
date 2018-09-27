typedef struct node{
	int value;
	struct node * next;
}node_t;

node_t * newnode();
void append(node_t * current, int val);
void freelist(node_t * head);
void printlist(node_t * head);
