#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void getData()
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << imaginary << endl
             << endl;
    }

    void setData(int a, int b)
    {
        real = a;
        imaginary = b;
    }
};

int main()
{

    //!Declaraion of class objects

    //Method-1 using object
    Complex c1;
    c1.setData(3, 4);
    c1.getData();

    //Method-2 using pointers and object
    Complex *ptr = &c1;
    (*ptr).setData(5, 6);
    (*ptr).getData();

    //Method-3 using pointers only
    Complex *ptr2 = new Complex;
    ptr2->setData(8, 6);
    ptr2->getData();

    //Method-3 Array of objects using pointers only
    Complex *ptr3 = new Complex[4];
    for (int i = 0; i < 4; i++)
    {
        (ptr3+i)->setData(i+4, i+3);
        (ptr3+i)->getData();
    }

    return 0;
}