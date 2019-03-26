#include <iostream>
#include <string>
using namespace std;

class AllSubsset {
private:
    void auxsubset1(string& in,int d, string res)
    {
        if (d == in.length()) {
            cout << res << endl;
            return;
        }
        auxsubset1(in,d+1,res);
        auxsubset1(in,d+1,res+=in.at(d));
    }
    void auxsubset21(string in, string res)
    {
        cout << res << endl;
        if (in.length() == 0) {
            return;
        }
        for (int i = 0; i < in.length(); i++)
            auxsubset21(in.substr(i+1),res+=in.at(i));
    }
    void auxsubset22(string in, string res,int start)
    {
        cout << res << endl;
        if (in.length() == start) {
            return;
        }
        for (int i = start; i < in.length(); i++)
            auxsubset22(in,res+=in.at(i),i+1);
    }
public:
    void subset1(string& in){
       string res = " ";
       auxsubset1(in, 0 ,res);
    }
    void subset21(string& in){
       string res = " ";
       auxsubset21(in, res);
    }
    void subset22(string& in){
       string res = " ";
       auxsubset22(in, res, 0);
    }

};
int main()
{
    string in = "abc";
    AllSubsset all;
    all.subset1(in);
    all.subset21(in);
    all.subset22(in);
    return 0;
}

