#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    // when no arg pass
    Complex()
    {
        a = 0;
        b = 0;
    }

    // when both arg pass
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }

    // when one arg pass
    Complex(int x)
    {
        a = x;
        b = 0;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    Complex c1(4, 6);
    c1.printNumber();

    Complex c2(5);
    c2.printNumber();

    Complex c3;
    c3.printNumber();
    return 0;
}
/*

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ constructorOverloading.cpp -o constructorOverloading } ; if ($?) { .\constructorOverloading }
Your number is 4 + 6i
Your number is 5 + 0i
Your number is 0 + 0i

*/