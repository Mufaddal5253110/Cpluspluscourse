#include <iostream>
#include <vector>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    int n;
    
    DSU(int nn){
        n = nn;
        parent.resize(n);
        rank.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int elem){
        if(parent[elem]==elem) return elem;
        return parent[elem]=find(parent[elem]);
    }
    
    void unionn(int a,int b){
        int parenta = find(a);
        int parentb = find(b);
        
        if(parenta == parentb) return;
        if(rank[parenta]>rank[parentb]){
            parent[parentb]=parent[parenta];
            rank[parenta]+=rank[parentb];
            
        }else{
            parent[parenta]=parent[parentb];
            rank[parentb]+=rank[parenta];
        }
    }
    
};