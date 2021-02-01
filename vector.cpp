#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //iteration on vector through index
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    } // 1 2 3

    //iteration on vector through element or iterator
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    } // 1 2 3 

    v.pop_back();
    
    //iteration on vector through element
    for(auto element:v){
        cout<<element<<" ";
    } // 1 2 3 

    return 0;
}