#include <iostream>
#include <string>
#include <iterator> 
#include <bits/stdc++.h>
using namespace std;

#define MAX(a,b) a > b ? a : b
class TSTnode {
public:
    bool isworld;
    char data;
    TSTnode *left, *middle, *right;

    TSTnode(char data) {
        this->data = data;
        isworld = false;
        left = right = middle = NULL;
    }
};
//TST :TernarySearchTree
class TST {
private:
    TSTnode* root;
    TSTnode* auxadd(TSTnode* root, string s)
    {
        if (root == NULL) {
            root = new TSTnode(s.at(0));
        } 
        if (s.at(0) == root->data) {
            if (s.length() == 1) {
                root->isworld = 1;
                return root;
            }   
            root->middle = auxadd(root->middle,s.substr(1));
        } else if (s.at(0) > root->data) {
            root->right = auxadd(root->right,s);
        } else {
            root->left = auxadd(root->left,s);
        }
        return root;
    }
public:
    TST()
    {
        root = NULL;
    }
    void add(string s) 
    {
        TSTnode *tmp = auxadd(root, s);
        if (root == NULL)
            root = tmp;
    }
    string lcp(string s)
    {
        TSTnode* cur = root;
        int i = 0;
        while (cur) {
            if (s.at(i) == cur->data) {
                if (i == s.length() - 1)
                    return s;
                ++i;
                cur = cur->middle;
            }
            else if (s.at(i) < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        } 
        return s.substr(0,i);
    }
};


class LongestRepeatedSubstring {
private:
    int longestcommonprefix1(string s, int i, int j) 
    {
        int len = 0;
        while(j < s.length() && s.at(i) == s.at(j)) {
            ++i;
            ++j;
            ++len;
        }
        return len;
    }
    int longestcommonprefix2(string s1, string s2) 
    {
        int len = 0;
        int i = 0;
        while(i < s1.length() && i < s2.length() && s1.at(i) == s2.at(i)) {
            ++i;
            ++len;
        }
        return len;
    }
public:
    int longrepsubstr1(string s) {
        int res = INT_MIN;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i+1; j < s.length(); ++j) {
                int temp = longestcommonprefix1(s, i, j); 
                res = MAX(res, temp);
            }
        }
        return res;
    }
    int longrepsubstr2(string s) {
        vector <string> suffixes;
        for(int i = 0; i < s.length();i++)
            suffixes.push_back(s.substr(i)); 
        sort(suffixes.begin(), suffixes.end());
        int res = INT_MIN;
        for (int i = 1; i < s.length(); ++i) {
                int temp = longestcommonprefix2(suffixes[i],suffixes[i-1]); 
                res = MAX(res, temp);
        }
        return res;
    }
    int longrepsubstr3(string s) {
        TST tst;
        int res = 0;
        tst.add(s.substr(0));
        for (int i = 1; i < s.length(); ++i) {
                string temp = tst.lcp(s.substr(i));
                res = MAX(res, temp.length());
                tst.add(s.substr(i));
        }
        return res;
    }
};
int main()
{
    LongestRepeatedSubstring l;
    cout << l.longrepsubstr1("abcbab")<< endl;
    cout << l.longrepsubstr2("abcbab")<< endl;
    cout << l.longrepsubstr3("abcbab")<< endl;
    return 0;
}
