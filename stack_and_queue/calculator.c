#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else 
        return 2;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/')
}
typedef struct operand_stack {
    int top;
    int* array;
    unsigned int capacity;
}operand_stack;

operand_stack* createStackoperand(unsigned int capacity)
{
	operand_stack* stk = (operand_stack *)malloc(sizeof(operand_stack));
	stk->top = -1;
	stk->capacity = capacity;
	stk->array = (int *)malloc(sizeof(int)*capacity);
	return stk;
}

void pushint(operand_stack* stk, int ele)
{
	if (stk->top == stk->capacity)
		return;
	stk->array[++stk->top] = ele;
}
int popint(operand_stack* stk)
{
	if (stk->top == -1)
		return INT_MIN;
	int bkp = stk->array[stk->top--];
	return bkp;
}
int peekint(operand_stack* stk)
{
	return stk->array[stk->top];
}
typedef struct operator_stack {
    int top;
    char* array;
    unsigned int capacity;
}operator_stack;

operator_stack* createStackoperator(unsigned int capacity)
{
	operator_stack* stk = (operator_stack *)malloc(sizeof(operator_stack));
	stk->top = -1;
	stk->capacity = capacity;
	stk->array = (char *)malloc(sizeof(char)*capacity);
	return stk;
}

void pushchar(operator_stack* stk, char ele)
{
	if (stk->top == stk->capacity)
		return;
	stk->array[++stk->top] = ele;
}
char popchar(operator_stack* stk)
{
	if (stk->top == -1)
		return CHAR_MIN;
	int bkp = stk->array[stk->top--];
	return bkp;
}
char peekchar(operator_stack* stk)
{
	return stk->array[stk->top];
}

int calculat_string(char* str)
{
    int len = strlen(str);
    int i = 0, j = 0;
    while (str[i]) {
        if (isdigit(str[i]))
            pushint(stkint, str[i]);
        if (str[i] ==  '(')
            peekchar(stkchar,str[i]);
        else if (isOperator(str[i])) {
            if(priority(peekchar(stkchar))  )
        }
}
int main()
{
        
	operator_stack* stkchar = createStackoperator(5);
	operand_stack* stkint = createStackoperand(5);
	pushint(stkint, 1);
	pushint(stkint, 2);
	pushint(stkint, 3);
	pushint(stkint, 4);
	pushint(stkint, 5);
	printf("Peek ele: %d\n",peekint(stkint));
	printf("Del ele: %d\n",popint(stkint));
	printf("Del ele: %d\n",popint(stkint));
	printf("Peek ele: %d\n",peekint(stkint));
	pushint(stkint, 8);
	printf("Peek ele: %d\n",peekint(stkint));
	pushchar(stkchar, '+');
	pushchar(stkchar, '-');
	pushchar(stkchar, '*');
	pushchar(stkchar, '/');
	pushchar(stkchar, '^');
	printf("Peek ele: %c\n",peekchar(stkchar));
	printf("Del ele: %c\n",popchar(stkchar));
	printf("Del ele: %c\n",popchar(stkchar));
	printf("Peek ele: %c\n",peekchar(stkchar));
	pushchar(stkchar, '*');
	printf("Peek ele: %c\n",peekchar(stkchar));
	return 0;
}
