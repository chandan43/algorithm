#include <iostream>
#include <string>

using namespace std;
#define MAX(a,b) a > b ? a : b

class LCS {
private:
    void auxlcs1(int i, int j,string s1, string s2, int csum, int *gmax) 
    {
        if (s1.length() == i || s2. length() == j) { 
            if (*gmax < csum )
                *gmax = csum;
            return;
        }
        if (s1.at(i) == s2.at(j))
            return auxlcs1(i+1, j+1, s1, s2, csum + 1, gmax);
        else {
                auxlcs1(i+1, j, s1, s2, csum, gmax);
                auxlcs1(i, j+1, s1, s2, csum, gmax);
        }
    }
    int auxlcs2(int i, int j,string s1, string s2) 
    {
        if (s1.length() == i || s2. length() == j) 
            return 0;
        if (s1.at(i) == s2.at(j))
            return auxlcs2(i+1, j+1, s1, s2) + 1;
        else {
            int skipfirst = auxlcs2(i+1, j, s1, s2);
            int skipsecond = auxlcs2(i, j+1, s1, s2);
            return MAX(skipfirst, skipsecond);
        }
    }
    int auxlcs3(int i, int j,string s1, string s2, int** mem) 
    {
        int temp;
        if (s1.length() == i || s2. length() == j) 
            return 0;
        if (mem[i][j] != 0)
            return mem[i][j];
        if (s1.at(i) == s2.at(j))
            temp = auxlcs3(i+1, j+1, s1, s2, mem) + 1;
        else {
            int skipfirst = auxlcs3(i+1, j, s1, s2, mem);
            int skipsecond = auxlcs3(i, j+1, s1, s2, mem);
            temp = MAX(skipfirst, skipsecond);
        }
        mem[i][j] = temp;
        return temp;
    }

public:
    int lcs1(string s1, string s2)
    {
        int gmax = 0;
        auxlcs1(0, 0, s1,s2,0,&gmax);
        return gmax;

    }
    int lcs2(string s1, string s2)
    {
        return auxlcs2(0, 0, s1,s2);

    }
    int lcs3(string s1, string s2)
    {
        int** mem = new int*[s2.length()];
        for(int i = 0; i < s1.length(); i++)
              mem[i] = new int[s2.length()];
        return auxlcs3(0, 0, s1,s2, mem);
    }
    int lcs4(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        int** mem = new int*[s2.length()+1];
        for(int i = 0; i <= s1.length(); i++)
              mem[i] = new int[s2.length()+1];

        for(int i = 0; i < m; ++i)
            mem[i][n] = 0;
        for(int j = 0; j < n; ++j)
            mem[m][j] = 0;
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if (s1.at(i) == s2.at(j))
                    mem[i][j] = 1 + mem[i+1][j+1];
                else {
                    int skipfirst = mem[i+1][j];
                    int skipsecond = mem[i][j+1];
                    mem[i][j] = MAX(skipfirst, skipsecond);
                }
                
            }
        }
        return mem[0][0];

    }
};

int main()
{
    LCS lcs;
    cout << lcs.lcs1("abaaba", "baba") << endl;
    cout << lcs.lcs2("abaaba", "baba") << endl;
    cout << lcs.lcs3("abaaba", "baba") << endl;
    cout << lcs.lcs4("abaaba", "baba") << endl;
    return 0;
}
