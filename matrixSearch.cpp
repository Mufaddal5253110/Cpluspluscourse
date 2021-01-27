#include <iostream>
using namespace std;

int main()
{

    int row, col;
    int n;
    cin >> row >> col;

    // Allocating Matrix
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    cout << "Enter elements:" << endl;

    //Matrix Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "\n";

    //Matrix Output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";

    // Matrix Search
    cout << "Enter element to search: ";
    cin >> n;

    //-------------Method-1-----------
    if (n > arr[0][0] && n < arr[row - 1][col - 1])
    {
        for (int i = 0; i < row; i++)
        {
            if (n <= arr[i][col - 1])
            {
                for (int j = 0; j < col; j++)
                {
                    if (n == arr[i][j])
                    {
                        cout << "true"<<endl<<"at index ("<<i<<", "<<j<<")";
                    }
                }
            }
        }
    }
    else
    {
        cout << "false";
    }

    //--------------Method-2--------

    int r=0,c=col-1; // Or we can write r=row-1,c=0
    bool found=false;
    while(!found && r<row-1 && c>=0){
        if(n== arr[r][c]){
            found = !found;
        }else if(n> arr[r][c]){
            r++;
        }else{
            c--;
        }
    }
    cout<<"\n"<<found;


    //Deallocating Matrix
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}