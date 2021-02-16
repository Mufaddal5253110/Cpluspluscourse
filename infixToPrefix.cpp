#include <iostream>
#include <stack>
#include <algorithm>
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

string reverseString(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

int main()
{

    stack<char> st;
    string str = "(a-b/c)*(a/k-l)";
    string ans;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || str[i] >= 'A' && str[i] <= 'Z')
        {
            ans += str[i];
        }
        else if (str[i] == ')')
        {
            st.push(str[i]);
        }
        else if (str[i] == '(')
        {

            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
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
                ans += st.top();
                st.pop();
                j--;
            }
            st.push(str[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << reverseString(ans) << endl;

    return 0;
}

/*OUTPUT

*-a/bc-/akl

*/