#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*
     * unordered set
     */
    unordered_set<string> myset = {"red", "green", "blue"};
    unordered_set<string>::const_iterator itr = myset.find("green"); // 0(1)
    if (itr = myset.end())                                           // Important check
        cout << *itr << endl;
    myset.insert("yellow"); // O(1)

    vector<string> vec = {"purple", "pink"};
    myset.insert(vec.begin(), vec.end());

    // Hash table specific APIs:
    cout << "load_factor = " << myset.load_factor() << endl;
    string x = "red";
    cout << x < < < " is in bucket #" << myset.bucket(x) << endl;
    cout << "Total bucket #" << myset.bucket_count() << endl;

    // unordered multiset: unordered set that allows duplicated elements
    // unordered map: unordered set of pairs
    // unordered multimap: unordered map that allows duplicated keys

    // hash collision => performance degrade
    1

        /* Properties of Unordered Containers:
        * 1. Fastest search/insert at any place: 0(1)
                Associative Container takes O(log(n))
                vector, deque takes O(n)
                list takes 0(1) to insert, O(n) to search
        * 2. Unorderd set/multiset: element value cannot be changed.
             Unorderd map/multimap: element key cannot be changed.
        *
        */

        /*
         * Associative Array,
         * - map and unordered map
         */

        unordered_map<char, string>
            day = {{'S', "Sunday"}, {'M', "Monday"}};
    cout << day['S'] << endl;    // No range check
    cout << day.at('S') << endl; // Has range check

    vector<int> vec = {1, 2, 3};
    vec[5] = 5; // Compile Error

    day['W'] = "Wednesday";               // Inserting {'W', "Wednesday}
    day.insert(make_pair('F', "Friday")); // Inserting ('F', "Friday"}

    day.insert(make_pair('M', "MONDAY")); // Fail to modify, it's an unordered_map
    day['M'] = "MONDAY";                  // Succeed to modify

    void foo(const unordered_map<char, string> &m)
    {
        // m['S'] = "SUNDAY"; //const cannot modifi
        // cout << m['S'] << endl; //not right way
        auto itr = m.find('S');
        if (itr != m.end())
            cout << *itr << endl;
        }
    foo(day);
    I

        // Notes about Associative Array:
        // 1. Search time: unordered_map, 0(1); map, O(log(n));
        // 2. Unordered_map may degrade to O(n);
        // 3. Can't use multimap and unordered_multimap, they don't have [] operator.

        /*
        Container Adaptor
        Provide a restricted interface to meet special needs
        Implemented with fundamental container classes
        1. stack: LIFO, push(), pop(), top ()
        2. queue: FIFO, push(), pop(), front (), back ()
        3. priority queue: first item always has the greatest priority push(), pop(), top ()
        */

        /*
        * Another way of categorizing containers:
        *
        1. Array based containers: vector, deque
        *
        * 2. Node base containers: list + associative containers + unordered container:
        *
        * Array based containers invalidates pointers:
          - Native pointers, iterators, references
        */
        vector<int>
            vec = {1, 2, 3, 4};
    int *p = &vec[2]; // p points to 3
    vec.insert(vec.begin(), 0);
    cout << *p < < < endl; // 2, or ?

    return 0;
}