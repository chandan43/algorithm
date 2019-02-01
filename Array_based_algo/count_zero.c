#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000

void fill_input(int *arr)
{
	int i = 0; 
	while (i < (SIZE - 3)) {
		arr[i++] = 0;  
	}
	arr[SIZE -1] = 9;
	arr[SIZE -3] = 10;
	arr[SIZE -2] = 10;
}

void print_output(int *arr)
{
	int i = 0;
	while( i < SIZE) {
		printf("%d\t",arr[i++]);
	}
	printf("\n");
}
/*TC:  O(n) SC : O(1) */ 
int count_zero(int* arr)
{
	int i = 0;
	int count = 0; 
	while (i < SIZE -1) {
		if (arr[i++] != 0 )
		     goto err;
		count++;
	}
err:
	return count;
}

/*TC:  O(logn) SC : O(1) */ 
int count_zero1(int* arr)
{
	int l = 0;
	int h = SIZE - 1;
	int mid;
	int count = 0; 
	while ((h - l) > 1) {
		mid = (l + h)/2;
		if (arr[mid] == 0) {
			l = mid;
		}else {
			h = mid;
		}
	}
	if (arr[h] == 0)
		return h + 1;
	else return h;
}
int main()
{
	int* arr = (int *)malloc(sizeof(int) * SIZE);
	fill_input(arr);
	//print_output(arr);
	//int count = count_zero(arr);
	int count = count_zero1(arr);
	printf("No of Zero: %d\n",count);
	return 0;
}
