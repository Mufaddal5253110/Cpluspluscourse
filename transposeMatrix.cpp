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
    cout<<"\n\n";

    //Transpose of 2-D array
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[j][i] << " ";
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

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ transposeMatrix.cpp -o transposeMatrix } ; if ($?) { .\transposeMatrix }
3 4
Enter Elements:
1 2 3 4
5
6 7 8
9 10 11 12


1 2 3 4
5 6 7 8
9 10 11 12


1 5 9
2 6 10
3 7 11
4 8 12

*/