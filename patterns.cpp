#include <iostream>
using namespace std;

void rectangularPatter(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void hollowRectangularPatter(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(i==0 || j==0 || i== row-1 || j==col-1){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void invertedHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void halfPyramidAfter180Rotation(int n)
{
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(j<=n-i){
                cout<<"  ";
            }else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}

void halfPyramidUsingNumbers(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void floydsTriangle(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

void butterflyPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"* ";
        }
        int noOfSpace = 2*n - 2*i;
        for (int j = 0; j < noOfSpace; j++)
        {
            cout<<"  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<"* ";
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"* ";
        }
        int noOfSpace = 2*n - 2*i;
        for (int j = 0; j < noOfSpace; j++)
        {
            cout<<"  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<"* ";
        }
        cout << endl;
    }
}

int main()
{
    int row, col;
    cout << "Enter number of Rows and Columns" << endl;
    cin >> row >> col;

    // Rectangular Pattern
    rectangularPatter(row, col);

    // Hollow Rectangular Pattern
    hollowRectangularPatter(row, col);

    // Inverted Half Pyramid
    invertedHalfPyramid(row);

    // Half Pyramid After 180degree Rotation
    halfPyramidAfter180Rotation(row);

    // Half Pyramid Using Numbers
    halfPyramidUsingNumbers(row);

    // Floyd's Triangle
    floydsTriangle(row);

    // Butterfly Pattern
    butterflyPattern(row);

    return 0;
}

/*

Enter number of Rows and Columns
4 5
* * * * * 
* * * * *
* * * * *
* * * * *

* * * * *
*       *
*       * 
* * * * *

* * * *
* * *
* *
*
        *
      * *
    * * *
  * * * *
1
2 2
3 3 3
4 4 4 4
1
2 3
4 5 6 
7 8 9 10
*             *
* *         * *
* * *     * * *
* * * * * * * *
* * * * * * * *
* * *     * * *
* *         * *
*             *

*/