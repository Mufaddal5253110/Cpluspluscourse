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

int getLength(Node *head)
{
    Node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

bool isIntersect(Node *head1, Node *head2)
{
    int diff = getLength(head1) - getLength(head2);
    int count = 0;
    while (count < diff)
    {
        head1 = head1->next;
        count++;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            return true;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return false;
}

int main()
{

    Node *head1 = NULL;
    Node *head2 = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {4, 5, 6, 1, 2, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
    {
        insertAtTail(head1, arr[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        insertAtTail(head2, arr2[i]);
    }

    display(head1); // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL
    display(head2); // 4 -> 5 -> 6 -> 1 -> 2 -> 6 -> 7 -> 8 -> 9 -> NULL

    if (isIntersect(head1, head2))
        cout << "Is Intersect: "
             << "True";
    else
        cout << "Is Intersect: "
             << "False";
    // Is Intersect: True

    return 0;
}