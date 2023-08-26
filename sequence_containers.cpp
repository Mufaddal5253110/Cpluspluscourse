#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Common member functions of all containers.
    // vec: (4, 1, 8}
    if (vec.empty())
    {
        cout << "Not possible. \n";
    }
    cout << vec.size();             // 3
    vector<int> vec2(vec);          // Copy constructor, vec2: (4, 1, 8}
    vec.clear();                    // Remove all items in vec;
    vec.size() == 0 vec2.swap(vec); // vec2 becomes empty, and vec has 3 items.
    // Notes: No penalty of abstraction, very efficient.

    /* Properties of Vector:
     * 1. fast insert/remove at the end: 0(1)
     * 2. slow insert/remove at the begining or in the middle: O(n)
     * 3. slow search: O(n)
     */

    /*
     * Deque
     */
    deque<int> deq = {4, 6, 7};
    deq.push_front(2); // deq: {2, 4, 6, 7}
    deq.push_back(3);  // deq: (2, 4, 6, 7, 3}
    // Deque has similar interface with vector
    cout << deq[1]; // 4

    /* Properties:
     * 1. fast insert/remove at the begining and the end;
     * 2. slow insert/remove in the middle: O(n)
     * 3. slow search: O(n)
     */

    /*
     * list
     * -- double linked list
     */

    list<int> mylist = {5, 2, 9};
    mylist.push_back(6);  // mylist: { 5, 2, 9, 6}
    mylist.push_front(4); // mylist: {4, 5, 2, 9, 6}

    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -> 2
    mylist.insert(itr, 8);                                           // mylist: {4, 5, 8, 2, 9, 6}
                                                                     // 0(1), faster than vector/deque
    itr++;                                                           // itr -> 9
    mylist.erase(itr);                                               // mylist: (4, 8, 5, 2, 6} O(1)

    /* Properties:
     * 1. fast insert/remove at any place: 0(1)
     * 2. slow search: O(n)
     * 3. no random access, no [] operator.
     */

    mylistl.splice(itr, mylist2, itr_a, itr_b); // 0 (1)

    /*
     * Array
     */
    int a[3] = {3, 4, 5};

    a.begin();
    a.end();
    a.size();
    a.swap();
}