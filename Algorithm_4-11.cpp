/*
Page 243
Algorithm 4.11 Kruskal's algorithm;

//E is the set of edges in G, G has n vertices. Cost(u, v) is the
//cost of edge(v,u). T the set of edges in the minimum cost spanning tree
//The final cost is returned;
Algorithm Kruskal(E, cost, n, t)
{
    //Construct a heap out of the edges costs using Heapify
    for(int i = 1 to n do parent[i] = -1)
    //Each vertext is in a different set
    i = 0;
    mincost = 0.0;

    while((i < n - 1) and (heap not empty))
    {
        //delete a minimum cost edges(u,v) from the heap;
        //and reheapufy using Adjust;

        if(j != k)
        {
            i = i + 1;
            t[i,1] = u;
            t[i,2] = v;
            mincost = mincost + cost(u,v);
            Union(j, k);
        }
    }
    if(i != n -1 ) then write ("No spanning tree");
    else retrun mincost;
}
*/

#include <bits/stdtr1c++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int size[N];
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = (parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{
    int n, k, u, v, m, wt;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> egdes;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        egdes.push_back({wt, {u, v}});
    }
    sort(egdes.begin(), egdes.end());
    for (int i = 0; i < n; i++)
    {
        make(i);
    }
    int total_cost = 0;
    cout << "\n";
    for (auto &edge : egdes)
    {
        wt = edge.first;
        u = edge.second.first;
        v = edge.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        cout << u << " -> " << v << endl;
    }
    cout << total_cost << endl;
}
/*
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6

1 4
1 2
3 2
5 1
2 6
3 6
25
*/