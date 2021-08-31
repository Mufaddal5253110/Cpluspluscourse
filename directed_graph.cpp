/* 
1. Topological Sorting
    - Topological Sorting for a graph is not possible if the graph is not a DAG(Directed Acyclic Graph)
    - Using DFA Concept
    - Time Complexity: O(V+E). 
    - Auxiliary space: O(V). 
2. DFS Sort
3. Transpose of Graph
    - Time Complexity: O(V+E)
4. Print Strongly Connected Components
    - Topological Sort to fill stack
    - Tanspose of graph
    - DFS algo on transposed graph to print SCC
    - Time Complexity: O(V+E)
5. Detect Cycle in Undirected Graph using dfs
    - Time Complexity: O(V+E).
    - Space Complexity: O(V).
6. Detect Cycle in Undirected Graph using bfs
    - Time Complexity: O(V+E).
    - Space Complexity: O(V).
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

    void printdfs(int v, vector<int> &visited);

    bool detectcycleusingdfs(int v, int parent, vector<int> &visited);

public:
    Graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int u, int w);
    void addEdge2(int u, int w);

    void topologicalSorting(stack<int> &ans);

    void strongleConnectedComponents();

    Graph getTranspose();

    void detecycle();
    bool detectcycleusingbfs();
};

void Graph::addEdge(int u, int w)
{
    adj[u].push_back(w);
}

void Graph::addEdge2(int u, int w)
{
    adj[u].push_back(w);
    adj[w].push_back(u);
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

void Graph::topologicalSorting(stack<int> &ans)
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

    ans = st;
}

Graph Graph::getTranspose()
{
    Graph newgraph(v);
    for (int i = 0; i < v; i++)
    {
        for (auto elem : adj[i])
        {
            newgraph.adj[elem].push_back(i);
        }
    }

    return newgraph;
}

void Graph::printdfs(int v, vector<int> &visited)
{
    visited[v] = 1;
    cout << v << " ";

    for (auto elem : adj[v])
    {
        if (visited[elem] == 0)
        {
            printdfs(elem, visited);
        }
    }
}

void Graph::strongleConnectedComponents()
{
    stack<int> st;
    vector<int> visited(v, 0);

    // topological sorting for filling stack
    topologicalSorting(st);

    // Making graph transpose;
    Graph gr = getTranspose();

    // reset visited array/vector;
    vector<int> visited2(v, 0);

    // now traversing the stack and for each element printing dfs
    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        if (visited2[v] == 0)
        {
            gr.printdfs(v, visited2);
            cout << endl;
        }
    }
}

bool Graph::detectcycleusingdfs(int v, int parent, vector<int> &visited)
{
    visited[v] = 1;

    for (auto elem : adj[v])
    {
        if (visited[elem] == 0)
        {
            if (detectcycleusingdfs(elem, v, visited))
            {
                return true;
            }
        }
        else if (elem != parent)
        {
            return true;
        }
    }
    return false;
}

void Graph::detecycle()
{
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            if (detectcycleusingdfs(i, -1, visited))
            {
                cout << "\nCycle is Present";
                return;
            }
        }
    }

    cout << "\nCycle is not Present";
    return;
}

bool Graph::detectcycleusingbfs()
{
    vector<int> visited(v + 1, 0);
    queue<pair<int, int>> q;

    q.push(make_pair(0, -1));
    visited[0] = 1;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (auto elem : adj[p.first])
        {
            if (visited[elem] == 0)
            {
                q.push(make_pair(elem,p.first));
                visited[elem] = 1;
            }
            else if (p.second != elem)
            {
                return true;
            }
        }
    }
    return false;
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
    stack<int> st;
    g.topologicalSorting(st); // 5 4 2 3 1 0
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    /*
    Graph 2
        1 -> 0 -> 3
        ↓    |    ↓
        2  <-|    4
    */

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 3);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g2.strongleConnectedComponents();

    /*
    Graph 2 :- Undirected Graph
        1 - 0 - 3
        |  /    |
        2       4
    */
    Graph g3(5);
    g3.addEdge2(1, 0);
    // g3.addEdge2(0, 2);
    g3.addEdge2(2, 1);
    g3.addEdge2(0, 3);
    g3.addEdge2(3, 4);
    // g3.addEdge2(2, 4);
    
    // Detecting Cycle using dfs in undirected graph
    cout << "\nDetecting Cycle Using DFS...";
    g3.detecycle();

    // Detecting Cycle using bfs in undirected graph
    cout << "\nDetecting Cycle Using BFS...\n";
    cout<<g3.detectcycleusingbfs();

    return 0;
}
