#include <iostream>
#include <string>
#include <list>
#include <iterator> 
using namespace std;


class Itrie {
public:
    virtual void add(string s) = 0;
    virtual void remove(string s) = 0;
    virtual list <string> autocomplete(string s) = 0;
    virtual string lcp(string s) = 0;
    virtual void display() = 0;
};


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
class TST: public Itrie {
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
    void auxDisplay(TSTnode* root, int nspace, string type)
    {
        if (root == NULL) return;
        for (int i = 0; i < nspace; i++)
            cout << " ";
        cout << "(" << root->data << "," << root->isworld << "," << type << ")" << endl;
        auxDisplay(root->left,nspace + 4, "L");
        auxDisplay(root->middle,nspace + 4, "M");
        auxDisplay(root->right,nspace + 4, "R");
    }
    TSTnode* findLastNode(string s)
    {
        TSTnode* cur = root;
        int i = 0;
        while (cur) {
            if (s.at(i) == cur->data) {
                if (i == s.length()-1)
                    return cur;
                ++i;
                cur = cur->middle;
            }
            else if (s.at(i) < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        } 
        return NULL;
    }
    void traverse(TSTnode* cur, string s, list <string>& res)
    {
        if (cur == NULL)
            return;
        traverse(cur->left, s, res);
        if (cur->isworld) {
             res.push_back(s + cur->data);
        }
        traverse(cur->middle, s + cur->data, res);
        traverse(cur->right, s, res);
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
    void remove(string s) 
    {
        cout << s << endl;
    }
    list <string> autocomplete(string s)
    {
        list <string> res;
        TSTnode* cur;
        if (s.length() == 0)
            cur = root;
        else 
            cur = findLastNode(s);
        if (cur == NULL)
             goto res;
        if (cur->isworld)
                res.push_back(s);
        traverse(s.length()?cur->middle:cur, s, res);
res:
        return res;
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
    void display()
    {
        auxDisplay(root, 0, "Root");
    }

};

class RadixTreeNode {
public:
    RadixTreeNode* children[26];  
    bool isworld;
};

class RadixTree: public Itrie {
private:
    RadixTreeNode* root;
    void auxDisplay(RadixTreeNode* root, int nspace, char type)
    {
        if (root == NULL) return;
        for (int i = 0; i < nspace; i++)
            cout << " ";
        cout << "(" << root->isworld << "," << type << ")" << endl;
        for(int i = 0; i < 26; ++i)
            auxDisplay(root->children[i],nspace + 4, (char)('a' + i));
    }
    RadixTreeNode* findLastNode(string s)
    {
        RadixTreeNode* cur = root;
        int i;
        for(i = 0;i < s.length(); ++i) {
            int index = s.at(i) - 'a';
            if (!cur->children[index]) {
                return NULL;
            }
            cur = cur->children[index];
        } 
        return cur;
    }
    void traverse(RadixTreeNode* cur, string word, list <string>& res)
    {
        if (cur == NULL)
            return;
        if (cur->isworld) {
             res.push_back(word);
        }
        for(int i = 0; i < 26; ++i)
            traverse(cur->children[i], word+(char)('a'+i), res);
    }
public:
    RadixTree() {
        for(int i = 0; i < 26; ++i)
            
        root = new RadixTreeNode;
    }
    void add(string s)
    {
        RadixTreeNode* cur = root;
        for (int i = 0; i < s.length(); i++) {
            int index = s.at(i) - 'a';
            if(!cur->children[index])
                cur->children[index] = new RadixTreeNode;
            cur = cur->children[index];
        }
        cur->isworld = true;
    }
    string lcp(string s)
    {
        RadixTreeNode* cur = root;
        int i;
        for(i = 0;i < s.length(); ++i) {
            int index = s.at(i) - 'a';
            if (!cur->children[index]) {
                break;
            }
            cur = cur->children[index];
        } 
        return s.substr(0,i);
    }
    void remove(string s) 
    {
        cout << s << endl;
    }
    void display()
    {
        auxDisplay(root, 0, 'R');
    }
    list <string> autocomplete(string s)
    {
        list <string> res;
        RadixTreeNode* cur;
        cur = findLastNode(s);
        if (cur == NULL)
             goto res;
        traverse(cur, s, res);
res:
        return res;
    }
};
class test {
public:
    void printautolist(list <string> autocomp)
    {
        list <string> :: iterator it; 
        for(it = autocomp.begin(); it != autocomp.end(); ++it) 
            cout << *it << " "; 
         cout << endl;
    
    }
};
class TestTST {
public:
    test t;
    TST tst;
    list <string> :: iterator it; 
    list <string> input = {"abc","ab", "abd", "xyz", "xab", "pqr", "abcx","aaab", "a"};
    TestTST() {
        cout << "Test Result for TST\n";
        for(it = input.begin(); it != input.end(); ++it) 
            tst.add(*it);
        tst.display();
        cout << " Lcp "<< tst.lcp("xz") << endl; 
        cout << " Lcp "<< tst.lcp("aaab") << endl; 
        cout << " Lcp "<< tst.lcp("pq") << endl; 
        list <string> autocomp = tst.autocomplete("");
        t.printautolist(autocomp);
    }
};
class TestRedixTree {
public:
    test t;
    RadixTree redix;
    list <string> :: iterator it; 
    list <string> input = {"abc","ab", "abd", "xyz", "xab", "pqr", "abcx","aaab", "a"};
    TestRedixTree() {
        cout << "Test Result for RedixTree\n";
        for(it = input.begin(); it != input.end(); ++it) 
            redix.add(*it);
        redix.display();
        cout << " Lcp "<< redix.lcp("xz") << endl; 
        cout << " Lcp "<< redix.lcp("aaab") << endl; 
        cout << " Lcp "<< redix.lcp("pq") << endl; 
        list <string> autocomp = redix.autocomplete("");
        t.printautolist(autocomp);
        list <string> autocomp = redix.autocomplete("ab");
        t.printautolist(autocomp);
    }

};
int main()
{
    TestTST t;
    TestRedixTree r;
    return 0;
}
