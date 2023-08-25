#include <iostream>
using namespace std;

struct Dog
{
    int age;
    string name;
};

ostream &operator<<(ostream &sm, const Dog &d)
{
    sm << "My name is " << d.name << " and my age is " << d.age << endl;
    return sm;
}

istream &operator>>(istream &sm, Dog &d)
{
    sm >> d.age;
    sm >> d.name;
    return sm;
}

int main()
{

    Dog d{2, "Tommy"};
    cout << d;
    cin >> d;
    cout << d;
    return 0;
}

/*
PS D:\Cpluspluscourse> cd "d:\Cpluspluscourse\" ; if ($?) { g++ streaming_for_class.cpp -o streaming_for_class } ; if ($?) { .\streaming_for_class }
My name is Tommy and my age is 2
10
Shummy
My name is Shummy and my age is 10
*/