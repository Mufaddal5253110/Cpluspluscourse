/*
Append Last K Nodes to the start of linked list
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void lastKToStart(Node *&head, int k)
{
    Node *temp = head;
    Node *start;
    Node *last;
    Node *end;
    int counter = 0;

    while (temp->next != NULL)
    {
        if (counter + 1 == k)
        {
            last = temp;
            start = temp->next;
        }
        counter++;
        temp=temp->next;
    }
    end = temp;

    last->next = NULL;
    end->next = head;
    head = start;
    
}

void insertAtHead(Node *&head, int data)
{

    Node *n = new Node();
    n->data = data;
    n->next = head;
    head = n;
    return;
}

void insertAtTail(Node *&head, int data)
{
    // This node is tail node we have to insert it tail
    Node *n = new Node();
    n->data = data;
    n->next = NULL;

    // For traversing through node and inserting tail node at end
    Node *temp = head;

    // checking if head in null means linked list is empty means we have to insert at first position
    if (head == NULL)
    {
        head = n;
        return;
    }

    // while loop till we reached to the last element of linked list , by mean next of last element should be null
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // inserting tail node at next to last element
    temp->next = n;
    return;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}

int main()
{
    Node *head = NULL;
    int arr[]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<9;i++){
        insertAtTail(head, arr[i]);
    }
    display(head); // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL

    lastKToStart(head, 5);
    display(head); // 6 -> 7 -> 8 -> 9 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    return 0;
}