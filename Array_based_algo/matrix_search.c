#include <stdio.h>
#include <stdlib.h>

/*TC : O(logn) SC : O(1)*/
int searchelementinMatrix3(int (*arr)[3],int start, int end, int ele)
{
    int mid;
    while (start <= end) {
            mid = (start + (end))/2;
            if (arr[mid/3][mid%3] == ele) 
                return 0;
            else if (arr[mid/3][mid%3] > ele)
                end = mid - 1;
            else 
                start = mid + 1;
    }
    return -1;
}
int binary_search(int *arr,int start, int end, int ele)
{
    for(int i =0; i < 3; i++) 
        printf("%d\n",arr[i]);
    int mid;
    while (start <= end) {
            mid = (start + (end -1))/2;
            if (arr[mid] == ele) 
                return 0;
            else if (arr[mid] > ele)
                end = mid - 1;
            else 
                start = mid + 1;
    }
    return -1;
}

int myfloor(int (*arr)[3],int ele)
{
    for (int i = 0; i < 3; i++) {
        if (ele <  *(*(arr + i)+2)) {
            return i;
        }
    }
}
/*TC : O(nlogn) SC : O(1)*/
int searchelementinMatrix2(int (*arr)[3] , int ele)
{
    int index = myfloor(arr,8);
    printf("\n%d Index\n",index);
    return binary_search(*(arr + index),0,3,8);
}
/*TC : O(n^2) SC : O(1)*/
int searchelementinMatrix(int (*arr)[3] , int ele)
{
	for (int i = 0; i < 3; i++) {
	    for(int j = 0; j < 3; j++) {
                if (*(*(arr + i) + j) == ele )
                    return 0;
            }
	}
        return -1;
}

int main()
{
        int k = 0;
        int *a[3];
	int (*p)[3] = (int (*)[3])(malloc(sizeof(int) * 3 * 3)); 
	for (int i = 0; i < 3; i++) {
	    for(int j = 0; j < 3; j++) {
                *(*(p + i) + j) = ++k + 1; 
            }
	}
	for (int i = 0; i < 3; i++) {
	    for(int j = 0; j < 3; j++) {
                printf("%d\t",*(*(p + i) + j)); 
            }
            printf("\n");
	}
        //int search = searchelementinMatrix(p,11);
        //int search = searchelementinMatrix2(p,11);
        int search = searchelementinMatrix3(p,0,8,12);
        
        if (!search) 
            printf("Element Found\n");
        else 
            printf("Element not Found\n");

        return 0;
}

