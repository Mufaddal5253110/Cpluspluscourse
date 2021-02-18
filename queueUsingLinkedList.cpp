#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedQueue
{
    Node *front;
    Node *back;

public:
    LinkedQueue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if (front == NULL)
        {
            front = temp;
            back = temp;
        }
        else
        {
            back->next = temp;
            back = temp;
        }
    }
    void dequeue()
    {
        if (empty())
        {
            return; //empty
        }
        else if (front->next == NULL)
        {
            Node *todlt = front;
            front = NULL;
            back = NULL;
            delete todlt;
        }
        else
        {
            Node *todlt = front;
            front = front->next;
            delete todlt;
        }
    }
    int peek()
    {
        if (empty())
        {
            return -1; //empty
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL && back == NULL)
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

    LinkedQueue qe;

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