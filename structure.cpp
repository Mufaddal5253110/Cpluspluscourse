#include<iostream>
using namespace std;

/*Method 1

struct employee
{
    
    int eId; 
    char favChar; 
    float salary; 
};

 int main() {
     struct employee monty;
     monty.eId = 1;
     monty.favChar = 'c';
     monty.salary = 120000000;
     cout<<"The value is "<<monty.eId<<endl; 
     cout<<"The value is "<<monty.favChar<<endl; 
     cout<<"The value is "<<monty.salary<<endl; 
     return 0;
}

*/

/*Method 2
*/

typedef struct employee
{
    /* data */
    int eId; //4
    char favChar; //1
    float salary; //4
} ep;

int main(){
ep monty;
    struct employee shubham;
    struct employee rohanDas;
    monty.eId = 1;
    monty.favChar = 'c';
    monty.salary = 120000000;
    cout<<"The value is "<<monty.eId<<endl; 
    cout<<"The value is "<<monty.favChar<<endl; 
    cout<<"The value is "<<monty.salary<<endl; 
    return 0;
}