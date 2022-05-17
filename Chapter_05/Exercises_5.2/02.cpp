/*
Page 282 
02) Redefine Algorithm 5.1 into a program. Asume that G is represented by it's adjacency list. 
Test the correctness of your code using suitabe graph.
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void PrintArray(int array[], int n)
{
    cout << "\n";
    for (int i = 1; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
void FGraph(int c[][9])
{
}
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int, int>> adj[], int V)
{
    int v, w;
    for (int u = 1; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    int V = 9;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 1, 3, 1);
    addEdge(adj, 1, 4, 3);
    addEdge(adj, 2, 5, 2);
    addEdge(adj, 3, 5, 6);
    addEdge(adj, 3, 6, 7);
    addEdge(adj, 4, 5, 6);
    addEdge(adj, 4, 6, 4);
    addEdge(adj, 4, 7, 9);
    addEdge(adj, 5, 8, 6);
    addEdge(adj, 6, 8, 4);
    addEdge(adj, 7, 8, 5);
    printGraph(adj, V);

    int stages = 4, min;
    int n = 8;
    int cost[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, d[9], p[stages + 1];
    cost[n] = 0;
    // PrintArray(cost, n + 1);

    for (int i = n - 1; i >= 1; i--)
    {
        min = 32767;
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            // cout << "cost " << k << " , " << i << "  -> " << c[k][i] << " \n";
            if (it->second + cost[it->first] < min)
            {
                min = it->second + cost[it->first];
                d[i] = it->first;
                // cout << " d[" << i << "]" << d[i] << "\n";
            }
        }
        cost[i] = min;
    }
    // PrintArray(cost, n + 1);
    p[1] = 1;
    p[stages] = n;
    int temp = 0;
    for (int i = 2; i < stages; i++)
    {
        p[i] = d[i - 1];
    }
    cout << "\npath is  ";
    for (int i = 1; i <= stages; i++)
    {
        cout << "-> " << p[i] << " ";
        temp += p[i];
    }
    cout << "\nTotal cost will be " << temp << " \n";
    return 0;
}