/*
page 217
02) Extend the greedy solution for the container loading problem
to the case where there are two ship. Does your algorithm always
generate optimal solution
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

int weight[] = {100, 200, 50, 90, 150, 50, 20, 80};
int n = (sizeof(weight) / sizeof(int));
bool cmp(Container a, Container b)
{
    return (a.weight < b.weight);
}

void ContainerLoading(Container c[], int capacity)
{
    // sort into incesing order of weight
    int capa = capacity;
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
    cout << "In Greedy solution we have for capaity " << capa << "\n";
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

    Container c[n];
    for (int i = 0; i < n; i++)
    {
        c[i].id = i;
        c[i].weight = weight[i];
    }
    sort(c, c + n, cmp);
    int capacity;
    cout << "Enter first-ship's capacity\n";
    cin >> capacity;
    ContainerLoading(c, capacity);
    cout << "Enter second-ship's capacity\n";
    cin >> capacity;
    ContainerLoading(c, capacity);
    return 0;
}
/*
Enter first-ship's capacity
400
In Greedy solution we have for capaity 400
x[0] -> 1
x[1] -> 0
x[2] -> 1
x[3] -> 1
x[4] -> 0
x[5] -> 1
x[6] -> 1
x[7] -> 1
Sum of xi -> 6
Enter second-ship's capacity
600
In Greedy solution we have for capaity 600
x[0] -> 1
x[1] -> 0
x[2] -> 1
x[3] -> 1
x[4] -> 1
x[5] -> 1
x[6] -> 1
x[7] -> 1
Sum of xi -> 7
*/