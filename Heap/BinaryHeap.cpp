#include <iostream>
#include <cstdlib>
using namespace std;

class BinaryHeap {
private:
    int heapSize;
    int* heap;
    int capacity;
public:
    BinaryHeap(int capacity) {
        heapSize = 0;
        heap = new int [capacity + 1];
        this->capacity = capacity;
    }
    /*TC : O(1)*/
    int isFull() 
    {
        return heapSize == capacity;    
    }
    /*TC : O(1)*/
    int isEmpty()
    {
        return heapSize == 0;
    }
    int parent(int i)
    {
        return  (i-1)/2;   
    }  

    int kthChild(int i, int k) 
    {
        return 2*i + k; 
    }
    /*TC = O(logn)*/
    void add(int x) 
    {
        if (isFull()) {
            cout << "Heap is full" << endl;
            return;
        }
        heap[heapSize++] = x;
        heapifyUp(heapSize-1);
    }
    void heapifyUp(int i) 
    {
        int temp = heap[i];
        while(i > 0 && temp > heap[parent(i)]) {
            heap[i] == heap[parent(i)];
            i = parent(i);
        }
        heap[i] = temp;
    }
    /*TC = O(logn)*/
    int removent(int x)
    {
        if(isEmpty()) {
            cout << "Heap is Empty" << endl;
            return 0;
        }
        int bkp = heap[x];
        heap[x] = heap[heapSize-1];
        heapSize--;
        heapifyDown(x);
        return bkp;
    }
    void heapifyDown(int i)
    {
        int child;
        int temp = heap[i]
        while (kthChild(i, 1) < heapSize) {
            child = maxChild(i);
            if (temp < heap[child]);
                heap[i] = heap[child];
            else
                break;
            i = child;
        }
        heap[i] = temp;
    }
    int maxChild(int i) {
	int leftChild = kthChild(i, 1);
	int rightChild = kthChild(i, 2);
	return heap[leftChild]>heap[rightChild]?leftChild:rightChild;
    } 
    void printHeap()
    {
        for (int i = 0; i <= (capacity-1)/2; i++) {
                    cout << heap[i] << "(Root)" <<"\t"<< heap[2*i+1] << "(L)" << "\t" << heap[2*i+2] << ("R")<<"\n";
        }
    }
    void printHeap1(int i, int nspace) 
    {
        if (i == capacity - 1)
            return;
        for(int j = 0; j < nspace; j++)
            cout << ' ';
        if (i == 0)
            cout << heap[i] << "(Root)"<<"\n";
        else if (i % 2 == 0)
            cout << heap[i] << "(L)" <<"\n";
        else 
            cout << heap[i] << "(R)"<<"\n";
        printHeap1(i+1, nspace + 4);
    }
    void displayheap()
    {
        printHeap1(0, 0);    
    }    
};

int main(int argc, char *agrc[])
{
    int n = 10;
    BinaryHeap myheap(n);
    for(int i = 0; i < n; i++) {
        int data = rand() % 100;
        myheap.add(data);
    }
    //myheap.printHeap();
    myheap.displayheap();
}
