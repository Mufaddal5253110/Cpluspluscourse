/*******CIRCULAR LINKED LIST*******
 * !Circular linked list is a linked list where all nodes are connected to form a circle.
 * !There is no NULL at the end. A circular linked list can be a singly circular linked list
 * !or doubly circular linked list.

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insertAtHead(Node *&head, int data)
{

    Node *n = new Node();
    n->data = data;

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;

    n->next = head;
    head = n;
    return;
}

void insertAtTail(Node *&head, int data)
{
    // This node is tail node we have to insert it tail
    Node *n = new Node();
    n->data = data;
    n->next = head;

    // checking if head in null means linked list is empty means we have to insert at first position
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    // For traversing through node and inserting tail node at end
    Node *temp = head;
    // while loop till we reached to the last element of linked list , by mean next of last element should be null
    while (temp->next != head)
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
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;

    } while (temp != head);
    cout << head->data << endl;
    return;
}

int main()
{

    Node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
    {
        insertAtTail(head, arr[i]);
    }

    display(head); // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 1

    return 0;
}