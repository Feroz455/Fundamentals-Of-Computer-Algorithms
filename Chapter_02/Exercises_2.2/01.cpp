/*
page 91 Show that the height of binary tree that has n, n>=0 nodes is at most
n and at least ceil(log2(n+1))
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    srand(time(0));
    int temp;
    for (int i = 0; i < rand() % 20; i++)
    {
        temp = rand() % 20;
        cout << "Number of node -> " << setw(5) << temp << " ";
        cout << " Height of the tree -> " << setw(5) << ceil(log2(temp + 1)) << "\n";
    }

    return 0;
}
/*
Number of node ->     2  Height of the tree ->     2
Number of node ->     6  Height of the tree ->     3
Number of node ->     4  Height of the tree ->     3
Number of node ->    17  Height of the tree ->     5
Number of node ->    13  Height of the tree ->     4
*/