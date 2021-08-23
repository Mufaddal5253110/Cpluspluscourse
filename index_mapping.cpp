/*
1. Index Mapping (or Trivial Hashing) with negatives allowed.

Given a limited range array contains both positive and non-positive numbers,
i.e., elements are in the range from -MAX to +MAX. Our task is to search if
some number is present in the array or not in O(1) time.

How to handle negative numbers? 
The idea is to use a 2D array of size hash[MAX+1][2]

Algorithm:

Assign all the values of the hash matrix as 0.
Traverse the given array:
    If the element ele is non negative assign 
        hash[ele][0] as 1.
    Else take the absolute value of ele and 
         assign hash[ele][1] as 1.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define max 100

// global array
bool hashh[max + 1][2];

bool search(int x)
{
    int elem = x >= 0 ? x : abs(x);
    int col = x >= 0 ? 0 : 1;

    if (hashh[elem][col] == 1)
    {
        return true;
    }
    return false;
}

void insert(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            hashh[arr[i]][0] = 1;
        }
        else
        {
            hashh[abs(arr[i])][1] = 1;
        }
    }
}

int main()
{

    int a[] = {-1, 9, -5, -8, -5, -2};
    int n = sizeof(a) / sizeof(a[0]);
    insert(a, n);
    int X = -1;
    if (search(X) == true)
        cout << "Present";
    else
        cout << "Not Present";
    return 0;
}
