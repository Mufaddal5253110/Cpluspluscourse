#include <iostream>
using namespace std;

int main()
{

    // //-------------Check for Palindrome---------
    // int n;

    // cout << "Enter length: ";
    // cin >> n;

    // char *arr = new char[n + 1];

    // cout << "Enter Word: ";
    // cin >> arr;

    // bool isPalindrome = true;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != arr[n - 1 - i])
    //     {
    //         isPalindrome = !isPalindrome;
    //         break;
    //     }
    // }
    // if (isPalindrome)
    //     cout << "Palindrome";
    // else
    //     cout << "Not Palindrome";

    // /*OUTPUT

    // PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ charArrayExamples.cpp -o charArrayExamples } ; if ($?) { .\charArrayExamples }
    // Enter length: 5
    // Enter Word: Madam
    // Not Palindrome
    // PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ charArrayExamples.cpp -o charArrayExamples } ; if ($?) { .\charArrayExamples }
    // Enter length: 5
    // Enter Word: madam
    // Palindrome

    // */

    // ------------------Printing longest length and word from sentence--------------

    int n;

    cout << "Enter Sentance Length: ";
    cin >> n;
    cin.ignore();

    char *arr = new char[n + 1];

    cin.getline(arr, n);

    cout<<endl;

    // char* ele = arr;
    int firstindex = 0, lastIndex = 0;
    int currentLen = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currentLen > maxLen)
            {
                maxLen = currentLen;
                lastIndex = firstindex;
            }
            firstindex = i+1;
            currentLen = 0;
        }
        else
            currentLen++;

        if (arr[i] == '\0')
            break;
    }

    for(int i=0;i<maxLen;i++){
        cout<<arr[lastIndex +i];
    }
    cout<<endl<<maxLen;

    /*OUTPUT
    
    Enter Sentance Length: 10
    do or die

    die
    3

    */

    return 0;
}