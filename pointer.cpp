#include<iostream>
using namespace std;

int main(){
    int a= 3;
    int* b= &a;
    int ** c = &b;

    cout<< "Value of a is "<<a<<endl;
    cout<< "Value of b is "<<b<<endl;
    cout<< "Value of c is "<<c<<endl;

    cout<< "Value at address b is "<< *b<<endl;
    cout<< "Value at address c is "<< **c<<endl;

    return 0;
}