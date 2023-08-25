#include <iostream>
using namespace std;


// end is a function that look like this
ostream& endl(ostream& sm){ // it is also called as manipulator
    sm.put('\n');
    sm.flush();
    return sm;
}

// how "<<" operator is overloaded and looks like
ostream& ostream::operator<<(ostream& (*func)(ostream&)){
    return (*func)(*this);
}

int main(){

    cout<<"Hello"<<endl;//'\n'
    cout << ends; //'\0'
    cout<<flush;
    cin>>ws; // read and discard white space
    cout<<setw(8)<<left<<setfill('_')<<99<<endl; //99____
    cout<<hex<<showbase<<14; //0xe
    return 0;
}

