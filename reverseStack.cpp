/*
Reverse stack using recursion
*/

#include <iostream>
#include <stack>
using namespace std;

void inserAtbottom(stack<int> &st, int ele)
{

    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    inserAtbottom(st, ele);

    st.push(topele);
}

void reverseStack(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int topele = st.top();
    st.pop();
    reverseStack(st);
    inserAtbottom(st, topele);
}

void displayStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Main Stack: ";
    displayStack(st);

    reverseStack(st);

    cout << "Reversed Stack: ";
    displayStack(st);

    return 0;
}

/*OUTPUT
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ reverseStack.cpp -o reverseStack } ; if ($?) { .\reverseStack }
Main Stack: 4 3 2 1 
Reversed Stack: 1 2 3 4
*/