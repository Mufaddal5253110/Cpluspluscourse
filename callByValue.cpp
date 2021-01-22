#include<iostream>
using namespace std;

void swap(int x, int y){
    int temp = x;
    x=y;
    y=temp;
}

int main(){
    int a=4,b=5;
    cout<<"BeforeSwap: "<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<"AfterSwap: "<<a<<" "<<b;
    return 0;
}