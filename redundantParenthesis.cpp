#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "((A+B)-(C)*b)";
    stack<char> st;

    for (int i = 0; i < str.length() ; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'A'))
        {
            continue;
        }
        else
        {
            if (str[i] == ')')
            {
                if (!st.empty() && st.top() != '(')
                {

                    st.pop();
                    st.pop();
                }else{
                    cout<<"Redundant";
                    break;
                }
            }else{
                st.push(str[i]);
            }
        }
    }

    return 0;
}
