#include<iostream>
using namespace std;

// position represent from left

int getBit(int n, int pos){
    return ((n>>pos) & 1);
}

int setBitToOne(int n, int pos){
    return (n | (1<<pos));
}


int main(){
    getBit(5,1);
    return 0;
}