#include <iostream>
using namespace std;

class Employee
{
    int id;
    static int count; // static member difens for class not for object means it will same for all objects

public:
    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is " << id << " and this is employee number " << count << endl;
    }

    static void getCount(void){ // static member function access only static member
        // cout<<id; // throws an error
        cout<<"The value of count is "<<count<<endl;
    }
};

// Count is the static data member of class Employee
int Employee::count; // Default value is 0

int main()
{
    Employee harry, rohan, lovish;

    harry.setData();
    harry.getData();
    Employee::getCount();

    rohan.setData();
    rohan.getData();
    Employee::getCount();

    lovish.setData();
    lovish.getData();
    Employee::getCount();

    return 0;
}

/*
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ static_member_memberFunction.cpp -o static_member_memberFunction } ; if ($?) { .\static_member_memberFunction }
Enter the id
1
The id of this employee is 1 and this is employee number 1
The value of count is 1
Enter the id
2
The id of this employee is 2 and this is employee number 2
The value of count is 2
Enter the id
3
The id of this employee is 3 and this is employee number 3
The value of count is 3

*/
