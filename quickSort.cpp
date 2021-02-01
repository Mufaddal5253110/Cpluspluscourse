/*
Idea: Select a random pivot, put it in its correct position, and sort the left and
right part recursively.
Time Complexity: 
    Avg = O(N logN)
    Worst Case = O(N^2)

Complexity:
Best case : jab pivot ke position/index middle me ho
Worst case : jab pivot ke position/index starting me ho ya last me 

Explanation Desi:
Partition function:-
    1. Sabse pehel hum last wala element choose karenge and usko store kardenge pivot 
    me and uske according do iterator rakhenge ek to for loop ke dwara and ek manual
    iterator jo initially equal honga start ke.
    2. to Isme hum kya kar rahe honge jo hamara last aur pivot element he usko hum uski
    sahi position par place kar denge means usse chote use pehle and usse bade uske baad
    3. to iske liye ek for loop lagayenge ke jo start se end-1 tak honga and jo check karenge
    ki element pivot se bada he ya chota agar chota he to jo manual iterator banaya he usko
    increment karte jayenge take jab bada element mile uske saath swap karte karte usko last
    me pahucha sake.
    4. function return karenga correct position/Index of pivot element jo ki hamara manuall
    iterator tai karenga

quickSort Function:
    1. Ye function bus pivot ke pehle and baad ke array element ke liye call karte jayenga


*/

#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[end]; //last element
    int i = start - 1;    // itreator for swapping and returning corect index

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            if (i != j)
            {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {

        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1); // left elements
        quickSort(arr, pi + 1, end);   // right elements

        // merge(arr,start,mid,end); // starting from small array merging them in sorted order
    }
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}