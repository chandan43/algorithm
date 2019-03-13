#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 3
#define COL 3

#define MIN(a,b) (((a)<(b))?(a):(b))
/*Complete search, Recursion with return value : TC : O(2^2n) SC: O(n)*/
void auxED1(char* s1, char* s2, int i, int j, int csum, int* gmax)
{
    int m = strlen(s1);
    int n = strlen(s2);
    if (i == m) {
        *gmax = MIN(csum, *gmax)+1;
         return;
    }
    if (j == n) {
        *gmax = MIN(csum, *gmax)+1;
         return;
    }
    if (*(s1+i) != *(s2+j)) {
        auxED1(s1,s2,i+1,j+1,csum+1,gmax);
        auxED1(s1,s2,i+1,j,csum+1,gmax);
        auxED1(s1,s2,i,j+1,csum+1,gmax);
    }else {
        auxED1(s1,s2,i+1,j+1,csum,gmax);
    }
}
int ED1(char* s1, char* s2)
{
    int gmax = 0;
    int csum = 0;
    auxED1(s1,s2,0,0,csum,&gmax);
    return gmax;
}
int auxED2(char* s1, char* s2, int i, int j)
{
    int m = strlen(s1);
    int n = strlen(s2);
    if (i == m) {
         return n-j;
    }
    if (j == n) {
         return m-i;
    }
    if (*(s1+i) != *(s2+j)) {
        int rop = auxED2(s1,s2,i+1,j+1);
        int dop = auxED2(s1,s2,i+1,j);
        int iop = auxED2(s1,s2,i,j+1);
        return MIN(MIN(rop,dop),iop)+1;
    }else {
        return auxED2(s1,s2,i+1,j+1);
    }
}
/*Complete search, Recursion with return value : TC : O(2^2n) SC: O(n)*/
int ED2(char* s1, char* s2)
{
    int gmax = auxED2(s1,s2,0,0);
    return gmax;
}
int auxED3(char* s1, char* s2, int i, int j,int (*mem)[strlen(s2)])
{
    int m = strlen(s1);
    int n = strlen(s2);
    if (i == m) {
         return n-j;
    }
    if (j == n) {
         return m-i;;
    }
     if(mem[i][j] != 0)
        return mem[i][j];
    if (*(s1+i) != *(s2+j)) {
        int rop = auxED3(s1,s2,i+1,j+1,mem);
        int dop = auxED3(s1,s2,i+1,j,mem);
        int iop = auxED3(s1,s2,i,j+1,mem);
        mem[i][j] = MIN(MIN(rop,dop),iop)+1;
    }else {
        mem[i][j] = auxED3(s1,s2,i+1,j+1,mem);
    }
    return mem[i][j];
}
int ED3(char* s1, char* s2)
{
    int (*mem)[COL] = (int (*)[strlen(s2)])calloc(sizeof(int), strlen(s1) * strlen(s2));
    int gmax = auxED3(s1,s2,0,0,mem);
    return gmax;
}
int ED4(char* s1, char* s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int (*mem)[COL] = (int (*)[strlen(s2)])calloc(sizeof(int),(m+1) * (n+1));
    for(int i = 0; i <= m; i++)
        mem[i][n] = i; 
    for(int i = 0; i <= m; i++)
        mem[m][i] = i; 
    for (int k = m-1; k >= 0; k--) {
	for(int l = n-1; l >=  0; l--) {
            if (*(s1+k) != *(s2+l)) {
                int rsum = mem[k+1][l+1];
                int isum = mem[k+1][l];
                int dsum = mem[k][l+1];
                mem[k][l] = MIN(MIN(rsum,dsum),dsum) + 1;
            }else {
                mem[k][l]= mem[k+1][l+1];
            }
        }
    }
    return mem[0][0];
}
#if 0
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
#endif 
int main(int argc, char** argv)
{
        printf("%d %s\n",strlen(argv[1]),argv[2]);
        int minmov = ED4(argv[1],argv[2]);
        printf("Min move :::- %d\n",minmov);
        return 0;
}
