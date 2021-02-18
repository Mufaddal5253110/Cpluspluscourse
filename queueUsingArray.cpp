#include <iostream>
using namespace std;

#define n 100

class Queue
{

    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int x)
    {
        if (back == n - 1)
        {
            return; // no space
        }
        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }
    void dequeue()
    {
        if (empty())
        {
            return; //empty
        }
        front++;
    }
    int peek()
    {
        if (empty())
        {
            return -1; //empty
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
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

    Queue qe;

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

    cout << qe.peek() << endl;// 4

    qe.dequeue();
    qe.dequeue();
    qe.dequeue();

    cout << qe.peek() << endl; // -1

    cout << qe.empty() << endl; // 1

    return 0;
}