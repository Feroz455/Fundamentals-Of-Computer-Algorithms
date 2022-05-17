/*
Page 287
02) Modify the function AllPaths so that a shortest path is output for each pair
of vertices(i,j). What are the time and space complexities of the new algorithm?
*/
#include <iostream>
#include <iomanip>
#define NODE 7
using namespace std;
// Cost matrix of the graph
int costMat[NODE][NODE] = {
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1}};
void floydWarshal()
{
    int cost[NODE][NODE]; // defind to store shortest distance from any node to any node
    for (int i = 0; i < NODE; i++)
        for (int j = 0; j < NODE; j++)
            cost[i][j] = costMat[i][j]; // copy costMatrix to new matrix

    for (int k = 0; k < NODE; k++)
    {
        for (int i = 0; i < NODE; i++)
            for (int j = 0; j < NODE; j++)
                if (cost[i][k] && cost[k][j])
                    cost[i][j] = 1;
    }
    cout << "The matrix:" << endl;
    for (int i = 0; i < NODE; i++)
    {
        for (int j = 0; j < NODE; j++)
            cout << setw(3) << cost[i][j];
        cout << endl;
    }
}
int main()
{
    floydWarshal();
}
/*
The matrix:
  0  3  5  4  6  7  7
  3  0  2  1  3  4  4
  5  2  0  1  3  2  3
  4  1  1  0  2  3  3
  6  3  3  2  0  2  1
  7  4  2  3  2  0  1
  7  4  3  3  1  1  0
*/