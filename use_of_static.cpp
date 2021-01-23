#include<iostream>
using namespace std;

int product(int a, int b){ // don't use inline with static
    static int c = 0; // This executes only once
    c += 1; // Next time this function is run, the value of c will be retained
    return a*b + c;
}

int main(){
    int a, b;
    cout<<"Enter the value of a and b"<<endl;
    cin>>a>>b;
    cout<<"The product of a and b is "<<product(a,b)<<endl;
    cout<<"The product of a and b is "<<product(a,b)<<endl;
    return 0;
}