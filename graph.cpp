/*
A Graph consists of a finite set of vertices(or nodes) and set of Edges which connect a pair of nodes

----Graph and its representations----
1. Adjacency Matrix 
    - delete/Insert/Query: O(1)
    - space : O(v^2)
    - Adding a vertex is O(V^2)
2. Adjacency List 
    - delete/Query: O(V)
    - insert: O(1);
    - space : O(|V|+|E|)
    - Adding a vertex is easier
3. Incidence Matrix
4. Incidence List
*/

#include<iostream>
#include<vector>
using namespace std;

// -------------- Adjacency Matrix----------
void add_edge(int arr[5][5],int a, int b){
    arr[a][b] = 1;
    arr[b][a] = 1;

}

void printAdjencyMatrix(int arr[5][5],int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


// -------------- Adjacency List----------
// Using arrays of vector

void add_edge_2(vector<int> arr[],int a,int b){
    arr[a].push_back(b);
    arr[b].push_back(a);

}

void printAdjancyList(vector<int> arr[],int v){
    for(int i=0;i<v;i++){
        cout<<"\nAdjacency list of vertex "<<i<<"\nhead";
        for(auto elem:arr[i]){
            cout<<" -> "<<elem;
        }
    }
}


int main(){

    // -------------- Adjacency Matrix----------
    int adj_mat[5][5] = {0};
    add_edge(adj_mat,0,1);
    add_edge(adj_mat,0,4);
    add_edge(adj_mat,1,2);
    add_edge(adj_mat,1,3);
    add_edge(adj_mat,1,4);
    add_edge(adj_mat,2,3);
    add_edge(adj_mat,3,4);
    printAdjencyMatrix(adj_mat,5);

    // -------------- Adjacency List----------
    // Using arrays of vector

    int v = 5;
    vector<int> adj_list[v];
    add_edge_2(adj_list,0,1);
    add_edge_2(adj_list,0,4);
    add_edge_2(adj_list,1,2);
    add_edge_2(adj_list,1,3);
    add_edge_2(adj_list,1,4);
    add_edge_2(adj_list,2,3);
    add_edge_2(adj_list,3,4);
    printAdjancyList(adj_list,v);


    return 0;
}