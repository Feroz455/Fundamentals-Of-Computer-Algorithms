/*
page 217

01) Suppose you have 6 containers whose weight are 50, 10, 30, 20, 60, and 5 and a ship whose
capacity is 100. Use algorithm 4.2 to find an optimal solution to this instance of the container loading problem

*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;
struct Container
{
    int id;
    int weight;
};

int weight[] = {50, 10, 30, 20, 60, 5};
int n = (sizeof(weight) / sizeof(int));
bool cmp(Container a, Container b)
{
    return (a.weight < b.weight);
}

void ContainerLoading(Container c[], int capacity)
{
    // sort into incesing order of weight

    // initialize x
    int x[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    // select containers in order of weight
    int i = 0;

    while (i <= n && c[i].weight <= capacity)
    {
        // enough capacity for container c[i].id;
        x[c[i].id] = 1;
        capacity -= c[i].weight; // remaining capacity
        i++;
    }
    cout << "In Greedy solution we have \n";
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] -> " << x[i] << "\n";
        if (x[i])
            check++;
    }
    cout << "Sum of xi -> " << check << "\n";
    return;
}
int main()
{
    int capacity;
    cout << "Enter capacity\n";
    cin >> capacity;
    Container c[n];
    for (int i = 0; i < n; i++)
    {
        c[i].id = i;
        c[i].weight = weight[i];
    }
    sort(c, c + n, cmp);
    ContainerLoading(c, capacity);
    return 0;
}
/*
Enter capacity
100
In Greedy solution we have
x[0] -> 0
x[1] -> 1
x[2] -> 1
x[3] -> 1
x[4] -> 0
x[5] -> 1
Sum of xi -> 4
*/
