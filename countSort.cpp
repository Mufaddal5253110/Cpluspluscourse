/*
?Given array like this [1,3,2,3,4,1,6,4,3]
!Key Points:
The O(N) sort.
Note: Only limited to small positive integers only.
Input: Given an array.
Output: print the sorted array.
Time Complexity: O(N)
Space Complexity: O(max(Arr))

Explanation desi:
1. initialize an array(a2) of size = max element of given array
2. a2 stores the count of each element in thier index
    Ex. count of 1 stores at index 1
3. according to above question array we have a2 like this
   [0,2,1,3,2,0,1]
    0 1 2 3 4 5 6
4. now we have to update a2 like, a2[i]=a2[i]+a2[i-1] to get
   the position of each element in sorted array.
   After Updaing : [0,2,3,6,8,8,9]
5. now again we have to initialize an array(a3) of size = size of main array.
6. now we have to iterate through main array from back and checking the position
   of each element in a2 and placing it in a3


*/

#include <iostream>
#include <algorithm>
using namespace std;

void countSort(int arr[], int n, int *opArr)
{

    // Gettting maximum element from given array
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    //initializing count array
    int *countArr = new int[k + 1]{0};
    for (int i = 0; i < n; i++)
    {
        countArr[arr[i]]++;
    }

    //Iniitially printing count array
    cout << "\nCount Array:" << endl;
    for (int i = 0; i <= k; i++)
    {
        cout << countArr[i] << " ";
    }

    //Updating count array
    for (int i = 1; i <= k; i++)
    {
        countArr[i] = countArr[i] + countArr[i - 1];
    }

    //printing updated count array
    cout << "\n\nUpdated Count Array:\n";
    for (int i = 0; i <= k; i++)
    {
        cout << countArr[i] << " ";
    }

    //updating main array
    for (int i = n - 1; i >= 0; i--)
    {
        countArr[arr[i]]--;
        opArr[countArr[arr[i]]] = arr[i];
    }
    return;
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

    //Output array
    int *outputArr = new int[n]{0};

    countSort(arr, n, outputArr);

    //Output
    cout << "\n\nOUTPUT:\n";
    for (int i = 0; i < n; i++)
    {
        cout << outputArr[i] << " ";
    }

    delete[] arr;
    delete[] outputArr;

    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ countSort.cpp -o countSort } ; if ($?) { .\countSort }
9
1 3 2 3 4 1 6 4 3

Count Array:
0 2 1 3 2 0 1

Updated Count Array:
0 2 3 6 8 8 9

OUTPUT:
1 1 2 3 3 3 4 4 6
*/