/*****LINKED LIST*****
Linked List Basic Operations:
    1. Insertion at head
    2. Insertion at tail
    3. Traversal Through linked list
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

void deleteAtHead(Node *head)
{
    Node *toDelete = head;
    head = head->next;
    delete toDelete;
}

void deletion(Node *head, int data)
{
    // if first element
    if (head->data == data)
    {
        deleteAtHead(head);
    }
    // if linked list is empty
    else if (head == NULL)
    {
        return;
    }
    // if Linked list have only one element and is not equal to query
    else if (head->next == NULL)
    {
        if (head->data != data)
        {
            return;
        }
        else
        {
            deleteAtHead(head);
        }
    }
    Node *temp = head;
    while (temp->next->data != data)
    {
        if (temp->next == NULL)
        {
            return;
        }
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return;
}

int main()
{

    Node *head = NULL;
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    display(head);

    insertAtHead(head, 9);
    insertAtTail(head, 10);
    display(head);

    deletion(head, 12);
    display(head);

    return 0;
}

/*OUTPUT

1. Insertion at head
2. Insertion at tail
3. Traversal Through linked list

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ linkedList.cpp -o linkedList } ; if ($?) { .\linkedList }
6 -> 7 -> 8 -> NULL
9 -> 6 -> 7 -> 8 -> 10 -> NULL


4. deletion

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ linkedList.cpp -o linkedList } ; if ($?) { .\linkedList }
6 -> 7 -> 8 -> NULL
9 -> 6 -> 7 -> 8 -> 10 -> NULL
9 -> 6 -> 7 -> 10 -> NULL

*/