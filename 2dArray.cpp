/*
Dynamic analyzation of ad array
*/
#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    //allocate the array
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];

    cout << "Enter Elements:" << endl;

    // Taking input of 2-D array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "\n\n";

    //Output of 2-D array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //deallocate the array
    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ 2dArray.cpp -o 2dArray } ; if ($?) { .\2dArray }
3 4
Enter Elements:
1 1 1 1
2 2 2 2
3 3 3 3


1 1 1 1
2 2 2 2
3 3 3 3

*/