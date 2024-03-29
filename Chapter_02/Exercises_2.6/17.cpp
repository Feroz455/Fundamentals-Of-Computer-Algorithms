/*
page 135
17) Do the preceding exercise but now set up the multilist representation.

*/
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;
void PRINT(list<int> A, list<int> X[])
{
    list<int>::iterator ptr = A.begin();
    cout << "\n==========GRAPH=============\n";
    while (ptr != A.end())
    {
        list<int>::iterator ptr1 = X[*ptr].begin();
        cout << char((*ptr)+65) << " -> ";
        while (ptr1 != X[*ptr].end())
        {
            cout << char((*ptr1++)+65) << " ";
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
void DELETE_EDGE(list<int> X[], int SRC, int DEST, int NODE, int &EDGE)
{
    if (SRC > NODE || DEST > NODE)
        return;
    else
    {
        list<int>::iterator ptr = find(X[SRC].begin(), X[SRC].end(), DEST);
        if (ptr != X[SRC].end())
        {
            X[SRC].remove(DEST);
            EDGE -= 1;
        }
        else
            cout << "EDGE NOT EXIST\n";
    }

    return;
}
void DELETE_NODE(list<int> &A, list<int> X[], int &NODE, int node)
{
    list<int>::iterator ptr = A.begin();
    while (ptr != A.end())
    {
        X[*ptr].remove(node);
        ptr++;
    }
    X[node].clear();
    A.remove(node);
    NODE -= 1;
}

void INDEGREE(list<int> A, list<int> X[], int indg[])
{
    list<int>::iterator ptr = A.begin();
    while (ptr != A.end())
    {
        list<int>::iterator ptr1 = X[*ptr].begin();
        while (ptr1 != X[*ptr].end())
        {
            indg[*ptr1] += 1;
            ptr1++;
        }
        ptr++;
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << char(65 + i) << " -> " << indg[i] << " \n";
    }
    cout << "\n";
    return;
}

int main()
{
    list<int> A;
    list<int> X[2000];
    int EDGE, NODE, SRC, DEST;
    char n, m;
    cout << "Enter Nodes and EDGE\n";
    cin >> NODE >> EDGE;

    for (int i = 0; i < EDGE; i++)
    {
        cin >> n >> m;
        SRC = n - 65;
        DEST = m - 65;
        X[SRC].push_back(DEST);
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }

    PRINT(A, X);
}