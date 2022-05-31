/*
Page 347
01) Rewrite BFS and BFT so that all the completed components of the undirected 
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
    void BFS(int s);
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

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent : adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
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
            DFS(i);
            cout << "\n";
        }
    }
}
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
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

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFT();

    return 0;
}
/*
0 1 3 7 4 5 2 6
*/