#include <iostream>
#include <string>
using namespace std;

class Allpartition {
private:
    void auxpartition(string in, string res)
    {
        if (in.length() == 0) {
            cout << res << endl;
            return;
        }
        for (int i = 0; i < in.length(); ++i)
            //auxpartition(in.substr(i+1),res+ "+" +in.substr(0,i+1));
            auxpartition(in.substr(i+1),in.substr(0,i+1)+'+'+res);
    }
public:
    void partition(string& in){
       string res = "";
       auxpartition(in, res);
    }
};
int main()
{
    string in = "abc";
    Allpartition all;
    all.partition(in);
    return 0;
}

