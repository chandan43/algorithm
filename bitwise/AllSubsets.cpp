#include <iostream>
#include <string>
using namespace std;

class allsubsets {
public:
    void subsets(string s)
    {
        int len = s.length();
        int nsubsets = (1 << n);
        int mask = 1 << len -1;
        for (int i = 0; i < nsubsets; i++) {
            for (int j = 0; j < len; j++) {
                if (i & mask != 0)
                    cout << s[j];
                mask = mask >> 1;
            }
        }
    
    }

};
int main()
{

}
