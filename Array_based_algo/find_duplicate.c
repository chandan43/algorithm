#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

#define SIZE 100000000


long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int parttion(int *arr, int start, int end)
{
	int i = start + 1;
	int pvot = arr[start];
	for (int j = start+1; j <= end; j++) {
		if (arr[j] < pvot) {
			swap(&arr[i],&arr[j]);
			i += 1;
		}
	}
	swap(&arr[start], &arr[i - 1]);
	return i - 1;

}
/*TC : O(n)*/
void sort(int *arr, int start, int end)
{
	if (start < end) {
		int pvot_pos = parttion(arr, start, end);
		sort(arr, start,  pvot_pos - 1);
		sort(arr, pvot_pos + 1, end);
	}
}

void fill_array(int *arr)
{
	int i = 0;
	int j = 1;
	while (i < SIZE - 1) {
		//scanf("%d",&arr[i++]);
		arr[i++] = j++; 
	}
	arr[SIZE -1] = --j;
}

void print(int *arr)
{
	int i = 0;
	while (i < SIZE) {
		printf("%d\t",arr[i++]);
	}
	printf("\n");
	
}
void printbool(bool *arr)
{
	int i = 0;
	while (i < SIZE) {
		printf("%d\t",arr[i++]);
	}
	printf("\n");
	
}

/*TC: O(n^2) SC: O(1)*/
int duplicate_1st(int *arr){
	int i = 0;
	for (i = 0; i <  SIZE -1; i++) {
	     for (int j = i+1; j < SIZE -1; j++) {
		if (arr[j] == arr[j-1]) 
			return arr[j];
	     }
	}
	return -1;
}
/*TC: O(nlogn) SC: O(1)*/
int duplicate_2nd(int *arr){
	int i = 0;
	sort(arr,0,SIZE - 1);
	for (i = 0; i < SIZE -1; i++) {
		if ( arr[i] == arr[i + 1]) 
			return  arr[i];
	}
	return -1;
}

/*TC: O(1) SC: O(n)*/
int duplicate_3rd(int *arr){
	int i = 0;
	bool* copy_arr = (bool *)malloc(sizeof(bool) * SIZE);
	//printbool(copy_arr);
	for (i = 0; i < SIZE -1; i++) {
		if ( copy_arr[arr[i]] == true ) {
			return  arr[i];
		} else {
		 	copy_arr[arr[i]] = true;
		}
	}
	return -1;
}
/*TC: O(1) SC: O(1) :Duplicate*/
int duplicate_4th(int *arr){
	int i = 0;
	int bkp;
	//printbool(copy_arr);
	for (i = 0; i < SIZE ; i++) {
		if ( arr[abs(arr[i])] < 0 ) {
			bkp = abs(arr[i]);
			goto abs; 
		} else {
		 	arr[abs(arr[i])] = -(arr[abs(arr[i])]);
		}
	}
	//print(arr);
	return -1;
abs:
	for (i = 0; i < SIZE ; i++) {
		arr[i] = abs(arr[i]);
	}
	//print(arr);
	return bkp;
}


int main()
{
	int* arr = (int *)malloc(sizeof(int) * SIZE);
	fill_array(arr);
	//print(arr);
	//sort(arr, 0, SIZE - 1);
	//print(arr);
	long start_time = getMicrotime();
	int d = duplicate_1st(arr);
	//int d = duplicate_3rd(arr);
	//int d = duplicate_4th(arr);
	long last_time = getMicrotime();
	printf("Time Taken : %ld micro sec\n",last_time-start_time);
	if ( d > 0 ) {
		printf("Duplicate No. is %d\n",d);
	} else {
		printf("Not Found Duplicate No\n");
	}
	return 0;
}
