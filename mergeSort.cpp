/*
Idea: Divide the array into two parts, sort the left part and sort the right part and
merge them
Time Complexity: O(N logN)
Space Complexity: O(N) Since we need an arbitrary array as well.

Explanation Desi:
1. Merge sort me hum pure array ko half half me divide karte jaate he kab tak,jab tak
ek element nahi mil jaye , ye karte he hum recursively
2. Iske baad hum bottom se top jaate hue merge and sort karte jaate he, suppose first half
   ke last me last do element he 6 and 5 to usko merge karenge with sort means [5,6...]
3. Iske liye merge function ka use karte he jisme hum to initial dummy array define karte he
   Jisme first and second half elements of main array store karte he.
4. fir dono array me loop lagate he and baari baari compare karte he konsa element chota he and
   simultaniously main array me change karte jaate he
5. And last agar dono me se koi array ka itreator dusre wale array ke iterator se pehle pahuch
   jata he end par to dusre array ke elements main array me change karte jayenge
*/

#include <iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){


    int n1= mid-start+1; // size of first half array
    int n2 = end-mid; // size of second half array

    // Initializing two dummy array for merge in sorted order
    int* arr1 = new int[n1]; // storing the elements of first half
    for(int i=0;i<n1;i++){
        arr1[i]=arr[start+i];
    }

    int* arr2 = new int[n2]; // storing the elements of second half
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+i+1];
    }

    int i=0; // iterator for arr1
    int j=0; // iterator for arr2
    int k=start; // iterator for arr

    // loop runs untill one of n1 and n2 reach to the end
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++,k++;
        }

        if(arr1[i]>arr2[j]){
            arr[k]=arr2[j];
            j++,k++;
        }
    }

    // if n1 reach to end and not n2
    while(j<n2){
        arr[k]=arr2[j];
        j++,k++;
    }

    // if n2 reach to end and not n1
    while(i<n1){
        arr[k]=arr1[i];
        i++,k++;
    }

    delete[] arr1;
    delete[] arr2;

}

// function split array int to two half and repeating that, untill we get small array
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid); // first half
        mergeSort(arr, mid+1, end); // second half

        merge(arr,start,mid,end); // starting from small array merging them in sorted order
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }

    delete[] arr;
    return 0;
}