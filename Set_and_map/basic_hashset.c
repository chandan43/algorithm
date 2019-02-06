#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
}node;

typedef struct table {
    int size;
    node** list;
}table;

table* createTable(int size)
{
    table* t = (table*)malloc(sizeof(table) * size);
    t->size = size;
    t->list = (node **)malloc(sizeof(node) * size);
    for (int i = 0; i < size; i++)
        t->list[i] = NULL;
    return t;
}
int hashcode(int value)
{
    //return value%t->size;
    return value%10;
}

void add(table* t, int value)
{   
    int hashvalue  =  hashcode(value);
    node* list = t->list[hashvalue];
    node* newnode = (node *)malloc(sizeof(node));
    node* p = list;
    while (p) {
        if (p->value == value)
            return;
        p = p->next;
    }
    newnode->value = value;
    newnode->next = list;
    t->list[hashvalue] = newnode;   
}
node* search(table* t, int value)
{   
   int hashvalue  =  hashcode(value);
   node* list = t->list[hashvalue];
   node* p = list;
   while (p) {
        if (p->value == value)
            return p;
        p = p->next;
   }
   return NULL;
}
table* traverse(table* t)
{
   int i;
   for (i = 0; i < t->size; i++)
   {    
        node* p = t->list[i];
        while(p){
            printf("(%d)\t",p->value);
            p = p->next;
        }
        printf("\n");
   }
}
int main()
{
    table* t = createTable(10);
    for (int i = 0; i < 100000; i++) {
        add(t, i+1);
    }
    traverse(t);
    return 0;
}
