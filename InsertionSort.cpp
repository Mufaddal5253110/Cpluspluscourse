/*
Idea: Insert an element from unsorted array to its correct position in sorted array
*/

#include <iostream>
using namespace std;

int main()
{

    int n = 11;
    int arr[] = {12, 45, 23, 51, 19, 8, 234, 1, 278, 29, 13};

    for (int i = 1; i < n; i++)
    { // loop goes through whole array(i.e. [1,n-1])
        int currentElement = arr[i];
        int previuosIndex = i - 1;
        while (arr[previuosIndex] > currentElement && previuosIndex >= 0)
        { // swaping elements till all bigger elemnts come after the smaller
            arr[previuosIndex + 1] = arr[previuosIndex];
            previuosIndex--;
        }
        arr[previuosIndex + 1] = currentElement;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}