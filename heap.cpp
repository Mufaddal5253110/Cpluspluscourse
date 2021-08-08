/* HEAP
1. Kth Smallest Element :- O(nlog(k))

*/


#include<iostream>
#include<queue>
using namespace std;

int kthsmalest(int arr[],int k,int n){
    // Declaring max heap
    priority_queue<int> maxh;
    
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size() > k){
            maxh.pop();
        }
    }
    return maxh.top();
}

int main(){
    // Kth Smallest
    int arr[] = {4,10,7,3,15,20};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"\nKth Smallest Element is (3rd) :- "<<kthsmalest(arr,k,n);

    return 0;
}