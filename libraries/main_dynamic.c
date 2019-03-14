#include <stdio.h>

int add(int, int);
int sub(int, int);
int max(int, int);
int min(int, int);

int main()
{
   int a = 10;
   int b = 8;
   int lmax = max(a, b);
   int lmin = min(a, b);
   int ladd = add(a, b);
   int lsub = sub(a, b);
   printf("Lmax: %d, Lmin: %d, Ladd: %d, Lsub %d\n",lmax,lmin,ladd,lsub);
   return 0;
}
