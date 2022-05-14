/*
page 226

Algorithm 4.4 The tree vertex splitting algorithm


//Determine and output the nodes to be split
//W() is the weighting function for the edges
Algorithm TVS(T, del)
{
    if(T != 0)
    {
        d[T] = 0;
        for each child v to T do
        {
            TVS(v,del);
            d[T] = max{d[T], d[v] + w(T,v)};
        }
        if((T is not the root) and (d[T] + w(perent(T), T) > del))
        {
            write (T);
            d[T] = 0;
        }

    }

}
*/

#include <iostream>
using namespace std;
int graph[100][100];
int main()
{
    int EDGE, NODE, SRC, DEST, WEIGHT;
    cout << "Enter NODE  and EDGE " << endl;
    cin >> NODE >> EDGE;

    for (int i = 0; i < NODE; i++)
    {
        for (int j = 0; j < NODE; j++)
            graph[i][j] = 0;
    }
    for (int i = 0; i < EDGE; i++)
    {
        cin >> SRC >> DEST >> WEIGHT;
        graph[SRC][DEST] = WEIGHT;
    }
    for (int i = 0; i < NODE; i++)
    {
        for (int j = 0; j < NODE; j++)
            cout << graph[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}
/*
 10 9
 1 2 4
 2 4 2
 1 3 2
 3 5 1
 3 6 3
 4 7 1
 7 8 4
 6 9 2
 6 10 3
*/