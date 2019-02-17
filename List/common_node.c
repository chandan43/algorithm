#include <stdio.h>
#include <stdlib.h>

static int size = 0;
typedef struct node {
	int data;
	struct node* next;
}node_t;

node_t* head = NULL;
void addele(int data)
{
	node_t* p = head;
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->next = head;
	head = temp;
        size += 1;
}

void showlist()
{
	node_t* p = head;
	while(p) {
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

void addlist(int num)
{
	for (int i = 1; i <= num; i++) 
		addele(i); 
}

int sizeoflist()
{
    return size;
}
int main()
{
	int num = 0;
	printf("Enter Size of list\n");
	scanf("%d",&num);
	addlist(num);
        showlist();
        int s = sizeoflist();
        printf("Size of list is %d\n",s);
	return 0;
}
