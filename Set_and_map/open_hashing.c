#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct node {
	int key;
	int data;
	struct node* next; 
}node;

#if 0
typedef struct arrayItem {
	struct node* head;
	struct node* tail;
}item;
#endif

node* hashArray[SIZE];
node* dummyItem;
node* item;

int hashfunction(int key)
{
	return key % SIZE;
}
void insert(int key, int data)
{
	item = (node*)malloc(sizeof(node));
	item->key = key;
	item->data = data;
	item->next = NULL;

	int hashvalue = hashfunction(key);	
	if ( hashArray[hashvalue] == NULL) {
		hashArray[hashvalue] = item;
	} else {
		node *p = hashArray[hashvalue];
		while (p->next) {
			p = p->next;
		}
		p->next = item;
	}
}

void display()
{
	int i = 0; 
	for ( i = 0; i < SIZE; i++ ) {
		int hashvalue = hashfunction(i);
		if (hashArray[hashvalue] != NULL) {
			node *p = hashArray[hashvalue];
			while(p) {
				printf("(%d %d)\t",p->key,p->data);
				p = p->next;
			}
			printf("\n");
		} else {
			printf("----------\n");
		}
	}
}


int main(int argc, char ** argv)
{
	insert(1, 20);
	insert(11, 30);
	insert(21, 40);
	insert(31, 50);
	insert(41, 60);
	insert(5, 10);
	insert(8, 21);
	insert(9, 23);
	insert(22, 29);
	insert(33, 25);
	insert(44, 41);
	insert(99, 54);
	insert(88, 99);
	insert(12, 91);
	insert(16, 89);
	insert(19, 27);

	display();
	
	return 0;

}
