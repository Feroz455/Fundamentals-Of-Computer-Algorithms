/*
Page 102
Algorithm Insert(a,n)
{
    //Insert a[n] into the heap which is sorted in a[1:n-1];
    i := n; item := a[n];
    while((i>1) and (a[floor(i/2)]) < item)) do
    {
    a[i] := a[floor(i/2)]; i := floor(i/2);
    }
    a[i] := item;
    return true;
}

*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
bool Insert(int array[], int N)
{
    // Insert a[n] into the heap which is stored in a[1:n-1];
    int i = N, item = array[N];
    while ((i > 1) && (array[(i / 2)] < item))
    {
        array[i] = array[i / 2];
        i = i / 2;
    }
    array[i] = item;
    return true;
}
int main()
{
    srand(time(0));
    int array[100];
    int N = 1, item;
    for (int i = 1; i < 10; i++)
    {
        item = rand() % 20;
        array[i] = item;
        cout << item << " ";
        Insert(array, i);
    }
    cout << "\n";
    for (int i = 1; i < 10; i++)
    {

        cout << array[i] << " ";
    }
    return 0;
}
/*
0 13 10 13 7 15 12 3 4 
15 13 13 4 7 10 12 0 3
*/