#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*TC : O(logn), SC: O(1)*/
int find_min1(int* arr, int size)
{
    int l = 0;
    int r = size -1;
    while (l < r) {
        int mid = l + (r - l)/2;
        if (arr[mid] > arr[r])
            l = mid +1;
        else 
            r = mid;
    }
    return arr[l];
}
/*TC : O(n), SC: O(1)*/
int find_min(int* arr, int size)
{
    int min = INT_MAX;

    for(int i =0; i < size; i++){
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
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
        arr[i] = i + 8;
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
    print_arr(arr, n);
    printf("Min Value in Array%d\n",find_min(arr,n));
    printf("Min Value in Array%d\n",find_min1(arr,n));
    return 0;
}
