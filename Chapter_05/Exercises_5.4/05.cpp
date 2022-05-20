/*
page 292
5)
Rewrite BellmanFord by replacing the loop of lines 7 to 12 with code that uses a queue of vertices that
may potentially result in reduction of the dist. This queue initially contains all vertices that are
adjacent from the source vertext v. On each successive iteration of the new loop, a vertex i is removed from
the queue. (unless the queue is empty) and the dist values to vertices adjacent from i are updated as in lines
11 and 12 of algorithm 5.4. When the dist value of a vertex is resduce because of this, it is added to the
queue unless it is alraeady on the queue .
a) Prove that the new algorithm produces the same result as the original one .
b) Show that the complexity of the new algorithm is no more than that the original one.
*/
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int src, dst, wt;
};
int V, E;

void bellmanFord(vector<edge> &Edges)
{
    int parent[V];                 // Stores Shortest Path Structure
    int cost_parent[V];            // Cost of the node to parent edge weight
    vector<int> value(V, INT_MAX); // Keeps shortest path values to each vertex from source

    // Assuming start point as Node-0
    parent[0] = -1; // Start node has no parent
    value[0] = 0;   // start node has value=0 to get picked 1st

    // Include (V-1) edges to cover all V-vertices
    bool updated;
    for (int i = 0; i < V - 1; ++i)
    {
        updated = false;
        for (int j = 0; j < E; ++j)
        {
            int U = Edges[j].src;
            int V = Edges[j].dst;
            int wt = Edges[j].wt;
            if (value[U] != INT_MAX and value[U] + wt < value[V])
            {
                value[V] = value[U] + wt;
                parent[V] = U;
                cost_parent[V] = value[V];
                updated = true;
            }
        }
        if (updated == false)
            break;
    }
    // Now check by relaxing once more if we have a negative edge cycle
    for (int j = 0; j < E and updated == true; ++j)
    {
        int U = Edges[j].src;
        int V = Edges[j].dst;
        int wt = Edges[j].wt;
        if (value[U] != INT_MAX and value[U] + wt < value[V])
        {
            cout << "Graph has -VE edge cycle\n";
            return;
        }
    }
    // Print Shortest Path Graph
    for (int i = 1; i < V; ++i)
        cout << "U->V: " << parent[i] << "->" << i << "  Cost to reach " << parent[i] << "from source 0 = " << value[i] << "\n";
}

int main()
{
    cout << "Enter number of vertices and edge\n";
    cin >> V >> E; // Enter no of Vertices and Edges
    vector<edge> Edges(E);
    cout << "Enter edge src , dest and wt\n";
    // Now input all E edges
    int src, dst, wt;

    for (int i = 0; i < E; ++i)
    {
        cin >> src >> dst >> wt;
        Edges[i].src = src;
        Edges[i].dst = dst;
        Edges[i].wt = wt;
    }

    bellmanFord(Edges);
    return 0;
}

// TIME COMPLEXITY: O(V.E)
/*
Enter number of vertices and edge
6
10
Enter edge src , dest and wt
0 1 2
0 2 4
1 2 -3
1 4 1
1 4 5
2 4 -4
2 4 -2
3 5 8
4 5 6
4 3 4
U->V: 0->1  Cost to reach 0from source 0 = 2
U->V: 1->2  Cost to reach 1from source 0 = -1
U->V: 4->3  Cost to reach 4from source 0 = -1
U->V: 2->4  Cost to reach 2from source 0 = -5
U->V: 4->5  Cost to reach 4from source 0 = 1
*/
