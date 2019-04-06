#include <iostream>
#include <string>
using namespace std;
class bitwise_Utils {
public:
    void showbit(int n)
    {
        for(int i = 31; i >= 0; i--)
        {
            int mask = 1 << i;
            if ((n&mask) != 0)
                cout << "1";
            else
                cout << "0";
            if (i % 8 == 0)
                cout << " ";
        }
        cout << endl;
        
    }
};
class countones {
public:
    int count1(int n)
    {
        int cnt = 0, mask;
        for(int i = 0; i < 32; i++)
        {
            mask = 1 << i;
            if ((n&mask) != 0)
                ++cnt;
        }
        return cnt;
    }
    int count2(int n)
    {
        int cnt = 0, mask = 0xF;
        int one[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
        while(n != 0)
        {
                cnt += one[n&mask];
                n >>= 4;
        }
        return cnt;
    }
    int count3(int n)
    {
        int cnt = 0;
        while(n != 0)
        {
                ++cnt;
                n = n&(n-1);
        }
        return cnt;
    }


};

main()
{
    int n;
    cin >> n;
    countones c;
    bitwise_Utils bit;
    cout << "Count "<<c.count1(n) << endl;
    cout << "Count "<<c.count2(n) << endl;
    cout << "Count "<<c.count3(n) << endl;
    bit.showbit(n);
    return 0;
}
