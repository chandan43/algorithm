#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
    int operation(int a, int b, char op) {
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack <int> value;
        int i = 0;
        for (i = 0; i < tokens.size(); i++ ) {
            string s = tokens.at(i);
            
            if (isdigit(s[0]))
                value.push(stoi(tokens.at(i)));
             else {
                    if (isdigit(s[1])){
                     int res = 0;
                     int j = 1; 
                        while(j < s.length()) {
                            res = res * 10 + (s[j]-'0');
                            j += 1;
                        }
                        switch(s[0]) {
                            case '+': res;
                            case '-': res = -res;
                        }
                        value.push(res);
                        continue;
                    }              
                 int op2 = value.top();
                 value.pop();
                 int op1 = value.top();
                 value.pop();
                 value.push(operation(op1, op2, s[0]));
             }
        }
        return value.top();
    }
};


int main()
{
	class Solution s1;
	vector<string> str = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << "Result:  "<< s1.evalRPN(str) << endl;
	return 0;	


}
