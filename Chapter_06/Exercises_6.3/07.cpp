/*
Page 348
7) A bipartite graph G = (V, E) is an undirected graph whose vertices can be
partitioned into two disjoint set v1 and v2 = v - v1 with the properties that
no two vertices in v1 are disjoint in graph G of figure 6.4(a) is bipartite .
A possible partitioning of V is V1 = {1,4,5,6,7} and v2 = {2,3,8}.
Write an algorithm to determine wheaher a graph G is bipartite.
*/
// C++ program to check if a connected
// graph is bipartite or not using DFS
#include <bits/stdc++.h>
using namespace std;

// function to store the connected nodes
void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// function to check whether a graph is bipartite or not
bool isBipartite(vector<int> adj[], int v, vector<bool> &visited, vector<int> &color)
{

  for (int u : adj[v])
  {

    // if vertex u is not explored before
    if (!visited[u])
    {

      // mark present vertic as visited
      visited[u] = true;

      // mark its color opposite to its parent
      color[u] = !color[v];

      // if the subtree rooted at vertex v is not bipartite
      if (!isBipartite(adj, u, visited, color))
        return false;
    }

    // if two adjacent are colored with same color then
    // the graph is not bipartite
    else if (color[u] == color[v])
      return false;
  }
  return true;
}

// Driver Code
int main()
{
  // no of nodes
  int N = 6;

  // to maintain the adjacency list of graph
  vector<int> adj[N + 1];

  // to keep a check on whether
  // a node is discovered or not
  vector<bool> visited(N + 1);

  // to color the vertices
  // of graph with 2 color
  vector<int> color(N + 1);

  // adding edges to the graph
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 5);
  addEdge(adj, 5, 6);
  addEdge(adj, 6, 1);

  // marking the source node as visited
  visited[1] = true;

  // marking the source node with a color
  color[1] = 0;

  // Function to check if the graph
  // is Bipartite or not
  if (isBipartite(adj, 1, visited, color))
  {
    cout << "Graph is Bipartite";
  }
  else
  {
    cout << "Graph is not Bipartite";
  }

  return 0;
}