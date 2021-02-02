/*
!Problem :Given an array containing only 0,1 and 2. You have to sort the array in O(N) time, single pass, and O(1) space.
?Example array 1 1 2 0 0 1 2 2 1 0

Input: Given an array, containing only 0,1, and 2.

Output: print the sorted array.

Time Complexity: O(N), single pass
Space Complexity: O(1)

Explanation :
1. There would be three iterator/pointer low,mid &high with initial value
   0,0,n-1 respectively
2. Rule we have to follow:
    Check value of arr[mid]:-
        if 0 : swap arr[low] & arr[mid] , low++ & mid++
        if 1 : mid++
        if 2 : swap arr[mid] & arr[high] , high--

*/

#include <iostream>
using namespace std;

void swapFunc(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dnfSort(int *arr, int n)
{
    int low = 0, mid = 0;
    int high = n - 1;

    while (mid != high)
    {
        switch (arr[mid])
        {
        case 0:
            swapFunc(arr, low, mid);
            low++;
            mid++;
            break;

        case 1:
            mid++;
            break;

        case 2:
            swapFunc(arr, high, mid);
            high--;
            break;

        default:
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    //Main array
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dnfSort(arr, n);

    //Output
    cout << "\n\nOUTPUT:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ DNFSort.cpp -o DNFSort } ; if ($?) { .\DNFSort }
10
1 1 2 0 0 1 2 2 1 0


OUTPUT:
0 0 0 1 1 1 1 2 2 2

*/