#include <iostream>
#include <stack>
using namespace std;

class QueueStack
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x)
    {

        s1.push(x);
    }
    void dequeue()
    {
        if (empty())
        {
            return; //empty
        }
        else if (s2.empty())
        {
            while (!s1.empty())
            {
                int k = s1.top();
                s1.pop();
                s2.push(k);
            }
            s2.pop();
        }
        else
        {
            s2.pop();
        }
    }
    int peek()
    {
        if (empty())
        {
            return -1; //empty
        }
        else if (s2.empty())
        {
            while (!s1.empty())
            {
                int k = s1.top();
                s1.pop();
                s2.push(k);
            }
            return s2.top();
        }
        else
        {
            return s2.top();
        }
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    QueueStack qe;

    cout << qe.empty() << endl; // 1

    qe.enqueue(6);
    qe.enqueue(2);
    qe.enqueue(3);
    qe.enqueue(4);
    qe.enqueue(5);

    cout << qe.peek() << endl; // 6

    qe.dequeue();
    qe.dequeue();
    qe.dequeue();

    cout << qe.peek() << endl; // 4

    qe.dequeue();
    qe.dequeue();
    qe.dequeue();

    cout << qe.peek() << endl; // -1

    cout << qe.empty() << endl; // 1

    return 0;
}