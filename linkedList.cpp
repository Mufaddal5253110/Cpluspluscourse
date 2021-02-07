/*****SINGLY LINKED LIST*****
 * !Like arrays, Linked List is a linear data structure.
 * !Unlike arrays, linked list elements are not stored at a contiguous location;
 * !the elements are linked using pointers.
Basic Operations:
    1. Insertion at head
    2. Insertion at tail
    3. Traversal Through linked list and Display
    4. Deletion
    5. Reverse
        A: By Iteration
        B: By Recursion
    6. Reverse K Nodes (By Iteration in recursion)
    7. Make Cycle
    8. Detect Cycle
    9. Remove cycle
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

void deleteAtHead(Node *&head)
{
    Node *toDelete = head;
    head = head->next;
    delete toDelete;
}

void deletion(Node *&head, int data)
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
    // if Linked list have only one element
    else if (head->next == NULL)
    {
        // and is not equal to query
        if (head->data != data)
        {
            return;
        }
        // and is equal to query
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

Node *revreseByIteration(Node *&head)
{

    Node *previous = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    return previous;
}

Node *revreseByRecurson(Node *&head)
{

    // Node *next;

    if (head == NULL || head->next == NULL)
    {
        // next = head->next;
        return head;
    }

    Node *newNode = revreseByRecurson(head->next);
    head->next->next = head;
    head->next = NULL;

    return newNode;
}

Node *revreseKNodes(Node *&head, int k)
{

    Node *previous = NULL;
    Node *current = head;
    Node *next;
    int counter = 0;

    // reversing k nodes
    while (current != NULL && counter < k)
    {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
        counter++;
    }

    // recurively Reversing remaining nodes and joining with previous nodes
    if (next != NULL)
        head->next = revreseKNodes(next, k);

    return previous;
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *cycleStartingNode;
    int count = 0;

    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cycleStartingNode = temp;
        }
        count++;
        temp = temp->next;
    }
    temp->next = cycleStartingNode;
    return;
}

bool detectCycle(Node *&head)
{
    /*
    Floyd's Algorithm
    Hare & Tortoise Algorithm
    */

    Node *tort = head;
    Node *hare = head;

    while (hare != NULL && hare->next != NULL)
    {
        tort = tort->next;       // tort taking one steps
        hare = hare->next->next; // hare taking 2 steps

        if (tort == hare)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(Node *&head)
{
    Node *tort = head;
    Node *hare = head;

    // loop till both reach to one place
    do
    {
        tort = tort->next;
        hare = hare->next->next;
    } while (tort != hare);

    //taking hare back to head
    hare = head;
    // looping till next of tort and hare matches
    while (hare->next != tort->next)
    {
        tort = tort->next;
        hare = hare->next;
    }
    tort->next = NULL;
}

int main()
{

    Node *head = NULL;
    //?Insertion at tail
    // insertAtTail(head, 6);
    // insertAtTail(head, 7);
    // insertAtTail(head, 8);

    //?Display
    // display(head);

    //?Insertion at head
    // insertAtHead(head, 9);

    // insertAtTail(head, 10);
    // display(head);

    //?Deletion
    // deletion(head, 6);
    // display(head);

    //?Reverse By Iteration
    // Node *reversedHead1 = revreseByIteration(head);
    // display(reversedHead1);

    //?Reverse By Recursion
    // Node *reversedHead2 = revreseByRecurson(head);
    // display(reversedHead2);

    //?Reverse K Nodes
    // Node *reversedHead3 = revreseKNodes(head, 2);
    // display(reversedHead3);

    //? Make, Detect & remove cycle

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);

    //Make Cycle
    cout << "Making Cycle" << endl;
    makeCycle(head, 3);

    //Detect Cycle
    cout << "Detecting Cycle: " << detectCycle(head) << endl;

    //Remove cycle
    removeCycle(head);
    cout << "Removing Cycle and Detcting: " << detectCycle(head) << endl;

    //Display cycle
    cout << "Displaying Cycle" << endl;
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

5. Reverse
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ linkedList.cpp -o linkedList } ; if ($?) { .\linkedList }
6 -> 7 -> 8 -> NULL
9 -> 6 -> 7 -> 8 -> 10 -> NULL
9 -> 7 -> 8 -> 10 -> NULL
10 -> 8 -> 7 -> 9 -> NULL

6. Reverse K Nodes
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ linkedList.cpp -o linkedList } ; if ($?) { .\linkedList }
6 -> 7 -> 8 -> NULL
9 -> 6 -> 7 -> 8 -> 10 -> NULL
9 -> 7 -> 8 -> 10 -> NULL
7 -> 9 -> 10 -> 8 -> NULL

7. Make, Detect & remove cycle
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ linkedList.cpp -o linkedList } ; if ($?) { .\linkedList }
Making Cycle
Detecting Cycle: 1
Removing Cycle and Detcting: 0
Displaying Cycle
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL
*/