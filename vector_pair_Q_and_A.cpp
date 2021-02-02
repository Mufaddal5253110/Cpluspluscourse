#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Print Index of thier sorted order
*/

bool myCompare(pair<int,int> p1 , pair<int,int> p2){
    return p1.second<p2.second;
}

int main()
{

    int n;
    cin >> n;

    vector<int> v(n);
    vector<pair<int, int>> p;

    // taking vector input
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << endl
         << "Main Array\\Vector"<<endl;
    // vector output
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    // Initializing pair vetor elements
    for (int i = 0; i < n; i++)
    {
        p.push_back(make_pair(i,v[i]));
    }


    // giving correct index according to thier order
    sort(p.begin(),p.end(),myCompare);

    //Updating the original vector

    for (int i = 0; i < n; i++)
    {
        v[p[i].first]=i;
    }

    cout << endl<<endl<<"Answer"<<endl;
    // final vector output
    for (int i = 0; i < n; i++)
    {
        cout << v[i] <<" ";
    }

    return 0;
}

/*OUTPUT

PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ vector_pair_Q_and_A.cpp -o vector_pair_Q_and_A } ; if ($?) { .\vector_pair_Q_and_A }
5
4 6 2 8 1

Main Array\Vector
4 6 2 8 1

Answer
2 3 1 4 0

*/