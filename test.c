#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int func(void *p) {
	return ++*((int *)p); 
	//printf("%d",++*(int *)p);
	
}

int main()
{
	int a = 10;
	bool  *n =  (bool *)malloc(sizeof(bool) * 10); 
	func(&a);
	printf("%d\n",a);
	return 0;
}
