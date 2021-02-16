/*
Infix = general expression (2*4+3)
Prefix = Operator than Operands (+*243)
Postfix = Operands than Operator (42*3+)
*/

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int operation(int a, int b, char oper)
{

    switch (oper)
    {
    case '^':
        return pow(a, b);
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    }
    return 0;
}

void postfixEvalaution(string str)
{
    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0'); //hack to convert char number to int
        }
        else
        {
            int a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(operation(a, b, str[i]));
        }
    }
    cout << st.top() << endl;
}

void prefixEvalaution(string str)
{
    stack<int> st;
    for (int i = str.length()-1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0'); //hack to convert char number to int
        }
        else
        {
            int a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(operation(a, b, str[i]));
        }
    }
    cout << st.top() << endl;
}

int main()
{
    string strpostfix = "46+2/5*7+";
    string strprefix = "-+7*45+20";
    postfixEvalaution(strpostfix); // 32
    prefixEvalaution(strprefix);   // 25
    return 0;
}