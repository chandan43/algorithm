#include <iostream>
using namespace std;

class HigherLowerMultiplesof8 {
public:
    int prevLowest(int n) {
        return n & ~7; // n & -8;
    }
    int nexthighest(int n) {
        return (n + 8) & ~7; // n & -8;
    }
};

int main()
{
    int n;
    cin >> n;
    HigherLowerMultiplesof8 h;
    cout << h.prevLowest(n) << endl;
    cout << h.nexthighest(n) << endl;
    return 0;
}



