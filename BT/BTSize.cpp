#include <iostream>
#include <string>
#include <cstdlib>
#include <queue> 
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
    int BTSize1(BTnode*);
    int BTSize2(BTnode*);
    int BTSize3(BTnode*);
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
            if (!cur->right) {
                parent->right = NewBT(data);
                break;
            }
            cur = cur->right;
        }
    
    }
    return root;
}
/* TC:O(n) SC:O(n) */
int BTnode:: BTSize1(BTnode* root)
{
    if (!root)  
        return 0;
    
    if (root->left == NULL && root->right == NULL)
        return 1;
    int ls = BTSize1(root->left);
    int rs = BTSize1(root->right);
    return ls + rs + 1;
}
/* TC:O(n) SC:O(n) */
int BTnode:: BTSize2(BTnode* root)
{
    queue <BTnode*> que;
    int count = 0;
    if (root)
        que.push(root);
    while(!que.empty()) {
        BTnode* temp = que.front();
        que.pop();
        count++;
        if (temp->left)
            que.push(temp->left);
        if (temp->right)
            que.push(temp->right);
    }
    return count;
}
/* TC:O(n) SC:O(1) */
int BTnode:: BTSize3(BTnode* root)
{
    int count = 0;
    BTnode* temp;
    BTnode* cur = root;
    while(cur) {
        if (!cur->left) {
            cur = cur->right;
            count++;
        } else {
            temp = cur->left;
            while(temp->right && temp->right != cur)
                temp = temp->right;
             if (!temp->right) {
                temp->right = cur;
                cur = cur->left;
                count++;
             }else {
                temp->right = NULL;
                cur = cur->right;
             }
        }
    }
    return count;
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
        int data = rand() % 10;
        root = add(root, data);
        arr[i] = data;
    }
    displayBT(root);
    cout << "BTSize1:: " << BTSize1(root)<<endl;
    cout << "BTSize2:: " << BTSize2(root)<<endl;
    cout << "BTSize3:: " << BTSize3(root)<<endl;
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
