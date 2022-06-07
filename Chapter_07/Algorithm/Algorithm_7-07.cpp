/*
Page 383
Algorithm 7.7 Finding all m-colorings of a graph

Algorithm mColoring(k)
//This algorithm was formed using the recursive backtracking
//schema. The graph is represented by its boolean adjacency matrix
//G[1:n,1:n]. All assignments of 1,2....,m to the vertices of the graph sucg that adjacent vertices are
//assigned distinct integer are printed. K is the index of the next to color.
{
    do
    {
        //Generate all legal assignments forx[k];
        NextValue(k); Assign to x[k] a legal color

        if(x[k] == 0)
        return;
        if(k == n)
        {
            write x[1:n];
        }
        else mColoring(K+1);
    }while(true);
}

*/
#include <iostream>
#include <math.h>
using namespace std;
#define V 4
bool G[V + 1][V + 1] = {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0},
};
int x[V + 1], m = 3;
void NextValue(int k)
// x[1],......x[k-1] have been assined interger values in the
// range [1,m] such that adjacent vertices have distinct
// integers. A value for x[k] is determined in the range
//[0,m]. x[k] is assigned the next highest numbered color
// while maintaining distinctness from the adjacent vertices
// of the vertex k. If no such color exist, then x[k] = 0;
{
    int j;
    do
    {
        x[k] = (x[k] + 1) % (m + 1); // Next hightest color
        // cout << x[k] << "\n";
        if (x[k] == 0)
            return; // All colors have been used
        for (j = 1; j <= V; j++)
        {
            // Check if this color is
            // distinct from adjacent colors
            if ((G[k][j] != 0) && (x[k] == x[j]))
            {
                // if (k,j) is and edge and if adj
                // vertices have same color
                break;
            }
        }
        if (j == (V + 1))
            return;  // New color found
    } while (false); // Otherwise try to find another color
}

void mColoring(int k)
// This algorithm was formed using the recursive backtracking
// schema. The graph is represented by its boolean adjacency matrix
// G[1:n,1:n]. All assignments of 1,2....,m to the vertices of the graph sucg that adjacent vertices are
// assigned distinct integer are printed. K is the index of the next to color.
{
    cout << " k -> " << k << "\n";
    do
    {
        // Generate all legal assignments forx[k];
        NextValue(k); //
        if (x[k] == 0)
            return;
        if (k == V)
        {
            for (int i = 1; i <= V; i++)
            {
                cout << x[i] << " ";
            }
            cout << "\n";
        }
        else
            mColoring(k + 1);
    } while (true);
}
int main()
{
    mColoring(1);
    return 0;
}