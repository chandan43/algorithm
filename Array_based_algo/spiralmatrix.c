#include <stdio.h>
#include <stdlib.h>

#define R 4
#define C 4

void createMatrix(int (*p)[C])
{
    int k = 0;
    //p = (int (*)[C])(malloc(sizeof(int) * R * C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            *(*(p + i) + j ) = ++k + 1;
            //scanf("%d",(*(p + i) + j ));
        }
    }
}

void showMatrix(int (*p)[C])
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d\t",*(*(p + i) + j));
        }
        printf("\n");
    }
}

void spiralmatrix(int (*p)[C])
{
    int k = 0, l = 0, m = R, n = C;
    int i = 0;
    while (k < m && l < n) {
        for (i = l; i < m; i++) {
            printf("%d\t",p[k][i]);
        }
        k++;
        for (i = k; i < m; i++) {
            printf("%d\t",p[i][n-1]);
        }
        n--;
        if (k < m) {
            for (i = n-1; i >= 1; i--) {
                printf("%d\t",p[m-1][i]);
            }
            m--;
        }
        if (l < n) {
            for (i = m-1; i >= k; i--) {
                printf("%d\t",p[i][l]);
            }
            l++;
        }
    }
    printf("\n");
}

int main()
{
    int p[R][C]; 
    createMatrix(p);
    showMatrix(p);
    spiralmatrix(p);
    return 0;

}
