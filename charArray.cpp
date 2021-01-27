#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    cin.ignore(); // use after cin if there is use of getline() function to take input for ignoring space or enter

    //Initializing char array
    char *arr = new char[n+1];

    //Taking input of char array
    cout << "Enter char: ";
    // // cin>>arr;
    cin.getline(arr,n);
    

    //Output of char array
    cout << endl
         << arr;

    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ charArray.cpp -o charArray } ; if ($?) { .\charArray }
10
Enter char: do or die

do or die

*/