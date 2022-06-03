/*
Page 355
ALgorithm 6.10 Pseudocode to determine biconmponents

Algorithm BiComp(u,v)
//u is a start vertex for depth first search. u is its parent if
//any in the depth first spanning tree. It is assumed that the
/loabal array dfn is initially zero and that the globall variable
//num is initialized to 1. n is the number of vertices in G.
{
    dfn[u] = num ;
    L[u] = num;
    num = num + 1;
    for(each vertex w adjacent from u do )
    {
        if((v != w) and (dfn[w] < dfn[n]))
        {
            add (u, w) to the top of a stack s;
        }
        if(dfn[w] == 0)
        {
            if(L[w] >= dfn[u])
            {
                write("New bicomponent");
                do
                {
                    delete an edge from the top of stack s;
                    let this edge be(x,y);
                    write(x,y);
                }while((x,y) != (u,w) or(x,y) != (w,u));
            }
            BiComp(w,u); // w is unvisited;
        L[u] = min(L[u],L[w]);
        }
            else if(w != v)
            L[u] = min(L[u], dfn[w]);
    }


}
*/

#include <bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int, vector<int>> adj;

void ART(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &articulation_Point)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    int children = 0;

    for (int v : adj[u])
    {
        if (disc[v] == -1) // If v is not visited
        {
            children += 1;
            parent[v] = u;
            ART(v, disc, low, parent, articulation_Point);
            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 and children > 1)
            { // Case-1: U is root
                articulation_Point[u] = true;
                //  cout << adj[u].at(1) << " connected " << adj[u].at(2) << "\n";
            }

            if (parent[u] != -1 and low[v] >= disc[u])
            {
                // Case-2: Atleast 1 component will get separated
                articulation_Point[u] = true;
                // cout << parent[u] << " connected " << adj[u].at(1) << "\n";
            }
        }
        else if (v != parent[u]) // Ignore child to parent edge
            low[u] = min(low[u], disc[v]);
    }
}

bool findAPs_Tarjan()
{
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<bool> articulation_Point(V, false); // Avoids cross-edge
    bool check = false;
    for (int i = 0; i < V; ++i)
        if (disc[i] == -1)
            ART(i, disc, low, parent, articulation_Point);

    cout << "Articulation Points are: ";
    for (int i = 0; i < V; ++i)
    {
        if (articulation_Point[i] == true)
        {
            check = true;
            cout << i << " ";
        }
    }
    cout << "\n";
    return check;
}

int main()
{
    adj[0].pb(2);
    adj[2].pb(0);
    adj[0].pb(3);
    adj[3].pb(0);
    adj[1].pb(0);
    adj[0].pb(1);
    adj[2].pb(1);
    // adj[2].pb(4);
    // adj[4].pb(2);
    adj[1].pb(2);
    adj[3].pb(4);
    adj[4].pb(3);

    if (!findAPs_Tarjan())
    {
        cout << "Graph is biconnected\n";
    }
    return 0;
}

// TIME COMPLEXITY: O(V+E)
/*
Articulation Points are: 0 3
*/