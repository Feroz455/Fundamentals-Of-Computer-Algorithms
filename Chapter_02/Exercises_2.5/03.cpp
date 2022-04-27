/*
Page 119
a) Present an algorithm HeightUnion that uses the height rule
for union operation insttead of the weighting rule. This rule is defined
below.

Defination 2.7 [Height rule] If the height of tree i is less than that of tree j, then
make j the parent of i; otherwise make i the parent of j.

your algorithm must run in O(1) time and should maintain the height of each tree as a negative number in
the p find of the root.

b) Show that the height bound of lemma 2.3 applies to trees constructed using the height rule;
*/

#include <iostream>

using namespace std;
int Array[100];

void option()
{
    int i = 1;
    cout << "\n************************************\n";
    // cout << i++ << "Enter sets value\n";
    cout << i++ << "\tUnion set\n";
    cout << i++ << "\tFind Parent\n";
    cout << i++ << "\tShow result\n";
    cout << i++ << "\tExit\n";
    cout << "\n************************************\n";
}
void SimpleUnion(int i, int j)
{
    Array[i] = j;
}
int SimpleFind(int i)
{
    while (Array[i] >= 0)
    {
        i = Array[i];
    }
    return i;
}
void WeightedUnion(int i, int j)
// Union sets with roots i and j, where i != j using the
// Weighting rule Array[i] = -count[i] and Array[j] = - count[j];
{
    int temp = (Array[i]) + (Array[j]);
    if (Array[i] > Array[j])
    {
        // I has fewer nodes
        Array[i] = j;
        Array[j] = temp;
    }
    else
    {
        // j has fewer or equal nodes
        Array[j] = i;
        Array[i] = temp;
    }
}

void HeightedUnion(int i, int j)
// Union sets with roots i and j, where i != j using the
// Weighting rule Array[i] = -count[i] and Array[j] = - count[j];
{
    if (Array[i] > Array[j])
    {
        // I has fewer nodes
        Array[i] = j;
        Array[j] -= 1;
    }
    else
    {
        // j has fewer or equal nodes
        Array[j] = i;
        Array[i] -= 1;
    }
}
int CollapsingFInd(int i)
// Find the root of the tree containing elemenet i. Use the
// Collapsing rule to collapse all nodes from i to the root
{
    int r, s;
    r = i;
    while (Array[r] > 0)
    {
        r = Array[r]; // Find the root
    }

    // Collapse nodes from i to root r
    while (i != r)
    {
        s = Array[i];
        Array[i] = r;
        i = s;
    }
    return r;
}
int main()
{
    int count, N, tempi, tempj, opcode;
    cout << "Number of element? --> \t";
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        Array[i] = -1;
    }
    while (1)
    {
        option();
        cin >> opcode;
        switch (opcode)
        {
        case 1:
            cout << "Enter 2 sets number\n";
            cin >> tempi >> tempj;
            if (tempi > N || tempj > N)
                break;
            else
                HeightedUnion(tempi, tempj);
            break;
        case 2:
            cout << "Enter set value\n";
            cin >> tempi;
            if (tempi >= N)
                break;
            else
                cout << CollapsingFInd(tempi) << "\n";
            break;
        case 3:
            for (int i = 1; i <= N; i++)
            {
                cout << i << " -> " << Array[i] << "\n";
            }
            break;
        case 4:
            exit(1);
        default:
            break;
        }
    }
}
/*
Number of element? -->  8

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1
Enter 2 sets number
1 2

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1 
Enter 2 sets number
3 4

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1
Enter 2 sets number
5 6

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1
Enter 2 sets number
7 8

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
3
1 -> -2
2 -> 1
3 -> -2
4 -> 3
5 -> -2
6 -> 5
7 -> -2
8 -> 7

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1
Enter 2 sets number
1 3

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
3
1 -> -3
2 -> 1
3 -> 1
4 -> 3
5 -> -2
6 -> 5
7 -> -2
8 -> 7

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1
Enter 2 sets number
5 7

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
3
1 -> -3
2 -> 1
3 -> 1
4 -> 3
5 -> -3
6 -> 5
7 -> 5
8 -> 7

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1
Enter 2 sets number
1 5

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
3
1 -> -4
2 -> 1
3 -> 1
4 -> 3
5 -> 1
6 -> 5
7 -> 5
8 -> 7

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
4
*/