#include <iostream>
#include <string>
#include <iterator> 
#include <map> 
#include<bits/stdc++.h>
using namespace std;

class FindKthmin {
public:
    set<int> bkpset; 
    set<int>::iterator itr;
    /*TC : O(n*k)  SC: (1)*/
    int FindKthminval1(int* input, int len, int k)
    {
        int in;
        int min;
        for (int j = 0; j < k; j++) {
            min = input[0];
            in = 0;
            for (int i = 0; i < len; i++) {
                if (input[i] < min) {
                    min = input[i];
                    in = i;
                }
            }
            input[in]= INT_MAX;
        }
        return min;
    }
    void swap(int *num1, int *num2)
    {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
    }   
    int partition(int* input, int start, int end)
    {
        int j = start + 1;
        int pvot = input[start];
        for (int i = start + 1; i <= end; i++){
            if  (input[i] < pvot) {
                 swap(&input[j], &input[i]);
                  j = j+1;
            }
        } 
        swap(&input[start],&input[j-1]);
        return j - 1;
    }
    void sort(int *arr, int start, int end)
    {
	if (start < end) {
		int pvot_pos = partition(arr, start, end);
		sort(arr, start,  pvot_pos - 1);
		sort(arr, pvot_pos + 1, end);
	}
    }
    /*TC : O(nlog)  SC: (1)*/
    int FindKthminval2(int* input, int len, int k)
    {
        sort(input, 0, len-1);
        return input[k-1];
    }
    /*TC : O(nlog)  SC: (n)*/
    int FindKthminval3(int* input, int len, int k)
    {
        for (int i = 0; i < len; i++) {
            bkpset.insert(input[i]);
        }
        itr = bkpset.begin();
        while(k-1) {
            itr++; 
            k--;
        }
        return *itr;
    }

};

int main()
{
    int size = 7;
    int k = 2;
    int input[size] = {6, 9, 5, 1, 3, 2, 4};
    FindKthmin kmin;
    cout << kmin.FindKthminval3(input, size, k) << endl;
    cout << kmin.FindKthminval2(input, size, k) << endl;
    cout << kmin.FindKthminval1(input, size, k) << endl;
    return 0;
}
