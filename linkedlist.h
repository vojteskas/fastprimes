typedef struct node{
	int value;
	struct node * next;
}node_t;

node_t * newnode();
int append(node_t * current, int val);
void freelist(node_t * current);
void printlist(node_t * head);
