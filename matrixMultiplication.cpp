#include <iostream>
using namespace std;

int main()
{
    int row1, col1, row2, col2;
    cout << "Enter row and column of 1st array:" << endl;
    cin >> row1 >> col1;
    cout << "Enter row and column of 2nd array:" << endl;
    cin >> row2 >> col2;

    //allocate the array-1
    int **arr1 = new int *[row1];
    for (int i = 0; i < row1; i++)
        arr1[i] = new int[col1];
    //allocate the array-2
    int **arr2 = new int *[row2];
    for (int i = 0; i < row2; i++)
        arr2[i] = new int[col2];

    cout << "Enter Elements of 1st array:" << endl;

    // Taking input of 2-D array-1
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << "\n";

    cout << "Enter Elements of 2nd array:" << endl;
    // Taking input of 2-D array-1
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    cout << "\n\n";

    //Simple Output of 2-D array-1
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    //Simple Output of 2-D array-2
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\nMultiplication is:\n";

    //Multiplication of 2-D arrays
    for (int i = 0; i < row1; i++)
    {
        
        int currentCol=0;
        // int total = 0;
        while(currentCol<col2){
            int total = 0;
            
            for (int j = 0; j < col1; j++)
            {
                total += arr1[i][j] * arr2[j][i];
                // cout << arr1[i][j] * arr2[j][i] << " ";
            }
            cout << total << " ";
            currentCol++;
        }

        cout << endl;
    }

    //deallocate the array-1
    for (int i = 0; i < row1; i++)
        delete[] arr1[i];
    delete[] arr1;
    //deallocate the array-2
    for (int i = 0; i < row2; i++)
        delete[] arr2[i];
    delete[] arr2;

    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ matrixMultiplication.cpp -o matrixMultiplication } ; if ($?) { .\matrixMultiplication }
Enter row and column of 1st array:
3 4
Enter row and column of 2nd array:
4 3
Enter Elements of 1st array:
1 1 1 1
2 2 2 2
3 3 3 3

Enter Elements of 2nd array:
4 4 4
5 5 5
6 6 6
7 7 7


1 1 1 1
2 2 2 2
3 3 3 3


4 4 4
5 5 5
6 6 6
7 7 7


Multiplication is:
22 22 22
44 44 44 
66 66 66

*/