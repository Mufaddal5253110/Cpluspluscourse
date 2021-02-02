#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imaginary;

public:
    //Default constructor
    Complex()
    {
    }
    //Parematrised constructor
    Complex(int rl, int img)
    {
        real = rl;
        imaginary = img;
    }
    void Display()
    {
        cout << real << " + i" << imaginary;
    }

    // Operator Overloading(For addition of two complex number)
    Complex operator+(Complex &complex)
    {
        Complex result;
        result.real = real + complex.real;
        result.imaginary = imaginary + complex.imaginary;
        return result;
    }
};

int main()
{
    Complex c1(4, 5), c2(5, 6), c3;
    c3 = c1 + c2;
    c3.Display();

    return 0;
}

/*OUTPUT
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ operatorOverloading.cpp -o operatorOverloading } ; if ($?) { .\operatorOverloading }
9 + i11
*/