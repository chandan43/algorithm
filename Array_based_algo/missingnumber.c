#include <stdio.h>
#include <stdlib.h>

void swap(int *str1, int *str2) 
{
    int temp = *str2;
    *str2 = *str1;
    *str1 = temp;
}

int partition(int* arr, int start, int end)
{
    int i = start + 1;
    int pvot = arr[start];
    for (int j = start + 1; j <= end; j++) {
        if (arr[j] < pvot) {
            swap(&arr[i], &arr[j]);
            i += 1;
        }
    }
    swap(&arr[start], &arr[i-1]);
    return i-1;
}

void sort(int* arr, int start, int end)
{
    int pos;
    if (start < end) {
        pos = partition(arr,start,end);
        sort(arr,start,pos-1);
        sort(arr,pos+1,end);
    }
}

/* TC = O(n), SC = O(1) */
int find_missing3(int* arr, int size) 
{
    int i,res=0;
    for(i = 0; i < size; i++) {
        res ^= i^arr[i];
    }
exit:
    return res^i;
}
/* TC = O(nlogn), SC = O(1) */
int find_missing2(int* arr, int size) 
{
    int i;
    sort(arr,0,size-1);
    for(i = 0; i < size; i++) {
        if(arr[i] != i)
            goto exit;
    }
exit:
    return i;
}
/* TC = O(n^2),SC = O(1) */
int find_missing1(int* arr, int size) 
{
    int i, j, temp = -1;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if (arr[j] == i)
                temp = i;
        }
        if (temp != i)
            goto exit;
    }
exit:
    return i;
}

void print_arr(int *arr, int size)
{
    for(int i=0; i < size; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");

}

void input(int *arr, int size)
{   int i;
    for(i = 0; i < size-2; i++) {
        arr[i] = i;
    }
    arr[size-2] = 5;
    arr[size-1] = i+1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(sizeof(int)*n);
    input(arr, n);
    sort(arr,0,n-1);
    print_arr(arr, n);
    //printf("Missing number is %d\n",find_missing1(arr, n));
    //printf("Missing number is %d\n",find_missing2(arr, n));
    printf("Missing number is %d\n",find_missing3(arr, n));
    return 0;
}
