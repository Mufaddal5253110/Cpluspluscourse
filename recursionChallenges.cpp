#include <iostream>
using namespace std;

/*
Check if an array is sorted or not
*/
bool checkSorted(int arr[], int n)
{
    if (n == 1)
        return 1;
    return arr[0] <= arr[1] && checkSorted(arr + 1, n - 1);
}

/*
Find first and last occurance of element in an array
*/

int firstOccurance(int arr[], int n, int len)
{
    if (arr[0] == n)
        return 1;
    if (len > 0)
        return 1 + firstOccurance(arr + 1, n, len - 1);
}

int lastOccurance(int arr[], int key, int lastindex, int len)
{
    if (arr[lastindex] == key)
        return lastindex;
    if (len > 0)
        return lastOccurance(arr, key, lastindex - 1, len);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4, 4, 3, 5};
    int n = 9;
    cout << checkSorted(arr, n) << endl;
    cout << firstOccurance(arr, 4, n) - 1 << endl;
    cout << lastOccurance(arr, 4, 7, n) << endl;

    return 0;
}