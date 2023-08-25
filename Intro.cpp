#include <iostream>
#include <fstream>
#include <bitset>
#include <complex>
using namespace std;

int main()
{
    // c++ Input/Output Library -- Stream
    cout << "Hello" << endl;

    // cout: a global object of ostream (typedef basic_ostreamcchar> ostream)
    //<<: ostream& ostream::operator<< (string v);
    //  endl: "\n' + flush

    // what is stream? Serial IO Interface to external devices (file, stdin/stdout, network, etc.)
    string s("Hello");
    s[3] = 't'; // Random access
    // cout[3] = 't'; // Error
    {

        ofstream of("MyLog.txt"); // Creates a new file for write, if the file didn't exist
        of << "Experience is the mother of wisdom" << endl;
        of << 234 << endl;
        of << 2.3 << endl;

        of << bitset<8>(14) << endl;      // 00001110
        of << complex<int>(2, 3) << endl; // (2,3)

    } // RAII

    // IO Operation:
    // formatting the data <-> communicating the data with external devices
    // Software Engineer Principle: Low Coupling
}