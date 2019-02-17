#include <stdio.h>
#include <stdlib.h>
int getpowertonth(int x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == 2) return x * x;
    int temp = getpowertonth(x,n/2);
    if (n % 2 == 0)
        return temp * temp;
    else {
        return temp * temp * x;
    }
}
int main()
{
    int res = getpowertonth(100,2);
    printf("Res: %d\n",res);
    return 0;

}
