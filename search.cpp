#include <iostream>
using namespace std;

int main()
{

    int n;
    int a;
    int index;
    bool flag = false;

    cout << "Enter size: ";
    cin >> n;

    //allocate the array
    int *arr = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> a;

    //--------------------Linear search----------------------
    /*
    time complexity = O(n)
    */
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == a)
    //     {
    //         flag = !flag;
    //         index = i;
    //         break;
    //     }
    // }

    // if (flag)
    // {
    //     cout << "Element found at index "<<index;
    // }
    // else
    // {
    //     cout << "Element not found";
    // }

    //--------------------Binary search----------------------
    /*
    time complexity = log(n)
    */
    int firstRange;
    int lastRange;
    if (arr[n / 2] > a)
    {
        firstRange = 0;
        lastRange = n / 2;
    }
    else
    {
        firstRange = n / 2;
        lastRange = n;
    }
    for (int i = firstRange; i < lastRange; i++)
    {
        if (arr[i] == a)
        {
            flag = !flag;
            index = i;
            break;
        }
    }

    if (flag)
    {
        cout << "Element found at index " << index;
    }
    else
    {
        cout << "Element not found";
    }

    //deallocate the array
    delete[] arr;

    return 0;
}