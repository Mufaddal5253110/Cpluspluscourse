/*****DOUBLY LINKED LIST*****
 * !A Doubly Linked List (DLL) contains an extra pointer, typically called previous pointer,
 * !together with next pointer and data which are there in singly linked list
Basic Operations:
    1. Insertion at head
    2. Insertion at tail
    3. Traversal Through linked list and Display
    4. Deletion
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;
};

void insertionAtHead(Node *&head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->next = head;
    n->previous = NULL;
    head = n;
    return;
}

void insertionAtTail(Node *&head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->next = NULL;

    Node *temp = head;

    if (head == NULL)
    {
        n->previous = NULL;
        head = n;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    n->previous = temp;
    temp->next = n;
    return;
}
void display(Node *head)
{
    Node *temp = head;
    cout << "NULL <- ";
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}

void deleteNode(Node *&head, int key)
{
    Node *temp = head;

    //Checking for 1st
    if (head->data == key)
    {
        Node *todlt = head;
        head = head->next;
        head->next->previous = NULL;
        delete todlt;
        return;
    }

    while (temp != NULL)
    {
        //Between 1st and last
        if (temp->data == key && temp->next != NULL)
        {
            Node *todlt = temp;
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete todlt;
            return;
        }
        //Last
        else if (temp->data == key && temp->next == NULL)
        {
            Node *todlt = temp;
            temp->previous->next = NULL;
            delete todlt;
            return;
        }
        temp = temp->next;
    }
    return;
}

int main()
{

    Node *head = NULL;

    //?Insert At Tail
    insertionAtTail(head, 1);
    insertionAtTail(head, 2);
    insertionAtTail(head, 3);
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);

    //?Display
    display(head); // NULL <- 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> NULL

    //?Insert At Head
    insertionAtHead(head, 6);

    //?Display
    display(head);// NULL <- 6 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> NULL

    //?Delete
    deleteNode(head, 5);

    //?Display
    display(head); // NULL <- 6 <-> 1 <-> 2 <-> 3 <-> 4 <-> NULL
    return 0;
}