#include<iostream>
using namespace std;

/*
Inline function use only when, the function is small and use many times in program  
*/
inline int product(int a, int b){
    return a*b;
}

int main(){
    int a, b;
    cout<<"Enter the value of a and b"<<endl;
    cin>>a>>b;
    cout<<"The product of a and b is "<<product(a,b)<<endl;
    cout<<"The product of a and b is "<<product(a,b)<<endl;
    
    return 0;
}