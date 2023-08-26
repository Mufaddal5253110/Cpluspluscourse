#include <iostream>
using namespace std;

template <class T>
class Algo
{
public:
    T a[2];
    // T add()
    // {
    //     cin >> a[0] >> a[1];
    //     return a[0] + a[1];
    // };
    T add(); //Initializing Function
};

template <class T>
T Algo<T>::add() //Defining Function
{
    cin >> a[0] >> a[1];
    return a[0] + a[1];
}

int main()
{
    Algo<float> algo;
    cout << algo.add();
    return 0;
}

/*
PS D:\Cpluspluscourse> cd "d:\Cpluspluscourse\" ; if ($?) { g++ template_for_class.cpp -o template_for_class } ; if ($?) { .\template_for_class }
2.5
6
8.5
*/