/*
Page 240
Algorithm 4.9 Prims's minimum-cost spanning tree algorithm

Algorithm Prim(E, cost, n , t)
//E is the set of edges in G, cost[1:n,1:n] is the cost
//adjacency matrix of an n vertext graph such that cost[i,j] is
//either a positive real number or infinit if no edge (i,j) exist
//A minimum spanning tree is computed and stored as a set of edges in
//the array t[1:n-1, 1:2]. (t[i,1], t[i,2]) is an edge in the minimum cost spanning tree.
The final cost is returned
{
    Let(k,l) be an edge of minimum cost in E;
    mincost = cost[k,l];
    t[1,1] = k;
    t[1,2] - l;

    for(int i = 1 to n do) // Initialize near
    if(cost [i,l] < cost[i,k] then) near[i] = l;
    else  near[i] = k;

    near[k] = near[l] = 0;

    for(i = 2; to n -1 do)
    {
        //Find n -2 addition edges for t.
        //let j be an index such that near[j] != 0 and
        //cost [j,near[j]] is minimum;
        t[i,1] = j; t[i,2] = near[j];
        mincost = mincost + cost[j,near[j]];
        near[j] = 0;
        for(k = 1; to n do) //update near[]
        if(near[k] != 0) && cost[k, near[k]] > cost[k,j]
        then near[k] = j;
    }
}
*/
#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int n, int graph[V][V])
{
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " " << graph[i][parent[i]] << "\n";
    }
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex
    key[0] = 0;
    // First node is always root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, V, graph);
}

// driver program to test above function
int main()
{
    /* Let us create the following graph
     `  2    3
     (0)--(1)--(2)
     |   / \   |
     6| 8/   \5 |7
     | /     \ |
     (3)-------(4)
            9
     */
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    // Print the solution
    primMST(graph);

    return 0;
}
/*
Edge   Weight
0 - 1 2
1 - 2 3
0 - 3 6
1 - 4 5
*/