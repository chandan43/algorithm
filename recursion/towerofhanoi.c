#include <stdio.h>
#include <stdlib.h>

void towerofhonai( char src, char aug, char dist, int n)
{
        if (n == 1) {
            printf("%c -> %c\n", src, dist);
            return;
        }
        towerofhonai(src, dist, aug, n-1);
        printf("%c -> %c\n",src,dist);
        towerofhonai(aug, src ,dist, n-1);
}

int main()
{
        towerofhonai('A','B','C',300);
        return 0;
}

