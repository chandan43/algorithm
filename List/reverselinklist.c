#include <stdio.h>
#include <stdlib.h>
typedef int nt;
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
void reverselist()
{
    node_t* cur = head;
    node_t*  prev = NULL;
    node_t* bkp; 
    while (cur) {
        bkp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = bkp;
    }
    head = prev;
}
void swap(node_t** p1, node_t** p2)
{
    *p1 = (node_t*)((nt)*p1 ^ (nt)*p2);
    *p2 = (node_t*)((nt)*p1 ^ (nt)*p2);
    *p1 = (node_t*)((nt)*p1 ^ (nt)*p2);
}
void reverselist1()
{
    node_t* cur = head;
    node_t*  prev = NULL;
    while (cur != NULL) {
        swap(&cur->next,&prev);
        swap(&prev, &cur);
    }
   head = prev;
}
void reverselist2()
{
    node_t* cur = head;
    node_t*  prev = NULL;
    while (cur != NULL) {
        cur = (node_t*)((nt)cur ^ (nt)prev ^ (nt)cur->next ^ (nt)(cur->next = prev) ^ (nt)(prev = cur));   
    }
   head = prev;
}
int main()
{
	int num = 0;
	printf("Enter Size of list\n");
	scanf("%d",&num);
	addlist(num);
        showlist();
        reverselist();
        showlist();
        reverselist1();
        showlist();
        int s = sizeoflist();
        printf("Size of list is %d\n",s);
	return 0;
}
