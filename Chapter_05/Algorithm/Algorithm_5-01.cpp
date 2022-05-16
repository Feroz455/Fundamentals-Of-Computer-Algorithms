/*
Page 281

Algorithm 5.1 Multistage graph pseudocode corresponding to the forward approach

Algorithm FGraph(G, k, n, p)
//The input is a k-stage graph G = (V, E) with n vertices
//Indexed in order of stages E is a set of edges and c[i,j]
//is the cost of (i,j). p[1:k] is aminimum-cost path
{
    cont[n] = 0.0;
    for(int j = n -1 ; j > 1; j--)
    {
        //Compute cost[j];
        let r be vertext such that<j, r> is an edge of G and c<j,r> + cost[r] is minimum;
        cost[j] := c[j,r] + cost[r];
        d[j] = r;
     }
     //find minimum cost path
     p[1] := 1;
    p[k] = n;
    for(j = 2; j < k; j++)

    {
        p[j] = d[p[j-1]];
    }

}
*/

// CPP program to find shortest distance
// in a multistage graph.
#include <bits/stdc++.h>
using namespace std;

#define N 20
#define INF INT_MAX
void FGraph(int G[][N], int stage, int n, int p[])
{
    int min, cost[n + 1], d[n + 1];
    cost[n] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        min = INF;
        for (int k = i + 1; k <= n; k++)
        {
            if (G[i][k] && G[i][k] + cost[k] < min)
            {
                min = G[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }
    p[1] = 1;
    p[stage] = n;
    for (int j = 2; j < stage; j++)
    {
        p[j] = d[p[j - 1]];
    }
    for (int j = 1; j <= stage; j++)
    {
        cout << p[j] << " ";
    }
    cout << "cost " << cost[1] << " ";
}
// Driver code
int main()
{
    // Graph stored in the form of an
    // adjacency Matrix
    int graph[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //cout << ".";
            graph[i][j] = 0;
        }
    }
    int vertext, stage, edge, src, dest, wt;
    cout << "Enter vartex edge and stage\n";
    cin >> vertext >> edge >> stage;
    for (int i = 0; i < edge; i++)
    {
        cin >> src >> dest >> wt;
        graph[src][dest] = wt;
    }

    // cout << shortestDist(graph);
    return 0;
}