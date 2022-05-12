/*
page 216

Algorithm 4.2  loading containers

//Greedy algorithm for container loading
//set x[i] = 1 iff container c[i], i >= 1 is loaded

Algorithm ContainerLoading(c, capacity, numberofContainers, x)
{
    //sort into incesing order of weight

    sort(c, numberofContainer);

    n = numberofContainer;

    //initialize x

    for(i = 1, i < n; i++)
    {
        x[i] = 0;
    }

    //select containers in order of weight
    i = 1;

    while(i <= n && c[i].weight <= capacity)
    {
        //enough capacity for container c[i].id;
        x[c[i].id] = 1;
        cpacity -= c[i].weight; // remaining capacity
        i++;
    }
}
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
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] -> " << x[i] << "\n";
        if(x[i])
        check++;
    }
    cout << "Sum of xi -> " << check << "\n";
    return;
}
void Print(Container c[])
{
    for (int i = 0; i < n; i++)
    {
        cout << c[i].id << " " << c[i].weight << "\n";
    }
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
400
x[0] -> 1
x[1] -> 0
x[2] -> 1
x[3] -> 1
x[4] -> 0
x[5] -> 1
x[6] -> 1
x[7] -> 1
Sum of xi -> 6
*/