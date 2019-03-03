#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
        int front, tail;
        int size;
        int* Que;
public:
        Queue(int size)
        {
            front = tail = -1;
            this->size = size;
            Que = new int [size];
        }
        void Qinsert(int data);
        int Qdel();
        void Qdisplay();
};
/*Enqueue*/
void Queue:: Qinsert(int data)
{
    /*Is Full*/
    if ((front == 0 && tail == size -1) ) {//|| (tail == ((front-1)%(size-1))) ){
        cout << "Queue is full\n";
        return;
    } else if (tail == -1) { /*First Element*/
        tail = front = 0;
        Que[tail] = data;
    } else if (tail == size -1 && front != -1) { /*Last element*/
        tail = 0;
        Que[tail] = data; 
    }else { /*Normal*/
        Que[++tail] = data;
    }
}
/*Dqueue*/
int Queue:: Qdel()
{
    /*Is Empty*/
    int data;
    if (front == -1){ 
        cout << "Queue is Empty\n";
        return INT_MIN;
    }else if (front == tail) { // Only one element
        cout << front << "###"<<tail << endl;
        data =  Que[front];
        front = tail = -1;
    } else if (front == size -1) { // last ele
        data =  Que[front];
        front = 0;
    } else {
        data =  Que[front++];
    }
    return data;
}

void Queue:: Qdisplay()
{
    if (front == -1) {
        cout << "Queue is empty\n";
    } 
    
    if (tail >= front) {
        for (int i = front; i <= tail; i++) {
            cout << Que[i%size]<< "\t";
        }
        cout << "\n";
    }else  {
        for (int i = front; i < size; i++) {
            cout << Que[i]<< "\t";
        }
        for (int i = 0; i <= tail; i++) {
            cout << Que[i]<< "\t";
        }
        cout << "\n";
    }
}
int main()
{
    Queue q(5);
    q.Qinsert(10);
    q.Qinsert(20);
    q.Qinsert(30);
    q.Qinsert(40);
    q.Qinsert(50);
    q.Qdel();
    q.Qinsert(50);
    q.Qdel();
    q.Qdel();
    q.Qdisplay();
    return 0;
}
