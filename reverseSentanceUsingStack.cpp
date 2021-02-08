#include <iostream>
#include <stack>
using namespace std;

void reverseSentance(string s)
{
    stack<string> s1;

    string word = "";
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        s1.push(word);
    }

    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}

int main()
{
    string s = "Hey what's up, Have a nice day";
    reverseSentance(s);
    return 0;
}


/*OUTPUT
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ reverseSentanceUsingStack.cpp -o reverseSentanceUsingStack } ; if ($?) { .\reverseSentanceUsingStack }
day nice a Have up, what's Hey
*/