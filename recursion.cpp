#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n < 2){
        return 1;
    }
    return fibonacci(n-2) + fibonacci(n-1);

    /*
    fib(5)
    fib(4) + fib(3)
    fib(2) + fib(3) + fib(2) + fib(3)
    */
}

int factorial(int n){
    if (n<=1){
        return 1;
    }
    return n * factorial(n-1);

    /*
    4 * factorial( 4-1 )
    4 * 3 * factorial( 3-1 )
    4* 3 * 2 * factorial( 2-1 )
    4 * 3 * 2 * 1
    */
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"The term in fibonacci sequence at position "<<n<< " is "<<fibonacci(n)<<endl;
    cout<<"The factorial of "<<n<< " is "<<factorial(n)<<endl;
    return 0;
}