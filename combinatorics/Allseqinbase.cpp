#include <iostream>
#include <string>
using namespace std;

class Allseqinbase {
private:
    void printarray(int* res, int s)
    {
        for(int i = 0; i < s; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    void auxallseq2(int d, int n, int b, int* res)
    {
        if (d == n) {
            printarray(res,n);
            return;
        }
        for (int i = 0; i < b; i++) {
            res[d] = i;
            auxallseq2(d+1,n,b,res);
        }
    }
public:
    /*Fixed length*/
    void allseq1(int n, int b) 
    {
        for(int i = 0; i < b; i++)
            for(int j = 0; j < b; j++)
                for(int k = 0; k < b; k++)
                    cout << i << " " << j << " "<< k << endl;
    }
    void allseq2(int n, int b)
    {
       int* res = new int[n];
       auxallseq2(0,n, b, res);
    }

};
int main()
{
    Allseqinbase all;
    all.allseq1(3,2);
    all.allseq2(2,3);
    return 0;
}

