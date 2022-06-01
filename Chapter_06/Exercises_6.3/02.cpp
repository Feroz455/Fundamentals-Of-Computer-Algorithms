/*
Page 347
2)  Rewrite BFS and BFT so that all the completed components of the undirected
graph G get printed out . Asume that G is input in adjacency list from.
*/
#include <bits/stdc++.h>
using namespace std;
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices
    vector<bool> visited;
    // Pointer to an array containing adjacency
    // lists
    vector<list<int>> adj;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void D_Search(int s);
    void BFT();
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v); // Add w to v’s list.
}

void Graph::D_Search(int s)
{
    // Mark all the vertices as not visited
    // Create a stck for BFS
    stack<int> stck;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    stck.push(s);

    while (!stck.empty())
    {
        // Dequeue a vertex from stck and print it
        s = stck.top();
        cout << s << " ";
        stck.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent : adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                stck.push(adjecent);
            }
        }
    }
}
void Graph::BFT()
{
    visited.resize(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            D_Search(i);
            cout << "\n";
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    g.BFT();

    return 0;
}
/*
0 2 6 7 4 3 5 1
*/
