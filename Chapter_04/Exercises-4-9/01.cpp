/*
Page 266
01) Use algorithm ShortestPath to obtain in nondecreasing order the lengths 
of the shortest pth from vertex 1 to all remaining vertices in the digraph of figure 4.20

*/

// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;
// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 1; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    // cout << "min = " << min << " min_index ->" << min_index << "\n";

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 1; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}
template <typename T>
void printArray(T array[])
{
    cout << "\n";
    for (int i = 0; i < V; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // printArray(dist);
    // printArray(sptSet);

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;
        // printArray(dist);
        //  printArray(sptSet);

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 1; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                //  printArray(dist);
                // printArray(sptSet);
            }
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver program to test above function
int main()
{

    /* Let us create the example graph discussed above */
    int graph[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)

        {
            graph[i][j] = 0;
        }
    }
    int ver, edge, src, dest, wt;
    cout << "Enter vertext and edge number\n";
    cin >> ver >> edge;
    for (int i = 0; i < edge; i++)
    {
        cin >> src >> dest >> wt;
        graph[src][dest] = wt;
        graph[dest][src] = wt;
    }
    dijkstra(graph, 1);

    return 0;
}

// This code is contributed by shivanisinghss2110
/*
Enter vertext and edge number
8
11
1 2 55
1 3 25
1 4 45
2 5 5
3 5 40
4 5 20
4 8 30
5 7 15
5 6 35
7 8 50
7 6 10
Vertex   Distance from Source
1               0
2               55
3               25
4               45
5               60
6               85
7               75
8               75
*/