#include <iostream>
#include <time.h>
#include <sys/time.h>
using namespace std;

class shuffle {
public:
    int random(int n) 
    {
        return rand() % n;
    }
    void display(int* input, int len)
    {
        for(int i = 0; i < len; i++ ) {
            cout << input[i] << "\t";
        }
        cout << endl;
    }
    void swap(int *num1, int *num2)
    {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
    }
    /*TC: O(n) SC: O(1) N! combination*/
    void shuffle1(int* input, int size)
    {
        for(int i = 0; i < size; i++) {
            int temp = random(size - i);
            swap(&input[i],&input[temp]);
        }
    }
    /*TC: O(n) SC: O(1)* N^N combination*/
    void shuffle2(int* input, int size)
    {
        for(int i = 0; i < size; i++) {
            int temp = random(size);
            swap(&input[i],&input[temp]);
        }
    }
};

int main()
{
    int n = 10;
    int size = 7;
    int input[size] = {6, 9, 5, 1, 3, 2, 4};
    shuffle s1;
    s1.display(input,size);
    s1.shuffle1(input,size);
    s1.display(input,size);
    s1.shuffle2(input,size);
    s1.display(input,size);
    return 0;
}
