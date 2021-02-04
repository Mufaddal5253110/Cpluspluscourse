#include <iostream>
using namespace std;

/*
Case1:
class B: public A{
   Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    Order of execution of constructor -> C() then B() and A()
};

*/

class Base1
{
    int data1;

public:
    Base1(int data)
    {
        data1 = data;
        cout << "Base1 constructor called" << endl;
    }

    void getter1();
};

class Base2
{
    int data2;

public:
    Base2(int data)
    {
        data2 = data;
        cout << "Base2 constructor called" << endl;
    }

    void getter2();
};

class Derived : public Base1, public Base2
{
    int derived1;

public:
    Derived(int a, int b, int c) : Base1(a), Base2(b)
    {
        derived1 = c;
        cout << "Derived constructor Called" << endl;
    }

    void getter3();
};

void Base1::getter1()
{
    cout << "Data1: " << data1 << endl;
}

void Base2::getter2()
{
    cout << "Data2: " << data2 << endl;
}

void Derived::getter3()
{
    cout << "Derived1: " << derived1 << endl;
}

int main()
{
    Derived d(5, 6, 7);
    d.getter1();
    d.getter2();
    d.getter3();

    return 0;
}

/*OUTPUT
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ advanceConstructor.cpp -o advanceConstructor } ; if ($?) { .\advanceConstructor }
Base1 constructor called
Base2 constructor called
Derived constructor Called
Data1: 5
Data2: 6
Derived1: 7
*/