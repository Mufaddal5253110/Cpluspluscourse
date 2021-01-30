#include <iostream>
using namespace std;

/*
given an array of distinct integers find permutation
*/

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void permutation(int *arr, int fact, int len, int i)
{
    if (fact == 0)
    {
        return;
    }
    if (i == len - 1)
    {
        i = 0;
    }

    if (arr[i] != arr[i + 1])
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;

        cout << "(";
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] << ",";
        }
        cout << ")";
    }
    permutation(arr, fact - 1, len, i + 1);
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

    cout << "(";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ",";
        }
        cout << ")";

    permutation(arr, factorial(n)-1, n, 0);

    return 0;
}