/* 
1. Topological Sorting
    - Topological Sorting for a graph is not possible if the graph is not a DAG(Directed Acyclic Graph)
    - Using DFA Concept
    - Time Complexity: O(V+E). 
    - Auxiliary space: O(V). 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    // no. of vertices
    int v;

    // adjacency list
    vector<int> *adj;

    // func using by topological sort
    void topologicalRecursion(int v, vector<int> &visited, stack<int> &st);

public:
    Graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int u, int w);

    void topologicalSorting();
};

void Graph::addEdge(int u, int w)
{
    adj[u].push_back(w);
}

void Graph::topologicalRecursion(int v, vector<int> &visited, stack<int> &st)
{
    visited[v] = 1;
    for (auto elem : adj[v])
    {
        if (visited[elem] == 0)
        {
            topologicalRecursion(elem, visited, st);
        }
    }
    st.push(v);
}

void Graph::topologicalSorting()
{
    stack<int> st;
    vector<int> visited(v + 1, 0);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            topologicalRecursion(i, visited, st);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    /* Graph
    
        5 -> 0 <- 4
        ↓         ↓
        2 -> 3 -> 1
        
    */


    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given "
            "graph \n";

    // Function Call
    g.topologicalSorting(); // 5 4 2 3 1 0 
    return 0;
}
