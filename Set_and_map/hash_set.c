#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD 10

static int size = 0;
static int bucket_size = 10;

typedef struct node {
    int value;
    struct node* next;
}node;

typedef struct table {
    node** list;
}table;

table* traverse(table* t);
int hashcode(int value)
{
    return value%bucket_size;
}


table* createTable(int size)
{
    table* t = (table*)malloc(sizeof(table));
    t->list = (node **)malloc(sizeof(node) * bucket_size);
    for (int i = 0; i < bucket_size; i++) {
        t->list[i] = NULL;
    }
    return t;
}

table* rehash(table* t)
{
    printf("%s\n",__func__);
    bucket_size = 2 * bucket_size;
    table* newbucket = createTable(bucket_size);
    for ( int i = 0; i < bucket_size/2; i++ ) {
        node* p = t->list[i];
        while (p) {
            int newhash = hashcode(p->value);
            node* q = (node *)malloc(sizeof(node));
            q->value = p ->value;
            q->next = newbucket->list[newhash];
            newbucket->list[newhash] = q;
            p = p->next;
        }
    }
    //free(t);
    return newbucket;
}
void add(table* t, int value)
{  
    if ( (size / bucket_size) > THRESHOLD ){ 
         t = rehash(t);
         traverse(t);
    }
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
    size++;
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
   printf("Total Element: %d\n",size);
   for (i = 0; i < bucket_size; i++)
   {    
        node* p = t->list[i];
        if (!p) {
            printf("------\n");
        }
        else {
            while(p){
                printf("(%d)\t",p->value);
                p = p->next;
            }
            printf("\n");
        }
   }
}
int main()
{
    table* t = createTable(bucket_size);
    for (int i = 0; i < 280; i++ ) {
        add(t,rand());
    }
    traverse(t);
    return 0;
}
