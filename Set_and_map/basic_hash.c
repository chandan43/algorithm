#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int key;
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
int hashcode(int key, table* t)
{
    //return key%t->size;
    return key%10;
}

void add(table* t, int key, int value)
{   
    int hashvalue  =  hashcode(key, t);
    node* list = t->list[hashvalue];
    node* newnode = (node *)malloc(sizeof(node));
    node* p = list;
    while (p) {
        if (p->key == key)
            return;
        p = p->next;
    }
    printf("%d",key);
    newnode->key = key;
    newnode->value = value;
    newnode->next = list;
    t->list[hashvalue] = newnode;   
}
node* search(table* t, int key)
{   
   int hashvalue  =  hashcode(key, t);
   node* list = t->list[hashvalue];
   node* p = list;
   while (p) {
        if (p->key == key)
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
            printf("(%d %d)\t",p->key,p->value);
            p = p->next;
        }
        printf("\n");
   }
}
int main()
{
    table* t = createTable(128);
    add(t,1,2);
    add(t,2,2);
    add(t,3,2);
    add(t,4,2);
    add(t,5,2);
    add(t,6,2);
    add(t,7,2);
    add(t,8,2);
    add(t,18,2);
    add(t,28,2);
    add(t,38,2);
    add(t,48,2);
    add(t,58,2);
    add(t,68,2);
    traverse(t);
    return 0;
}
