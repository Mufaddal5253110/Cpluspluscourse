/*********************************** OOPS in C++ ************************/

#include <iostream>
using namespace std;

//Classes have objects which have the same data type as defined in the class
class Student
{

    string name; //Private members
    int age;
    bool gender;

public:
    // int age;  Public members
    // bool gender;

    /* Constructors in C++ */
    Student()
    {
        cout << "Default constructor\n";
    } // Default constructor(used to initialize object without passing values)

    Student(string s, int a, bool g)
    {
        cout << "Parametrised constructor\n";
        name = s;
        age = a;
        gender = g;
    } // Parametrised constructor

    Student(Student &copy)
    {
        /*To copy the class objects we use the copy constructor. Here a student object is
        passed, it initializes the values to the new object.*/
        cout << "Copy Constructor\n";
        name = copy.name;
        age = copy.age;
        gender = copy.gender;
    } // Copy Constructors

    /* Destructors in C++ */
    ~Student()
    {
        /*
        Invoked when the object goes out of scope or is explicitly destroyed by a call to
        delete.
        */
        cout << "Destructor called\n";
    }

    /****Geters**** Getters are public functions used to get private data members in the class.*/
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    bool getGender()
    {
        return gender;
    }

    /****Seters**** Setters are public functions used to set private data members in the class*/
    void setName(string name)
    {
        name = name;
    }
    void setAge(int Age)
    {
        Age = Age;
    }
    void setGender(bool gender)
    {
        gender = gender;
    }

    /****Opretor Overloading****
    We can overload operators( == , + , - ,etc), to work on class objects.
    */
    bool operator==(Student &student)
    {

        if (name == student.name &&
            age == student.age &&
            gender == student.age)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Student student1;
    Student student2("muff", 20, 0);

    // Student arr[5] = {
    //     Student("muff", 20, 0),
    //     Student("uuf", 21, 1),
    //     Student("luuf", 22, 1),
    //     Student("tuuf", 23, 0),
    //     Student("suuf", 24, 1),
    // }; //Getting error

    cout << "Data Table\n\n";
    for (int i = 0; i < 5; i++)
    {
        // student1 = Student("muff",20,0);
        // student1 = arr[i];
        student1 = student2;
        cout << "Name: " << student1.getName() << endl;
        cout << "Age: " << student1.getAge() << endl;
        cout << "Gener: " << student1.getGender() << endl<<endl;
    }

    return 0;
}