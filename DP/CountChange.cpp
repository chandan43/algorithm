#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define MIN(a, b)  (a > b) ? (b) : (a) 

class CountChange {
private:
    void auxcount1(int* in, int i, int j, int size, int cum, int* gmin)
    {
        if (j == 0) {
            if ( cum < *gmin)
                *gmin = cum;
            return;
        }
        if (size == i || in[i] > j)
            return;
         auxcount1(in, i , j - in[i], size, cum +1,  gmin);
         auxcount1(in, i + 1 , j, size, cum, gmin);
    }
    int auxcount2(int* in, int i, int j, int size)
    {
        if (j == 0)
            return 0;
        if (size == i || in[i] > j)
            return INT_MAX;
         int inclusive = auxcount2(in, i , j - in[i], size);
         int exclusive = auxcount2(in, i + 1 , j, size);
         return MIN(inclusive == INT_MAX ? inclusive : inclusive + 1, exclusive);
    }
    int auxcount3(int* in, int i, int j, int size, int** mem)
    {
        if (j == 0)
            return 0;
        if (size == i || in[i] > j)
            return INT_MAX;
         if(mem[i][j] != 0)
            return mem[i][j];
         int inclusive = auxcount2(in, i , j - in[i], size);
         int exclusive = auxcount2(in, i + 1 , j, size);
         mem[i][j] = MIN(inclusive == INT_MAX ? inclusive : inclusive + 1, exclusive);
         return mem[i][j];
    }
public:
    /*TC : O(2^w) SC = O(w)*/
    int count1(int* input, int sum,int size) 
    {
        int gmin = INT_MAX;
        auxcount1(input, 0 ,sum, size, 0 , &gmin);
        return gmin;
    }
    /*TC : O(2^w) SC = O(w)*/
    int count2(int* input, int sum,int size) 
    {
        int totalcount =  auxcount2(input, 0 ,sum, size);
        return totalcount;
    }
    /*TC : O(nw) SC = O(nw)*/
    int count3(int* input, int sum,int size) 
    {
        int** mem = new int*[size];
        for(int i = 0; i < sum; i++)
              mem[i] = new int[sum];
        int totalcount =  auxcount3(input, 0 ,sum, size, mem);
        return totalcount;
    }
    /*TC : O(nw) SC = O(nw)*/
    int count4(int* in,int sum, int size)
    {
        int** mem = new int*[size+1];
        for(int i = 0; i <= sum; i++)
              mem[i] = new int[sum];
        for (int k = 0; k <= size; k++)
            mem[k][0] = 0;
        for (int k = 1; k <= sum; k++)
            mem[size][k] = INT_MAX;
        for(int i = size-1; i >= 0; --i) {
            for(int j = 1; j <= sum; ++j) {
                if (in[i] > j)
                    mem[i][j] = INT_MAX;
                else {
                    int inclusive = mem[i][ j - in[i]];
                    int exclusive = mem[i+1][j];
                    mem[i][j] = MIN(inclusive == INT_MAX ? inclusive : inclusive + 1, exclusive);
                }
            }
        }
        return mem[0][sum];
    }

};

int main()
{
    int input[3] = {1,3,4};
    CountChange c;
    cout << "Count :" << c.count2(input,6,2) << endl;
    cout << "Count :" << c.count1(input,6,2) << endl;
    cout << "Count :" << c.count3(input,6,2) << endl;
    cout << "Count :" << c.count4(input,6,2) << endl;
    return 0;
}
