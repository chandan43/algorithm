#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class BSTnode {
public:
    BSTnode* left;
    BSTnode* right;
    int data;
    int local_rank;
    BSTnode(int data) {
        this->data = data;
        left = right = NULL;
        local_rank = 1;
    } 
    BSTnode(int data,int local_rank) {
        this->data = data;
        left = right = NULL;
        this->local_rank = local_rank;
    } 
    BSTnode() {
    }
    BSTnode* NewBST(int );
    BSTnode* NewBST(int, int);
    BSTnode* add(BSTnode* , int );
    void auxDisplay(BSTnode* , int , string );
    int* createUniqueBST(int );
    void displayBST(BSTnode*);
    void searchinBST(BSTnode*, int);
    BSTnode* auxBBST(int*, int, int );
    void createBalanceBST(int *, int size);
};
void BSTnode:: searchinBST(BSTnode* root, int data)
{
    while(root) {
        if(root->data == data) {
            cout << "Data found: " << data << endl;
            return;
        }
        if(root->data > data) 
            root = root->left;
        else 
            root = root->right;
    }
    cout << "Data not found::" << endl;
}

BSTnode* BSTnode:: NewBST(int data)
{
    BSTnode* node = new BSTnode(data);
    return node;
}
BSTnode* BSTnode:: NewBST(int data,int local_rank)
{
    BSTnode* node = new BSTnode(data, local_rank);
    return node;
}
BSTnode* BSTnode:: add(BSTnode* root, int data)
{
    if (!root)  
        return NewBST(data);
   if (root->data == data)
        return root;
   if (root->data > data) {
        ++root->local_rank;
        root->left = add(root->left,data);
    }
    else if (root->data < data) {
        root->right = add(root->right,data);
    }
    return root;
}
void BSTnode:: auxDisplay(BSTnode* root, int nspace, string type)
{
    if(!root)
        return;
    for(int i = 0; i < nspace; i++)
        cout << ' ';
    cout << root->data << "( " << type <<"\t"<< root->local_rank << " )" << endl;
    auxDisplay(root->left, nspace+4, "L");
    auxDisplay(root->right, nspace+4, "R");
}
void BSTnode:: displayBST(BSTnode* root)
{
    auxDisplay(root, 0, "root");    
}

int* BSTnode:: createUniqueBST(int n)
{
    BSTnode* root = NULL;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        int data = rand() % 100;
        root = add(root, data);
        arr[i] = data;
    }
    displayBST(root);
    searchinBST(root, 83);
    return arr;
}
BSTnode* BSTnode:: auxBBST(int* arr, int l, int r)
{
    if (l > r)
        return NULL;
    int m = l + (r - l)/2;
    BSTnode* temp = NewBST(arr[m],m-l+1);
    temp->left = auxBBST(arr, l, m-1);
    temp->right = auxBBST(arr, m+1, r);
    return temp;
}
void BSTnode:: createBalanceBST(int *arr, int size)
{
    BSTnode* root = auxBBST(arr, 0, size-1);
    displayBST(root);
}
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int parttion(int *arr, int start, int end)
{
	int i = start + 1;
	int pvot = arr[start];
	for (int j = start+1; j <= end; j++) {
		if (arr[j] < pvot) {
			swap(&arr[i],&arr[j]);
			i += 1;
		}
	}
	swap(&arr[start], &arr[i - 1]);
	return i - 1;

}
/*TC : O(n)*/
void sort(int *arr, int start, int end)
{
	if (start < end) {
		int pvot_pos = parttion(arr, start, end);
		sort(arr, start,  pvot_pos - 1);
		sort(arr, pvot_pos + 1, end);
	}
}

int main()
{
    int n;
    cin >> n ;
    BSTnode bst;
    int *arr = bst.createUniqueBST(n);
    sort(arr, 0, n-1);
    bst.createBalanceBST(arr,n);
    return 0;
}
