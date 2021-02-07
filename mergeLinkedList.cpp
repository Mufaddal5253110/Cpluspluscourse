/*
Merging To Sorted Linked List
O(m+n)
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

void merge(Node *head1, Node *head2, Node *&mergedHead)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            insertAtTail(mergedHead, head1->data);
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            insertAtTail(mergedHead, head2->data);
            head2 = head2->next;
        }
        else if (head1->data = head2->data)
        {
            insertAtTail(mergedHead, head1->data);
            head1 = head1->next;
            // head2 = head2->next;
        }
    }

    while (head1 == NULL && head2 != NULL)
    {
        insertAtTail(mergedHead, head2->data);
        head2 = head2->next;
    }

    while (head2 == NULL && head1 != NULL)
    {
        insertAtTail(mergedHead, head1->data);
        head1 = head1->next;
    }
    return;
}

int main()
{

    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *mergedHead = NULL;
    int arr[] = {1, 3, 6, 9, 12};
    int arr2[] = {2, 4, 5, 6, 8, 10};
    for (int i = 0; i < 5; i++)
    {
        insertAtTail(head1, arr[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head2, arr2[i]);
    }

    display(head1); // 1 -> 3 -> 6 -> 9 -> 12 -> NULL
    display(head2); // 2 -> 4 -> 5 -> 6 -> 8 -> 10 -> NULL

    merge(head1, head2, mergedHead);

    display(mergedHead);// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 6 -> 8 -> 9 -> 10 -> 12 -> NULL

    return 0;
}