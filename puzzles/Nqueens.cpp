#include <iostream>
#include <cstdlib>
using namespace std;
class Nqueens {
private:
    bool isvalid1(int* out, int n)
    {
        for(int i = 0; i < n; ++i) {
            for(int j= i+1; j < n; ++j) {
                if(out[i] == out[j] || abs(i-j) == abs(out[i]-out[j]))
                    return false;
            }
        }
        return true;
    
    }
    bool isvalid2(int* out, int n, int d, int c)
    {
        for(int i = 0; i < d; ++i) {
                if(out[i] == c || abs(i-d) == abs(out[i]-c))
                    return false;
        }
        return true;
    
    }
    void printarray(int* out, int n)
    {
        for(int i=0; i < n; ++i)
            cout << out[i] << " ";
        cout << endl;
    }
    void auxnquuen1(int d, int* out, int n)
    {
        if (d == n) {
            if (isvalid1(out,n))
                printarray(out, n);
            return;
        }
        for(int c = 0; c < n; ++c) {
            out[d] = c;
            auxnquuen1(d+1, out, n);
        }
    }
    void auxnquuen2(int d, int* out, int n)
    {
        if (d == n) {
            printarray(out, n);
            return;
        }
        for(int c = 0; c < n; ++c) {
            if (isvalid2(out,n,d,c)) {
                out[d] = c;
                auxnquuen2(d+1, out, n);
            }
        }
    }
public:
    void nqueen1(int n)
    {
        int* out = new int[n];
        auxnquuen1(0,out,n);
    }
    void nqueen2(int n)
    {
        int* out = new int[n];
        auxnquuen2(0,out,n);
    }
};


int main()
{
    Nqueens q;
    //q.nqueen1(4);
    q.nqueen2(4);
    return 0;
}
