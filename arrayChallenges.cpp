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

// #include<iostream>
// using namespace std;

// int main(){
//     int n = 3;
//     int arr[]={1,2,2};
//     for(int i= 0;i<n;i++){
//         int total = 0;
//         for(int j=i;j<n;j++){
//             total+= arr[j];
//             cout<<total<<" ";
//         }
//     }
//     return 0;
// }

/*

Q: Longest arithematic subarray
Problem:
An arithmetic array is an array that contains at least two integers and the
differences between consecutive integers are equal. For example, [9, 10], [3, 3, 3],
and [9, 7, 5, 3] are arithmetic arrays, while [1, 3, 3, 7], [2, 1, 2], and [1, 2, 4] are
not arithmetic arrays.

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 7;
    int arr[] = {10,7,4,6,8,10,11};
    int ans = 0;
    int x = 0;

    for (int i = 1; i < n-1; i++)
    {
        int diff = arr[i] - arr[i-1];
        if(arr[i+1]-arr[i] == diff){
            x++;
            
        }else{
            diff=arr[i+1]-arr[i];
            x=0;
        } 
        ans = max(ans, x);
        
        
    }
    cout << ans+2;

    return 0;
}