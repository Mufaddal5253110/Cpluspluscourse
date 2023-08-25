#include <iostream>
#include <fstream>
#include <bitset>
#include <complex>
using namespace std;

int main()
{
    {
        ofstream of("MyLog.txt"); // Creates a new file for write, if the file didn't exist
        of << "Experience is the mother of wisdom" << endl;
        of << 234 << endl;
        of << 2.3 << endl;
        of << bitset<8>(14) << endl;      // 00001110
        of << complex<int>(2, 3) << endl; // (2,3)

    } // RAII

    {

        ofstream of("MyLog.txt", ofstream::app); // Move the output pointer to the end of the file
        of << "Honesty is the best policy." << endl;
    }
    {
        ofstream of("MyLog.txt", ofstream::in | ofstream::out);
        of.seekp(10, ios::beg); // Move the output pointer 10 chars after begin
        of << "--12345--";          // Overwrite 5 chars
        of.seekp(-5, ios::end); // Move the output pointer 5 chars before end
        of << "--Nothing ventured, nothing gained.--" << endl;
        of.seekp(-5, ios::cur); // Move the output pointer 5 chars before current position
    }
}