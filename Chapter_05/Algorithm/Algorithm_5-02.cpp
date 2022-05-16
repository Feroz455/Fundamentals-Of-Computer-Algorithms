/*
Page 282
Algorithm 5.2 Multistage graph pseudocede corresponding to backward approach

Algorithm BGraph(G, k, n, p)
{
    bcost[1] = 0.0;
    for(j = 2 to n do)
    {
        //Compute bcost[j]
        //Let r be such that <r, j> is an edge of G and
        //bcost[j] = bcost[r] + G[r][j] is minimum
        //
        bcost[j] = bcost[r] + c[r][j];
        d[j] = r;
    }
    //find a minimum cost path
    p[1] = 1;
    p[k] = n;
    for(j = k - 1 to 2 )
    {
        p[j] = d[p[j+1]];
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
    int min, bcost[n + 1], d[n + 1];
    bcost[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        min = INF;
        for (int k = i + 1; k <= n; k++)
        {
            if (G[i][k] && G[i][k] + bcost[k] < min)
            {
                min = G[i][k] + bcost[k];
                d[i] = k;
            }
        }
        bcost[i] = min;
    }
    p[1] = 1;
    p[stage] = n;
    for (int j = stage - 1; j >= 2; j--)
    {
        p[j] = d[p[j + 1]];
    }
    for (int j = 1; j <= stage; j++)
    {
        cout << p[j] << " ";
    }
    cout << "bcost " << bcost[1] << " ";
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
            // cout << ".";
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