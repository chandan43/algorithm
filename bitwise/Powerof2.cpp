#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n&(n-1) == 0)
        cout << "N is power of 2" << endl;
    else
        cout << "N is not Power of 2" << endl;
    return 0;
}
