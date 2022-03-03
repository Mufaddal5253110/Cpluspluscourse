#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int dijkstra(int n,vector<vector<pair<int,int>>> adj){
    
    priority_queue<pii,vector<pii>,greater<pii>> minh;
    vector<int> dist(n+1,INT_MAX);
    
    dist[1]=0; // Starting from source, assuming 1 i.e. first node
    minh.push({0,1});
    
    while(!minh.empty()){
        int v = minh.top().second;
        minh.pop();
        
        for(auto elem : adj[v]){
            if(dist[elem.first]>dist[v]+elem.second){
              dist[elem.first]=dist[v]+elem.second;
              minh.push({dist[elem.first],elem.first});
            }
        }
    }
    
    return dist[n]; // Returning smallest path till N i.e. last node
    
}