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
            // ary[i][j] is then rewritten as ary[i*sizeY+j];
            cin >> arr[i][j];
        }
    }
    cout << "\n\n";

    //Simple output of 2-D array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // ary[i][j] is then rewritten as ary[i*sizeY+j];
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";

    //Spiral order output
    int row_start = 0, row_end = row - 1, col_start = 0, col_end = col - 1;
    while (row_start <= row_end && col_start <= col_end)
    {
        //first row
        for (int cl = col_start; cl <= col_end; cl++)
        {
            cout << arr[row_start][cl] << " ";
        }
        row_start++;
        //last column
        if (row_start <= row_end && col_start <= col_end)
            for (int ro = row_start; ro <= row_end; ro++)
            {
                cout << arr[ro][col_end] << " ";
            }
        col_end--;
        //last row
        if (row_start <= row_end && col_start <= col_end)
            for (int cl = col_end; cl >= col_start; cl--)
            {
                cout << arr[row_end][cl] << " ";
            }
        row_end--;
        //first column
        if (row_start <= row_end && col_start <= col_end)
            for (int ro = row_end; ro >= row_start; ro--)
            {
                cout << arr[ro][col_start] << " ";
            }
        col_start++;
    }

    //deallocate the array
    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ spiralOrderMatrix.cpp -o spiralOrderMatrix } ; if ($?) { .\spiralOrderMatrix }
3 4
Enter Elements:
1 2 3 4
5 6 7 8
9 10 11 12


1 2 3 4
5 6 7 8
9 10 11 12


1 2 3 4 8 12 11 10 9 5 6 7 

*/