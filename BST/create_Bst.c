#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
}bstNode;

bstNode* CreateNode(int data)
{
    bstNode* newNode = (bstNode*)malloc(sizeof(bstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void display(bstNode* root)
{
    if (root) {
        display(root->left);
        printf("%d\t",root->data);
        display(root->right);
    }
}
bstNode* insert(bstNode* node, int data)
{
    if(!node)
        return CreateNode(data);
    
    if(data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}
int search(bstNode* root, int key)
{
    while (root) {
        if (root->data == key)
            return 1;
        if (root->data > key)
            root = root->left;
        else 
            root = root->right;
    }
    return 0;
}
int main()
{
    bstNode* root = NULL;
    for (int i = 10; i < 100; i = i+10) {
        root = insert(root, i);
    }
    display(root);
    printf("\n");
    int r = search(root, 0);
    if (r) {
        printf("Element Found\n");
    }else {
        printf("Element not Found\n");
    }
    return 0;
}


