/*
Page 135
Devise a suitable representation for graphs so that they can be stored
on disk. Write an algorithm that reads in such a graph and creates its adjacency matrix. Write
another algorithm that creates the adjanncency list fromm the dislk input.

*/
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include<iomanip>
using namespace std;
void PRINT(list<int> A, list<int> X[])
{
    list<int>::iterator ptr = A.begin();
    cout << "\n==========GRAPH=============\n";
    while (ptr != A.end())
    {
        list<int>::iterator ptr1 = X[*ptr].begin();
        cout << char((*ptr) + 65) << " -> ";
        while (ptr1 != X[*ptr].end())
        {
            cout << char((*ptr1++) + 65) << " ";
        }
        cout << "\n";
        ptr++;
    }

    cout << "=======================\n";
}
void FINDEDGE(list<int> A, list<int> X[], int SRC, int DEST, int NODE)
{
    if (SRC > NODE)
    {
        return;
    }
    else
    {
        list<int>::iterator ptr = find(A.begin(), A.end(), SRC);
        if (ptr != A.end())
        {
            list<int>::iterator temp = find(X[*ptr].begin(), X[*ptr].end(), DEST);
            if (temp != X[*ptr].end())
            {
                cout << "Match found\n";
            }
            else
            {
                cout << "NOT FOUND\n";
            }
        }
        else
        {
            cout << "NOT FOUND\n";
        }
    }
}
void INSER_NODE(list<int> &A, list<int> X[], int &NODE)
{
    A.push_back(NODE);
    NODE = NODE + 1;
}
void INSERT_EDGE(list<int> X[], int NODE, int &EDGE, int SRC, int DEST)
{
    if (SRC > NODE && SRC > DEST)
    {
        return;
    }
    else
    {
        X[SRC].push_back(DEST);
        EDGE += 1;
    }
}



int main()
{
    list<int> A;
    list<int> X[2000];
    int EDGE, NODE, SRC, DEST;
    char n, m;
    cout << "Enter Nodes and EDGE\n";
    cin >> NODE >> EDGE;

    int **a = new int *[NODE];

    for (int i = 0; i < NODE; i++)
    {

        // Declare a memory block
        // of size n
        a[i] = new int[EDGE];
    }
    // Traverse the 2D array
    for (int i = 0; i < NODE; i++)
    {
        for (int j = 0; j < EDGE; j++)
        {

            // Assign values to the
            // memory blocks created
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < EDGE; i++)
    {
        cin >> n >> m;
        SRC = n - 65;
        DEST = m - 65;
        X[SRC].push_back(DEST);
        a[SRC][DEST] = 1;
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }

    PRINT(A, X);


    // Traverse the 2D array
    for (int i = 0; i < NODE; i++)
    {
        for (int j = 0; j < EDGE; j++)
        {

            // Print the values of
            // memory blocks created
            cout << setw(5) << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < NODE; i++) // To delete the inner arrays
        delete[] a[i];
    delete[] a;
}
/*
Enter Nodes and EDGE
7 7
A C
B D
B F
D C
E C
G A
G F

==========GRAPH=============
A -> C
B -> D F
C ->
D -> C
E -> C
F ->
G -> A F
=======================
    0     0     1     0     0     0     0
    0     0     0     1     0     1     0
    0     0     0     0     0     0     0
    0     0     1     0     0     0     0 
    0     0     1     0     0     0     0
    0     0     0     0     0     0     0
    1     0     0     0     0     1     0 
*/