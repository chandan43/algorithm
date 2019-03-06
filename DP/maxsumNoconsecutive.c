#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

void auxsum1(int* input, int size,int csum, int* gmax)
{
    if (size <= 0){
        if (csum > *gmax)
            *gmax = csum;
         return;
    }
    auxsum1(input,size-2,csum + input[size-1],gmax);
    auxsum1(input,size-1,csum,gmax);
}
int maxsum1(int* input, int size)
{
     int gmax = 0;
     int csum = 0;
     auxsum1(input,size,csum,&gmax);
     return gmax;
}

/*TC : O(2^n) SC : O(n)*/
int maxsum2(int* input, int size)
{
    if(size <= 0)
        return 0;
    int inclusive = maxsum2(input, size-2) + input[size-1];
    int exclusive = maxsum2(input, size-1);
    return MAX(inclusive,exclusive);
}
int auxsum3(int* input, int size,int* mem)
{
    if(size <= 0)
        return 0;
    if (mem[size] != 0)
        return mem[size];
    int inclusive = maxsum2(input, size-2) + input[size-1];
    int exclusive = maxsum2(input, size-1);
    mem[size] = MAX(inclusive,exclusive);
    return mem[size];
}
/*TC : O(2^n) SC : O(n)*/
int maxsum3(int* input, int size)
{
     int* mem = (int *)calloc(size+1, sizeof(int));
     int data = auxsum3(input, size, mem);
     return data;
}
/*TC : O(n) SC : O(n)*/
int auxsum4(int* input, int size)
{
    int* mem = (int *)calloc(size+1, sizeof(int));
    mem[0] = 0;
    mem[1] = MAX(0,input[0]);
    for (int i = 0; i <= size; i++) {
        int inclusive = mem[i-2] + input[i-1];
        int exclusive = mem[i-1];
        mem[i] = MAX(inclusive,exclusive);
    }
    return mem[size];
}
int main(int argv, char* argc[])
{
    int size = atoi(argc[1]);
    int* input = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        *(input + i) = rand()%10;
    }
    for (int i = 0; i < size; i++) {
        printf("%d\t",*(input + i));
    }
    printf("\n");
    //int msum = maxsum2(input, size);
    //int msum = maxsum3(input, size);
    int msum = maxsum4(input, size);
    printf("MaxSize = %d\n",msum);
    msum = maxsum1(input, size);
    printf("MaxSize = %d\n",msum);
    return 0;
}
