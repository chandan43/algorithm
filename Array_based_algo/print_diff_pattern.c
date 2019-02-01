#include <stdio.h>
#include <stdlib.h>

void swap(int *arg1, int *arg2)
{
    int temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}


int partition(int *arr, int start, int end)
{
    int i = start + 1;
    int pvot = arr[start];
    for (int j = start + 1; j <= end; j++) {
        if (arr[j] < pvot) { 
            swap(&arr[i], &arr[j]);
            i += 1;
        }
    }
    swap(&arr[start], &arr[i - 1]);
    return i -1;

}
int sort(int *arr,int start, int end)
{
    if (start < end) {
        int index = partition(arr,start,end);
        sort(arr,start,index-1);
        sort(arr,index+1,end);
    }
}

int find_min(int *arr, int arr_zize)
{
    int min = arr[1] - arr[0];
    int i;
    for(i=1; i < arr_zize-1; i++) {
        if ((arr[i+1] - arr[i]) < min) {
            min = arr[i+1] - arr[i];
         }
    }
    return min;

}
/*TC : O(nlogn) SC: O(1)*/
void print_mindiff_pair(int *arr, int arr_zize, int min)
{
    int i;
    for(i=0; i < arr_zize-1; i++) {
        if ((arr[i+1] - arr[i]) == min)
            printf("(%d %d)\n",arr[i],arr[i+1]);
    }
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
        arr[i] = 100 - i;
    }
    arr[size-2] = 5;
    arr[size-1] = i+10;
}

int main()
{
    int i =0,n;
    scanf("%d",&n);
    int *arr = (int *)malloc(sizeof(int) * n);
    input(arr, n);
    sort(arr,0,n-1);
    //print_arr(arr, n);
    int mid = find_min(arr,n);
    //printf("%d\n",x);
    print_mindiff_pair(arr, n, mid);
    return 0;
}


