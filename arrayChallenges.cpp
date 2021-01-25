/*

Q: Max till i
Explanation : given an array arr[] of size n. For
every i from 0 to n-1 output max(a[0],a[1],...,a[i])

*/

// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     int n = 6;
//     int arr[] = {0,-8,1,3,-4,5};
//     int mx = arr[0];

//     for (int i = 0; i < n; i++)
//     {
//         cout<<mx<<' ';
//         mx =  max(mx,arr[i+1]);
//     }

//     return 0;
// }



/*

Q: sum of all subarrays
Explanation : given an array arr[] of size n. Output
sum of each subarray of givn array

*/

#include<iostream>
using namespace std;

int main(){
    int n = 3;
    int arr[]={1,2,2};
    for(int i= 0;i<n;i++){
        int total = 0;
        for(int j=i;j<n;j++){
            total+= arr[j];
            cout<<total<<" ";
        }
    }
    return 0;
}