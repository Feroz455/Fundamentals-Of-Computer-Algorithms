/*
Page 165
//Sorting the array a[1:n] into nondecreasing order, n >= 1
Algorithm insertionSort(a, n)
{
    for(j = 0;j < n; j++)
    {
        //a[1:j-1] is already sorted
        item = a[j];
        i = j -1 ;
        while((i >= 1) && (item < a[i]))
        {
            a[i+1] = a[i];
            i = i -1;
        }
        a[i+1] = item;
    }

}
*/
#include <iostream>
#include <ctime>
using namespace std;

void insertionSort(int a[], int n)
{
    int item = 0, i;
    for (int j = 1; j < n; j++)
    {
        // a[1:j-1] is already sorted
        item = a[j];
        i = j - 1;
        while ((i >= 0) && (item < a[i]))
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = item;
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main()
{
    srand(time(0));
    int size = 20;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    printArray(array, size);
    insertionSort(array, size);
    printArray(array, size);
}
/*
10 31 16 46 14 11 30 37 34 2 35 10 9 25 9 21 48 47 24 31
2 9 9 10 10 11 14 16 21 24 25 30 31 31 34 35 37 46 47 48
*/