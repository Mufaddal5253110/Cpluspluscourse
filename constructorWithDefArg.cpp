#include <iostream>
using namespace std;

class Simple
{
    int data1;
    int data2;
    int data3;

public:
    Simple(int a, int b = 9, int c = 8)
    { // default arg means if not data has pass than default arg will overcome
        data1 = a;
        data2 = b;
        data3 = c;
    }

    void printData();
};

void Simple ::printData()
{
    cout << "The value of data1, data2 and data3 is " << data1 << ", " << data2 << " and " << data3 << endl;
}

int main()
{
    Simple s(12, 13);
    s.printData();
    return 0;
}

/*
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ constructorWithDefArg.cpp -o constructorWithDefArg } ; if ($?) { .\constructorWithDefArg }
The value of data1, data2 and data3 is 12, 13 and 8
*/
