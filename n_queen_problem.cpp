#include <iostream>
using namespace std;

// function to check whether we can place queen or not
bool checkPlace(int **arr, int i, int j, int n)
{
    for (int row = 0; row < i; row++)
    { // loop on each row and checking whwther it has queen(means 1) or not
        if (arr[row][j] == 1)
        {
            return false;
        }
    }

    // checking in left diganolly upward direction
    int row = i;
    int col = j;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    // checking in right diganolly upward direction
    row = i;
    col = j;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool placeNQueen(int **arr, int i, int n)
{
    if (i >= n)
    { // means we have placed our all queens
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (checkPlace(arr, i, col, n))
        { // checking wether place is safe for queen or not and placing in first row
            arr[i][col] = 1;

            if (placeNQueen(arr, i + 1, n))
            { // placing in remaining rows
                return true;
            }

            arr[i][col] = 0; //Backtracking
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    // Initializing solution array with all elements 0
    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (placeNQueen(solArr, 0, n))
    {
        //Outputing solution array
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    delete[] solArr;

    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ n_queen_problem.cpp -o n_queen_problem } ; if ($?) { .\n_queen_problem }
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ n_queen_problem.cpp -o n_queen_problem } ; if ($?) { .\n_queen_problem }
5
1 0 0 0 0 
0 0 1 0 0
0 0 0 0 1 
0 1 0 0 0
0 0 0 1 0

*/