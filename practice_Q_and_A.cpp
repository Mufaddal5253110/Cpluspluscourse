#include<iostream>
using namespace std;

// int &fun()
// {
//     static int x = 10;
//     return x;
// }
// int main()
// {
//     fun() = 30;
//     cout << fun();
//     return 0;
// }
// // Output:30


// int fun(int &x)
// {
// 	return x;
// }
// int main()
// {
// 	//Solution
// 	// int a = 10;
// 	//cout<< fun(a);
// 	cout << fun(10);
// 	return 0;
// }


// void swap(char * &str1, char * &str2)
// {
// char *temp = str1;
// str1 = str2;
// str2 = temp;
// }

// int main()
// {
// char *str1 = "GEEKS";
// char *str2 = "FOR GEEKS";
// swap(str1, str2);
// cout<<"str1 is "<<str1<<endl;
// cout<<"str2 is "<<str2<<endl;
// return 0;
// }
// // output:
// // str1 is FOR GEEKS
// // str2 is GEEKS



// int main()
// {
// int x = 10;
// int* ptr = &x;
// int &*ptr1 = ptr; //pointer to refrence is not allowed
// }

// int main()
// {
//    int *ptr = NULL;
//    int &ref = *ptr; // refrence can be null but can't define void
//    cout << ref;
// }


