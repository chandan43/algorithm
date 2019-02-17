#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int isOpetator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
int applyop(int a, int b, char op)
{
    switch (op) {
        case '+':
                return a + b;
        case '-':
                return a - b;
        case '*':
                return a * b;
        case '/':
                return a / b;
    }

}
int calculateExp(char* exp)
{
    stack <int> operand;
    stack <char> Operator;
    int i;
    for  (i = 0; i < strlen(exp); i++) {
        if (exp [i] == ' ')
            continue;
        else if (exp[i] == '(')
            Operator.push(exp[i]);
        else if (isdigit(exp[i])) { 
            int num = 0;
            while (i < strlen(exp) && isdigit(exp[i])) {            
                num = num * 10 + (exp[i] - '0');
                if (!isdigit(exp[i+1]))
                    goto exit;
                else 
                    i++;
            }
exit:
            operand.push(num);
        }
        else if (exp[i] == ')') {
            while (!Operator.empty() && Operator.top() != '('){
                int op2 = operand.top();
                operand.pop();
                int op1 = operand.top();
                operand.pop();
                char op = Operator.top();
                Operator.pop();
                operand.push(applyop(op1, op2, op));
            }
            Operator.pop();
        } else {
            while (!Operator.empty() && Operator.top() >= exp[i] ){
                int op2 = operand.top();
                operand.pop();
                int op1 = operand.top();
                operand.pop();
                char op = Operator.top();
                Operator.pop();
                operand.push(applyop(op1, op2, op));
            }
            Operator.push(exp[i]);
        }
    }
    while (!Operator.empty()) {
            int op2 = operand.top();
            operand.pop();
            int op1 = operand.top();
            operand.pop();
            char op = Operator.top();
            Operator.pop();
            operand.push(applyop(op1, op2, op));
    }
    return operand.top();    

}
int main()
{
    char exp[] = "(1)";
    cout << "Cal: "<<calculateExp(exp) << endl;
    return 0;
}
