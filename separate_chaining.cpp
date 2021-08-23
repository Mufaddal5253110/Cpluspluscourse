/*
Separate Chaining

The idea is to make each cell of hash table point to a linked list
of records that have same hash function value.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class SeparateChaining
{
private:
    int n;
    vector<vector<int>> hashtable;

public:
    SeparateChaining(int n)
    {
        this->n = n;
        hashtable = vector<vector<int>>(n);
    }

    int getHashIndex(int x)
    {
        return x % n;
    }

    void insert(int x)
    {
        hashtable[getHashIndex(x)].push_back(x);
    }

    void deleteFromHashTable(int x)
    {
        int i = getHashIndex(x);
  
        // Scan for the element to be removed
        for (int j = 0; j < hashtable[i].size(); j++) {
  
            // Erase if present otherwise
            // print no element found!
            if (hashtable[i][j] == x) {
                hashtable[i].erase(hashtable[i].begin() + j);
                cout << x << " deleted!" << endl;
                return;
            }
        }
  
        cout << "No Element Found!" << endl;
    }

    void displayHashTable()
    {

        // Display the contents
        for (int i = 0; i < hashtable.size(); i++)
        {
            cout << i;
            for (int j = 0; j < hashtable[i].size(); j++)
                cout << " -> " << hashtable[i][j];
            cout << endl;
        }
    }
};

// Driver Code
int main()
{
    // Array to be used
    int arr[] = {12, 3, 23, 4, 11,
                 32, 26, 33, 17, 19};

    // Sending the size
    // for separate chaining
    SeparateChaining obj(10);

    // Inserting elements in
    // the container accordingly
    for (int i = 0; i < 10; i++)
        obj.insert(arr[i]);

    // Display the initial hash
    cout << "Initial Hash:\n";
    obj.displayHashTable();

    // Removing the element
    // from the container
    cout << "\nRemoving 23 from Hash: ";
    obj.deleteFromHashTable(23);
    cout << endl;

    // Display the final hash
    cout << "Final Hash:\n";
    obj.displayHashTable();
    return 0;
}
