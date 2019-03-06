#include <stdio.h>
#include <stdlib.h>

/*TC = O(n) SC = O(1)*/
int feb4(int n)
{
    int* mem = (int *)calloc(n, sizeof(int));
    int val1 = 1, val2 = 1;
    int temp = 0;
    for (int i = 3; i <= n; i++) { 
         temp = val1 + val2; 
         val1 = val2;
         val2 = temp;
    }
    return temp;
}
/*FIlling Dynamic array without Recursion Tought : TC = O(n) SC = O(n)*/
int feb3(int n)
{
    int* mem = (int *)calloc(n, sizeof(int));
    mem[1] = mem[2] = 1;
    for (int i = 3; i <= n; i++) 
        mem[i] = mem[i-1] + mem[i-2];

    return mem[n];
}
int auxfeb2(int n, int *mem)
{
    if (n <= 2)
        return 1;
    if (mem[n-1] != 0)
        return mem[n];
    int prev1 = auxfeb2(n-1,mem);
    int prev2 = auxfeb2(n-2,mem);
    mem[n] = prev1 + prev2;
    return mem[n];
}

/*FIlling Dynamic array with Recursion Tought : TC = O(n) SC = O(n)*/
int feb2(int n)
{
    int* mem = (int *)calloc(n, sizeof(int));
    int feb = auxfeb2(n, mem);
    return feb;
}
/*Recursion Tought : TC = O(2^n) SC = O(n)*/
int feb1(int n)
{
    if (n <= 2) 
        return 1;
    int prev1 = feb1(n-1); 
    int prev2 = feb1(n-2);
    return prev1 + prev2;
}
int main(int argc , char** argv)
{
    int n = atoi(argv[1]);
    int feb = feb4(n);
    //int feb = feb1(n);
    printf("Nth febonacci ele:: %d\n",feb);
    return 0;
}
