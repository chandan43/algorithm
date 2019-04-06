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
class ReverseBits_bytes {
public:
    int reversebytes(int n) {
        n = n << 24|(n << 8)&0X00FF0000 | (n >> 8)&0X00FF00 | n >> 24; 
        return n;
    }
    int reversebites(int x) {
	x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
	x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
	x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
	x = ((x & 0x00FF00FF) << 8) | ((x >> 8) & 0x00FF00FF);
	x = ((x & 0x0000FFFF) << 16) | ((x >> 16) & 0x0000FFFF);
	return x;
    }
};

int main()
{
    int n;
    cin >> n;
    ReverseBits_bytes rev;
    bitwise_Utils bit;
    bit.showbit(n);
    //n = rev.reversebytes(n);
    n = rev.reversebites(n);
    bit.showbit(n);
    return 0;
}
