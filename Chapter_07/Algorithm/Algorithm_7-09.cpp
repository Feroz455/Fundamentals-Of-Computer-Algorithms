/*
Page 386
ALgoritm 7.9 Generating a next vertex

Algorithm NextValue(k)
{
    repeate
    {
        x[k] = (x[k]+1) mod (n+1); // Next vertex
        if(x[k] == 0)
        {
            retrun;
        }
        if(G[x[k-1],x[k]] != 0)
        {
            //Is there an edge
            for(int j = 1; j < k; j++)
            {
                if(x[j] == x[k])
                break;
            }
            if(j == k)
            if((k < n) || (k == n) && G[x[n],x[1]] != 0)
            return;
        }
    }
}


Algorithm Hamiltonian(k)
//This algorithm uses recursive formulation of
//Backtracking to find all the Hamiltonian cycles
//of a graph. The graph is stored as an adjacency
//Matrix G[1:n][1:n]. All the cycles begain at node 1;
{
    repeate
    {
        //Generate values for x[k];
        NextValue(k); // Assign a legal next value to x[k];
        if(x[k] == 0)
        return;
        if(k == n)
        {
            for(int i = 0; i < n; i++)
            {
                cout << x[i] << " ";
            }
        }
        else Hamiltonian(k+1);
    }until(false);
}
*/
#include <iostream>
using namespace std;
#define N 5
int G[N][N + 1] = {
    {0, 0, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 1},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 0}};
int x[N + 1];
void NextValue(int k);
void Print(int x[])
{
    // cout << "3";
    for (int i = 1; i <= N; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
}
void Hamiltonian(int k)
// This algorithm uses recursive formulation of
// Backtracking to find all the Hamiltonian cycles
// of a graph. The graph is stored as an adjacency
// Matrix G[1:n][1:n]. All the cycles begain at node 1;
{
    // cout << "2";
    do
    {
        // cout << "2+2";
        // Generate values for x[k];
        NextValue(k); // Assign a legal next value to x[k];
        if (x[k] == 0)
            return;
        if (k == N)
        {
            Print(x);
        }
        else
            Hamiltonian(k + 1);
    } while (true);
}
void NextValue(int k)
{
    // cout << "1";
    int j;
    // cout << "k " << k;
    do
    {
        // cout << "1+1";
        x[k] = (x[k] + 1) % (N + 1); // Next vertex
        // Print(x);
        if (x[k] == 0)
        {
            return;
        }
        // cout << x[k - 1] << " " << x[k] << endl;
        if (G[x[k - 1]][x[k]] != 0)
        {
            // Is there an edge
            for (j = 1; j < k; j++)
            {
                if (x[j] == x[k])
                    break;
            }
            if (j == k)
                if ((k < N) || (k == N) && G[x[N], x[1]] != 0)
                    return;
        }
    } while (true);
}

int main()
{
    Hamiltonian(2);
    /*for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }*/
    return 0;
}
/*
0 2 1 3 5
0 2 4 1 3
0 2 4 1 5
0 3 2 1 4
0 3 2 1 5
0 3 2 4 1
0 3 5 2 1
0 3 5 2 4
0 5 2 1 3
0 5 2 1 4
0 5 2 4 1
*/