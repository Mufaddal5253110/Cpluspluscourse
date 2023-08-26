#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*
     * Iterators
     */
    // 1. Random Access Iterator: vector, deque, array
    vector<int> itr;
    itr = itr + 5; // advance itr by 5
    itr = itr - 4;
    if (itr2 > itrl)
        ... ++itr; // faster than itr++
    --itr;

    // 2. Bidirectional Iterator: list, set/multiset, map/multimap
    list<int> itr;
    ++itr;
    --itr;

    // 3. Forward Iterator: forward_list
    forward list<int> itr;
    ++itr;

    // Unordered containers provide "at least" forward iterators.

    // 4. Input Iterator: read and process values while iterating forward.
    int x = *itr;
    // 5. Output Iterator: output values while iterating forward.
    *itr = 100;

    // Every container has a iterator and a const_iterator
    set<int>::iterator itr;
    set<int>::const_iterator citr; // Read_only access to container elements
    set<int> myset = {2, 4, 5, 1, 9};
    for (citr = myset.begin(); citr != myset.end(); ++citr)
    {
        cout << *citr << endl;
        //*citr = 3;
    }
    for_each(myset.cbegin(), myset.cend(), MyFunction); // Only in C++ 11

    // Iterator Functions:
    advance(itr, 5);      // Move itr forward 5 spots. itr += 5;
    distance(itrl, itr2); // Measure the distance between itrl and itr2

    /* Iterator Adaptor (Predefined Iterator)
     * - A special, more powerful iterator
     * 1. Insert iterator
     * 2. Stream iterator
     * 3. Reverse iterator
     * 4. Move iterator (C++ 11)
     */

    // 1. Insert Iterator:
    vector<int> vec1 = {4, 5};
    vector<int> vec2 = {12, 14, 16, 18};
    vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
    insert_iterator<vector<int>> i_itr(vec2, it);
    copy(vecl.begin(), vec1.end(), // source
         i_itr);                   // destination
    // vec2: (12, 14, 4, 5, 16, 18}
    //  Other insert iterators:back_insert_iterator, front_insert_iterator

    // 2. Stream Iterator:
    vector<string> vec4;
    copy(istream_iterator<string>(cin), istream_iterator<string>() back_inserter(vec4));
    copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, ""));

    // Make it terse:
    unique_copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, ""));

    // 3. Reverse Iterator:
    vector<int> vec = {4, 5, 6, 7};
    reverse_iterator<vector<int>::iterator> ritr;
    for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
        cout << *ritr < < < < < < endl; // prints: 7 6 5 4

    /*
     *Algorithms
     *-mostly loops
     */
    vector<int> vec = {4, 2, 5, 1, 3, 9};
    vector<int>::iterator itr = min_element(vec.begin(), vec.end()); // itr -> 1

    // Note 1: Algorithm always process ranges in a half-open way: [begin, end)
    sort(vec.begin(), itr);  // vec: 2, 4, 5, 1, 3, 9}
    reverse(itr, vec.end()); // vec: { 2, 4, 5, 9, 3, 1} itr = > 9
    // Note 2:
    vector<int> vec2(3);
    copy(itr, vec.end(), // Source
         vec2.begin());  // Destination
    // vec2 needs to have at least space for 3 elements.
    &

        // Note 3:
        vector<int>
            vec3;
    copy(itr, vec.end(), back_inserter(vec3)); // Inserting instead of overwriting
    // back_insert_iterator                         Not efficient
    vec3.insert(vec3.end(), itr, vec.end()); // Efficient and safe

    // Note 4: Algorithm with function
    bool isodd(int i)
    {
        return i % 2;
    }
    int main()
    {
        vector<int> vec = {2, 4, 5, 9, 2} vector<int>::iterator itr = find_if(vec.begin(), vec.end(), isOdd);
        // itr->5
    }

    // Note 5: Algorithm with native C++ array
    int arr[4] = {6, 3, 7, 4};
    sort(arr, arr + 4);
}
