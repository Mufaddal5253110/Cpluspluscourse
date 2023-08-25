#include <iostream>
#include <fstream>
#include <ifstream>
#include <bitset>
#include <complex>
using namespace std;

int main()
{
    // Formatting

    cout << 34 << endl; // 34
    cout.setf(ios::oct, ios::basefield);
    cout << 34 << endl; // 42
    cout.setf(ios::showbase);
    cout << 34 << endl; // 042
    cout.setf(ios::hex, ios::basefield);
    cout << 34 << endl; // 0x22

    cout.unsetf(ios::showbase);
    cout << 34 << endl; // 22

    cout.setf(ios::dec, ios::basefield);
    cout.width(10);
    cout << 26 << endl; //        26
    cout.setf(ios::left, ios::adjustfield);

    // Floating point value
    cout.setf(ios::scientific, ios::floatfield);
    cout << 340.1 << endl; // 3.481000e+002
    cout.setf(ios::fixed, ios::floatfield);
    cout << 340.1 << endl; // 340.100000
    cout.precision(3);
    cout << 340.1 << endl; // 340.100

    int i;
    cin.setf(ios::hex, ios::basefield);
    cin >> i;          // Enter: 12
    cout << i << endl; // i==18
    ios::fmtflags f = cout.flags();
    cout.flags(ios::oct | ios::showbase); 
    cout << i << endl; //022

    // unformated IO part remaning
}