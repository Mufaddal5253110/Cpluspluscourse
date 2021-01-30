#include <iostream>
using namespace std;

/*
Check if an array is sorted or not
*/
bool checkSorted(int arr[], int n)
{
    if (n == 1)
        return 1;
    return arr[0] <= arr[1] && checkSorted(arr + 1, n - 1);
}

/*
Find first and last occurance of element in an array
*/
int firstOccurance(int arr[], int n, int len)
{
    if (arr[0] == n)
        return 1;
    if (len > 0)
        return 1 + firstOccurance(arr + 1, n, len - 1);
}

int lastOccurance(int arr[], int key, int lastindex, int len)
{
    if (arr[lastindex] == key)
        return lastindex;
    if (len > 0)
        return lastOccurance(arr, key, lastindex - 1, len);
}

/*
Reverse a string using recursion
*/
string reverseString(string str, int position)
{
    if (position >= 0)
        return str[position] + reverseString(str, position - 1);
    else
        return "";
}

/*
Replace pi with 3.14 in string
*/
string replacePI(string str, int firstPosition)
{
    if (firstPosition <= str.length() - 1)
    {

        if ((str[firstPosition] == 'p' && str[firstPosition + 1] == 'i'))
            return "3.14" + replacePI(str, firstPosition + 2);

        else
            return str[firstPosition] + replacePI(str, firstPosition + 1);
    }
    else
        return "";
}

/*
Move all x to the end of the string
*/

string movetoEnd(string str, char ch, int position)
{
    if (position < str.length())
    {
        if (str[position] == ch)
            return movetoEnd(str, ch, position + 1) + str[position];
        else
            return str[position] + movetoEnd(str, ch, position + 1);
    }
    else
        return "";
}

/*
Generate all substrings of string
*/
void generateSubstring(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << " ";
        return;
    }

    char first = str[0];
    string rest = str.substr(1);

    generateSubstring(rest, ans);
    generateSubstring(rest, ans + first);
}

/*
Permutation of string
*/

void stringPermutation(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << " ";
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        char first = str[i];
        string rest = str.substr(0, i) + str.substr(i + 1);
        stringPermutation(rest, ans + first);
    }
}

/*
Count the number of path possible in maze
explanation: at every position whether it will move to x direction or in -y direction
*/

int countPath(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return 1;
    if (i >= n || j >= n)
        return 0;
    return countPath(n, i + 1, j) + countPath(n, i, j + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4, 4, 3, 5};
    string str = "binod";
    string str2 = "pippxxppiixipi";
    string str3 = "axxbdxcefxhix";
    string str4 = "ABC";
    int n = 9;
    cout << checkSorted(arr, n) << endl;
    cout << firstOccurance(arr, 4, n) - 1 << endl;
    cout << lastOccurance(arr, 4, 7, n) << endl;
    cout << reverseString(str, str.length() - 1) << endl;
    cout << replacePI(str2, 0) << endl;
    cout << movetoEnd(str3, 'x', 0) << endl;
    generateSubstring(str4, "");
    cout << endl;
    stringPermutation(str4, "");
    cout << endl<< countPath(4,0,0);

    return 0;
}