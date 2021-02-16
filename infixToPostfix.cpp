#include <iostream>
#include <stack>
using namespace std;

int presedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    stack<char> st;
    string str = "(a-b/c)*(a/k-l)";

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || str[i] >= 'A' && str[i] <= 'Z')
        {
            cout << str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            
            while (!st.empty() && st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            int j = i;
            while (!st.empty() && presedence(str[j]) < presedence(st.top()))
            {
                cout << st.top();
                st.pop();
                j--;
            }
            st.push(str[i]);
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}

/*OUTPUT

abc/-ak/l-*

*/