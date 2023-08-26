#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add<int>(2, 5) << endl;
    cout << add<float>(2.5, 3.6) << endl;
    return 0;
}

/*
PS D:\Cpluspluscourse> cd "d:\Cpluspluscourse\" ; if ($?) { g++ stl_basic.cpp -o stl_basic } ; if ($?) { .\stl_basic }
7
6.1
*/