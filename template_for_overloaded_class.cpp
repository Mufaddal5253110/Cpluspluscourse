#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class Tempo
{
public:
    Tempo(T a)
    {
        cout << a << " is not a charachter!" << endl;
    }
};

template <>
class Tempo<char>
{
public:
    Tempo(char a)
    {
        cout << a << " is indeed a charachter!\n";
    }
};

int main()
{
    Tempo<float> obj1(2.5);
    Tempo<int> obj2(3);
    Tempo<char> obj3('j');

    return 0;
}

/*
PS D:\Cpluspluscourse> cd "d:\Cpluspluscourse\" ; if ($?) { g++ template_for_overloaded_class.cpp -o template_for_overloaded_class } ; if ($?) { .\template_for_overloaded_class }
2.5 is not a charachter!
3 is not a charachter!
j is indeed a charachter!
*/