#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

#define MAX(a,b) (((a)>(b))?(a):(b))
/*Complete search, Recursion with return value : TC : O(2^2n) SC: O(n)*/
void auxgridsum1(int (*p)[COL], int i, int j, int csum, int* gmax)
{
    if (i >= ROW || j >= COL) {
        if (csum  > *gmax)
            *gmax = csum;
        return;
    }
    auxgridsum1(p,i+1,j,csum+p[i][j],gmax);
    auxgridsum1(p,i,j+1,csum+p[i][j],gmax);
}
int gridsum1(int (*p)[COL], int i, int j)
{
    int gmax = 0;
    int csum = 0;
    auxgridsum1(p,0,0,csum,&gmax);
    return gmax;
}
/*Complete search, Recursion with return value : TC : O(2^2n) SC: O(n)*/
int gridsum2(int (*p)[COL], int i, int j)
{
    if (i >= ROW || j >= COL)
        return 0;
    int rsum = gridsum2(p,i+1,j);
    int dsum = gridsum2(p,i,j+1);
    return MAX(rsum,dsum)+ p[i][j];
}
/*TC : O(n^2) SC: O(n^2)*/
int auxgridsum3(int (*p)[COL], int i, int j, int (*mem)[COL])
{
     if (i >= ROW || j >= COL)
        return 0;
     if(mem[i][j] != 0)
        return mem[i][j];
     int rsum = auxgridsum3(p,i+1,j,mem);
     int dsum = auxgridsum3(p,i,j+1,mem);
     mem[i][j] = MAX(rsum,dsum) + p[i][j];
     return mem[i][j];
}
int gridsum3(int (*p)[COL], int i, int j)
{
    int (*mem)[COL] = (int (*)[COL])calloc(sizeof(int), ROW * COL);
    return auxgridsum3(p,0,0,mem);
}
void treeOptimalPath(int i, int j, int (*mem)[COL+1])
{
    if(i >= ROW-1 && j >= COL-1)
        return;
    if(mem[i+1][j] > mem[i][j+1]) {
        printf("(%d,%d)->",i+1,j);
        treeOptimalPath(i+1,j,mem);
    }else{
        printf("(%d,%d)->",i,j+1);
        treeOptimalPath(i,j+1,mem);
    }
}
int auxgridsum4(int (*p)[COL], int (*mem)[COL+1])
{
     for (int i = 0; i <= ROW; i++)
        mem[i][COL] = mem[ROW][i] = 0;
    for (int k = ROW-1; k >= 0; k--) {
	for(int l = COL-1; l >=  0; l--) {
                int rsum = mem[k+1][l];
                int dsum = mem[k][l+1];
                mem[k][l] = MAX(rsum,dsum) + p[k][l];
        }
    }
    return mem[0][0];
}
/*TC : O(n^2) SC: O(n^2)*/
int gridsum4(int (*p)[COL], int i, int j)
{
    int (*mem)[COL+1] = (int (*)[COL+1])calloc(sizeof(int), ROW+1 * COL+1);
    int msum = auxgridsum4(p,mem);
    treeOptimalPath(0,0,mem);
    printf("\n");
    return msum;
}
int main()
{
	int (*p)[COL] = (int (*)[COL])(malloc(sizeof(int) * ROW * COL)); 
	for (int k = 0; k < ROW; k++) {
	    for(int l = 0; l < COL; l++) {
                *(*(p + k) + l) = rand() % 10; 
            }
	}
	for (int k = 0; k < ROW; k++) {
	    for(int l = 0; l < COL; l++) {
                printf("%d\t",*(*(p + k) + l)); 
            }
            printf("\n");
	}

        int msum = gridsum1(p,0,0);
        printf("Max Sum1:::- %d\n",msum);
        msum = gridsum2(p,0,0);
        printf("Max Sum2:::- %d\n",msum);
        msum = gridsum3(p,0,0);
        printf("Max Sum3:::- %d\n",msum);
        msum = gridsum4(p,0,0);
        printf("Max Sum4:::- %d\n",msum);
        return 0;
}
