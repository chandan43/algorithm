#include <iostream>
#include <string>
using namespace std;

class Allcharsequence {
private:
    void printarray(char* res, int s)
    {
        for(int i = 0; i < s; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    void auxcharseq1(char* in,int d, int n,char* res)
    {
        if (d == n) {
            printarray(res,n);
            return;
        }
        for (int i = 0; i < n; i++) {
            res[d] = in[i];
            auxcharseq1(in,d+1,n,res);
        }
    }
public:
    void charseq1(char* in,int n)
    {
       char* res = new char[n];
       auxcharseq1(in, 0,n, res);
    }

};
int main()
{
    char in[3] = {'a','b','c'};
    Allcharsequence all;
    all.charseq1(in,3);
    return 0;
}

