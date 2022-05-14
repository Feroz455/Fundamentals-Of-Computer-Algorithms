/*
page 242
Algorithm 4.10 Early form of minimum-cost spanning tree algorithm due to Kruskal.


t = 0;
while((t ha less than n - 1 edges) (E != 0) do
{
    choose an edge(v,w) from E of lowest cost;
    Delete (v, v) from E;
    if(v, w) does not create a cycle in t then add(v, w) to t;
    else discard(v,w);
}
*/