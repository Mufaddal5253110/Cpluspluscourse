#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "{{{[(])}}";
    stack<char> st;
    int balanced=0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            balanced++;
            st.push(str[i]);
        }
        if ((str[i] == '}' && st.top() == '{') ||
            (str[i] == ']' && st.top() == '[') ||
            (str[i] == ')' && st.top() == '('))
        {
            balanced--;
            st.pop();
        }
    }

    if(balanced==0){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"UnBalanced"<<endl;

    }

    return 0;
}