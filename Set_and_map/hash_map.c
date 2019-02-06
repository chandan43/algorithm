#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD 10

static int size = 0;
static int bucket_size = 10;

typedef struct node {
    int value;
    int key;
    int size;
    struct node* next;
}node;

typedef struct table {
    node** list;
}table;

table* traverse(table* t);
int hashcode(int key)
{
    return key%bucket_size;
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
   // printf("%d bucket_sized\n", bucket_size);
    table* newbucket = createTable(bucket_size);
    for ( int i = 0; i < bucket_size/2; i++ ) {
        printf("I = %d\n",i);
        node* p = t->list[i];
        while (p) {
            printf("bucket_sized :%d and key %d\n",bucket_size, p->key);
            int newhash = hashcode(p->key);
            node* q = (node *)malloc(sizeof(node));
            q->value = p ->value;
            q->key = p->key;
            q->next = newbucket->list[newhash];
            newbucket->list[newhash] = q;
            p = p->next;
        }
    }
    //free(t);
    return newbucket;
}
void add(table* t, int key, int value)
{  
    if ( (size / bucket_size) > THRESHOLD ){ 
         //traverse(t);
         t = rehash(t);
         traverse(t);
         //exit(1);
    }
    //printf("New : %d THRESHOLD: %d\n",size / bucket_size, THRESHOLD );
    int hashvalue  =  hashcode(key);
    node* list = t->list[hashvalue];
    node* newnode = (node *)malloc(sizeof(node));
    node* p = list;
    printf("%d bucket_sized : hashvalue %d \n", bucket_size,hashvalue);
    while (p) {
        if (p->key == key)
            return;
        p = p->next;
    }
    newnode->key = key;
    newnode->value = value;
    newnode->next = list;
    t->list[hashvalue] = newnode; 
    size++;
}
node* search(table* t, int key)
{   
   int hashvalue  =  hashcode(key);
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
   printf("Total Element: %d\n",size);
   for (i = 0; i < bucket_size; i++)
   {    
        node* p = t->list[i];
        if (!p) {
            printf("------\n");
        }
        else {
            while(p){
                printf("(%d %d)\t",p->key,p->value);
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
        add(t,rand(),rand());
    }
    traverse(t);
    return 0;
}
