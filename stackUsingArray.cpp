/*
Stack : LIFO(Last In first Out)
*/

#include <iostream>
using namespace std;

#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int k)
    {
        if (top == n - 1)

            cout << "Stack Overflow" << endl;

        else
        {
            top++;
            arr[top] = k;
        }
    }
    void pop()
    {
        if (top == -1)

            cout << "No element to pop" << endl;

        else

            top--;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    int Top()
    {
        if (top == -1)
            return -1;
        else
            return arr[top];
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.Top() << endl; // 4

    st.pop();

    cout << st.Top() << endl; // 3

    cout << st.isEmpty() << endl; // 0

    st.pop();
    st.pop();
    st.pop();
    st.pop(); // No element to pop

    cout << st.isEmpty() << endl; // 1

    return 0;
}