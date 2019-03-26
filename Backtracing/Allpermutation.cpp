#include <iostream>
#include <string>
using namespace std;

class Allpermutation {
private:
    bool isvalid1(string res)
    {
        for (int i = 0; i < res.length(); ++i) {
            for (int j = i + 1; j < res.length(); ++j) {
                if (res[i] == res[j] )
                    return false;
            }
        }
        return true;
    }
    bool isvalid2(string res, char ch)
    {
        for (int i = 0; i < res.length(); ++i) {
                if (res[i] == ch )
                    return false;
            }
        return true;
    }
    void auxpermutation1(string in, string res)
    {
        if (in.length() == res.length()) {
            if (isvalid1(res))
                cout << res << endl;
            return;
        }
        for (int i = 0; i < in.length(); ++i)
            auxpermutation1(in,res+in.at(i));
    }
    void auxpermutation2(string in, string res)
    {
        if (in.length() == res.length()) {
                cout << res << endl;
            return;
        }
        for (int i = 0; i < in.length(); ++i) {
            if (isvalid2(res,in[i]))
            auxpermutation2(in,res+in.at(i));
        }
    }
    void auxpermutation3(string in, string res)
    {
        if (in.length() == 0) {
                cout << res << endl;
            return;
        }
        for (int i = 0; i < in.length(); ++i) {
            auxpermutation3(in.substr(0,i)+in.substr(0+1),res+in.at(i));
        }
    }
public:
    void permutation1(string& in){
       string res = "";
       auxpermutation1(in, res);
    }
    void permutation2(string& in){
       string res = "";
       auxpermutation2(in, res);
    }
    void permutation3(string& in){
       string res = "";
       auxpermutation2(in, res);
    }
};
int main()
{
    string in = "abc";
    Allpermutation all;
    //all.permutation1(in);
    //all.permutation2(in);
    all.permutation3(in);
    return 0;
}

