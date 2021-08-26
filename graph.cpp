/*
A Graph consists of a finite set of vertices(or nodes) and set of Edges which connect a pair of nodes

----Graph and its representations----
(
    V : number of vertices in the graph.
    E : number of edges in the graph.
)
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
5. BFS (Breadth First Traversal)
    - Time Complexity: O(V+E)
6. DFS (Depth First Traversal)
    - Time Complexity: O(V+E)
    - Space Complexity: O(V). 
7. Topological Sorting
*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;

// -------------- Adjacency Matrix----------
void add_edge(int arr[5][5], int a, int b)
{
    arr[a][b] = 1;
    arr[b][a] = 1;
}

void printAdjencyMatrix(int arr[5][5], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// -------------- Adjacency List----------
// Using arrays of vector

void add_edge_2(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

void printAdjancyList(vector<int> arr[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "\nAdjacency list of vertex " << i << "\nhead";
        for (auto elem : arr[i])
        {
            cout << " -> " << elem;
        }
    }
}

//-----------BFS Traversal---------
vector<int> bfsTraversal(vector<int> arr[], int v)
{
    vector<int> ans;
    vector<int> visited(v + 1, 0);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            queue<int> temp;
            temp.push(i);
            visited[i] = 1;

            while (!temp.empty())
            {
                int elem = temp.front();
                temp.pop();

                ans.push_back(elem);

                for (auto e : arr[elem])
                {
                    if (visited[e] == 0)
                    {
                        temp.push(e);
                        visited[e] = 1;
                    }
                }
            }
        }
    }

    return ans;
}


//-----------DFS Traversal---------
void dfsRecursion(int index, vector<int> &ans,vector<int> &visited,vector<int> arr[])
{
    visited[index] = 1;
    ans.push_back(index);
    for (auto elem : arr[index])
    {
        if (visited[elem] == 0)
        {
            dfsRecursion(elem, ans, visited,arr);
        }
    }
    
}

vector<int> dfsTraversal(vector<int> arr[], int v)
{
    vector<int> ans;
    vector<int> visited(v + 1, 0);

    dfsRecursion(0, ans, visited,arr);

    return ans;
}

//-----------TopoLogical Sorting---------

void topologicalRecursion(int index,stack<int> &st,vector<int> &visited,vector<int> arr[]){
    for(auto elem : arr[index]){
        if(visited[elem] == 0){
            topologicalRecursion(elem,st,visited,arr);
        }
    }
    st.push(index);
    visited[index] = 1;
}

vector<int> topologicalSorting(vector<int> arr[], int v)
{
    vector<int> ans;
    vector<int> visited(v + 1, 0);
    stack<int> st;

    topologicalRecursion(0, st, visited,arr);

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{

    /* GRAPH
        0 - 1 - 2
        | / |  /
        4 - 3 
    */

    // -------------- Adjacency Matrix----------
    int adj_mat[5][5] = {0};
    add_edge(adj_mat, 0, 1);
    add_edge(adj_mat, 0, 4);
    add_edge(adj_mat, 1, 2);
    add_edge(adj_mat, 1, 3);
    add_edge(adj_mat, 1, 4);
    add_edge(adj_mat, 2, 3);
    add_edge(adj_mat, 3, 4);
    cout << "Adjency Matrix" << endl;
    printAdjencyMatrix(adj_mat, 5);

    // -------------- Adjacency List----------
    // Using arrays of vector
    int v = 5;
    vector<int> adj_list[v];
    add_edge_2(adj_list, 0, 1);
    add_edge_2(adj_list, 0, 4);
    add_edge_2(adj_list, 1, 2);
    // add_edge_2(adj_list, 1, 3);
    // add_edge_2(adj_list, 1, 4);
    // add_edge_2(adj_list, 2, 3);
    add_edge_2(adj_list, 3, 4);
    cout << "\nAdjency List\n";
    printAdjancyList(adj_list, v);

    // BFS Traversal
    vector<int> bfs = bfsTraversal(adj_list, v);
    cout << "\nBFS Traversal \n";
    for (auto e : bfs)
    {
        cout << e << " ";
    }

    // DFS Traversal
    vector<int> dfs = dfsTraversal(adj_list, v);
    cout << "\nDFS Traversal \n";
    for (auto e : dfs)
    {
        cout << e << " ";
    }

    // TopoLogical Sorting
    // vector<int> topology = topologicalSorting(adj_list, v);
    // cout << "\nTopoLogical Sorting \n";
    // for (auto e : topology)
    // {
    //     cout << e << " ";
    // }

    return 0;
}