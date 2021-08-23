/* HEAP
1. Kth Smallest Element :- O(nlog(k))
2. K Largest Elements :- O(nlog(k))
3. Sort K sorted Array :- O(nlog(k))
4. K closest Number :- O(nlog(k))
5. Top K frequent Number
6. Connect Ropes To minimise the cost
*/

#include <iostream>
#include <queue>
#include <map>
#include <math.h>
using namespace std;

typedef map<int, int> mii;
typedef pair<int, int> pii;

int kthsmalest(int arr[], int k, int n)
{
    // Declaring max heap
    priority_queue<int> maxh;

    for (int i = 0; i < n; i++)
    {
        maxh.push(arr[i]);
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    return maxh.top();
}

int klargestelement(int arr[], int k, int n)
{
    // Declaring min heap
    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    while (!minh.empty())
    {
        cout << minh.top() << ' ';
        minh.pop();
    }
}

void kSorted(int arr[], int k, int n)
{

    // Declaring min heap
    priority_queue<int, vector<int>, greater<int>> minh;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            arr[j] = minh.top();
            cout << minh.top() << " ";
            minh.pop();
            j++;
        }
    }

    while (!minh.empty())
    {
        arr[j] = minh.top();
        cout << minh.top() << " ";
        minh.pop();
        j++;
    }
}

void kClosest(int arr[], int k, int n, int x)
{
    // Declaring max heap
    priority_queue<pair<int, int>> maxh;

    for (int i = 0; i < n; i++)
    {
        maxh.push(make_pair(abs(x - arr[i]), arr[i]));
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }

    while (!maxh.empty())
    {
        cout << maxh.top().second << " ";
        maxh.pop();
    }
}

void topKFrequentNumber(int arr[], int k, int n)
{
    // declaring map
    mii mp; //arr[i],freq

    // O(n)
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    // Min heap
    priority_queue<pii, vector<pii>, greater<pii>> minh;

    // O(m) : m is the size of map
    for (auto m : mp)
    {
        minh.push(make_pair(m.second, m.first)); // freq,arr[i]
        if (minh.size() > k)
        {
            minh.pop();
        }
    }

    // O(k)
    while (!minh.empty())
    {
        cout << minh.top().second << " ";
        minh.pop();
    }
}

void kClosestPointsToOrigin(int arr[][2], int row, int k)
{
    // max heap
    priority_queue<pair<int, pair<int, int>>> maxh;
    for (int i = 0; i < row; i++)
    {
        int distance = sqrt((arr[i][0]) ^ 2 + (arr[i][1]) ^ 2);
        maxh.push(make_pair(distance, make_pair(arr[i][0], arr[i][1])));
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }

    while (!maxh.empty())
    {
        cout << "(" << maxh.top().second.first << "," << maxh.top().second.second << "), ";
        maxh.pop();
    }
}

int connectRope(int arr[], int n)
{
    /*
    Logic :- Add Always two minimum
    */

    // min heap
    priority_queue<int, vector<int>, greater<int>> minh;

    // ans
    int cost = 0;

    // First Push All elements in minh
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
    }

    // traverse in heap till empty
    while (!minh.empty())
    {
        // getting first minimum
        int first = minh.top();
        minh.pop();
        // cost = first;

        if (!minh.empty())
        {
            // getting second minimum
            int second = minh.top();
            minh.pop();

            // adding two minimum ropes and pushing it again in heap
            minh.push(first + second);

            // incrementing cost by adding cost of both minimum ropes
            cost = cost + first + second;
        }
    }

    return cost;
}

int main()
{
    // Kth Smallest
    int arr[] = {4, 10, 7, 3, 15, 20};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nKth(3rd) Smallest Element is :- " << kthsmalest(arr, k, n);

    // Kth Smallest
    int arr2[] = {4, 10, 7, 3, 15, 20};
    int k2 = 3;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\nK(3) Largest Elements is :- ";
    klargestelement(arr2, k2, n2);

    // Sort K sorted array
    int arr3[] = {6, 5, 3, 2, 8, 10, 9};
    int k3 = 3;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "\nSort K Sorted Array :- ";
    kSorted(arr3, k3, n3);

    // K closest element array
    int arr4[] = {5, 6, 7, 8, 9};
    int k4 = 3;
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int x = 7;
    cout << "\nK(3) closest elemnt to x(7) in array :- ";
    kClosest(arr4, k4, n4, x);

    // K frequent elements in an array
    int arr5[] = {1, 1, 1, 3, 2, 2, 4};
    int k5 = 2;
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "\nK(2) frequent elemnts in an array :- ";
    topKFrequentNumber(arr5, k5, n5);

    // K closest points to origin
    int arr6[4][2] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k6 = 2;
    // int n5 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "\nK(2) closest points to origin :- ";
    kClosestPointsToOrigin(arr6, 4, k6);

    // Connect Ropes To MINIMISE The cost
    int arr7[] = {1, 2, 3, 4, 5};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    cout << "\nMinimum Cost While connecting rope is :- " << connectRope(arr7, n7);

    return 0;
}