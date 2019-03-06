#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class BTnode {
public:
    BTnode* left;
    BTnode* right;
    int data;
    BTnode(int data){
        this->data = data;
    }
    BTnode(){
    }
    BTnode* NewBT(int );
    BTnode* add(BTnode* , int );
    void auxDisplay(BTnode* , int , string );
    int* createUniqueBT(int );
    void displayBT(BTnode*);
};

BTnode* BTnode:: NewBT(int data)
{
    BTnode* node = new BTnode(data);
    return node;
}
BTnode* BTnode:: add(BTnode* root, int data)
{
    if (!root)  
        return NewBT(data);
    BTnode* cur = root; 
    BTnode* parent = NULL;
    while(cur) {
        parent = cur;
        if(rand()%2 == 0) {
            if (!cur->left) {
                parent->left = NewBT(data);
                break;
            }
            cur = cur->left;
        }else {
            if (!cur->left) {
                parent->right = NewBT(data);
                break;
            }
            cur = cur->right;
        }
    
    }
    return root;
}
void BTnode:: auxDisplay(BTnode* root, int nspace, string type)
{
    if(!root)
        return;
    for(int i = 0; i < nspace; i++)
        cout << ' ';
    cout << root->data << "( " << type << " )" << endl;
    auxDisplay(root->left, nspace+4, "L");
    auxDisplay(root->right, nspace+4, "R");
}
void BTnode:: displayBT(BTnode* root)
{
    auxDisplay(root, 0, "root");    
}

int* BTnode:: createUniqueBT(int n)
{
    BTnode* root = NULL;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        int data = rand() % 100;
        root = add(root, data);
        arr[i] = data;
    }
    displayBT(root);
    return arr;
}
int main()
{
    int n;
    cin >> n ;
    BTnode bst;
    int *arr = bst.createUniqueBT(n);
    return 0;
}
