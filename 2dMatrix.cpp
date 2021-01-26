#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    //allocate the array
    int* arr = new int[row * col];

    cout << "Enter Elements:" << endl;

    // Taking input of 2-D array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // ary[i][j] is then rewritten as ary[i*sizeY+j];
            cin>>arr[i*col+j];
        }
    }
    cout<<"\n\n";

    //Output of 2-D array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // ary[i][j] is then rewritten as ary[i*sizeY+j];
            cout<<arr[i*col+j]<<" ";
        }
        cout<<endl;
    }

    //deallocate the array
    delete[] arr;
    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ 2dMatrix.cpp -o 2dMatrix } ; if ($?) { .\2dMatrix }
3 4
Enter Elements:
1 1 1 1
2 2 2 2
3 3 3 3


1 1 1 1 
2 2 2 2
3 3 3 3

*/