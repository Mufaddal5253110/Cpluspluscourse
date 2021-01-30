// concept Desi : Sab try karo fir sahi chuno!

/*
Rat in maze
*/

#include <iostream>
using namespace std;

void getPath(int **arr, int **solnArray, int n, int i, int j)
/*
AIM : Find currect path to reach at end
Note :  Q => 0-block,1-Path
        A => 1-correctPath
        +x => forward
        +y => downward
*/
{
    solnArray[i][j] = 1; // onstarting we are assuming that we can move forward
    if (i == n - 1 && j == n - 1)
    {
        solnArray[i][j] = 1;
        return;
    }
    else if (arr[i + 1][j] != 0 && arr[i][j + 1] != 0) // Wether we can move in both +x and +y direction
    {
        solnArray[i + 1][j] = 1;
        solnArray[i][j + 1] = 1;
        getPath(arr, solnArray, n, i + 1, j);
        getPath(arr, solnArray, n, i, j + 1);
    }

    else if (arr[i + 1][j] != 0 && arr[i][j + 1] == 0) // we can only move in +x direction
    {
        solnArray[i + 1][j] = 1;
        getPath(arr, solnArray, n, i + 1, j);
    }

    else if (arr[i][j + 1] != 0 && arr[i + 1][j] == 0) // we can only move in +y direction
    {
        solnArray[i][j + 1] = 1;
        getPath(arr, solnArray, n, i, j + 1);
    }
    // Backtracking
    else if ((arr[i + 1][j] == 0 && arr[i][j + 1] == 0) || // +x and +y both are blocked
             (arr[i + 1][j] >= n && arr[i][j + 1] == 0) || // +x is at column end and +y is blocked
             (arr[i][j + 1] >= n && arr[i + 1][j] == 0))   // +y is at row end and +x is blocked
    {
        solnArray[i][j] = 0;
    }
}

int main()
{
    int n;
    cin >> n;

    //Initializing maze array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // taking maze array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl
         << endl;
    //Outputing maze array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Initializing solution array with all elements zero
    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }
    cout << endl;

    // Updating solution array
    getPath(arr, solArr, n, 0, 0);

    //Outputing solution array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }

    delete[] arr;
    delete[] solArr;
    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ backTracking.cpp -o backTracking } ; if ($?) { .\backTracking }
5
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1


1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1 

1 0 0 0 0
1 1 1 1 0
0 0 0 1 0
0 0 0 1 1
0 0 0 0 1

*/