#include<iostream>
using namespace std;

int main(){
    int i=1 , a=6;
    do
    {
        int b = a*i;
        printf("%d x %d = %d\n",a,i,b);
        i++;
    } while (i<11);
    
    return 0;
}

