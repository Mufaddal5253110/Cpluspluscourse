/*
Idea: Reapetedly swap two adjacent element if the are in wrong order
*/

#include <iostream>
using namespace std;

int main()
{

    int n = 11;
    int x = n - 1;
    int arr[] = {12, 45, 23, 51, 19, 8, 234, 1, 278, 29, 13};

    while (x > 1) // while loop for every time we will take the size of unsortd array(eg. 0 to n-1, 0 to n-2...)
    {
        for (int i = 0; i < x; i++) // on whole iteration last element will sort
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
        x--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}