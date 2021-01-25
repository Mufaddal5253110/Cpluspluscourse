/*
Idea: Find the min element in unsorted array and swap
it with element at begining
Time complexity: O(N^2)
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 11;
    int arr[] = {12, 45, 23, 51, 19, 8,234,1,278,29,13};

    for(int i=0;i<n-1;i++){ // loop goes through whole array 
        for(int j=i+1;j<n;j++){ // loop goes through unsorted array
            if(arr[i]>arr[j]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;

            }
        }
    }
    

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}