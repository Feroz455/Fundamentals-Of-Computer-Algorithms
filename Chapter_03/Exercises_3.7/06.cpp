/*
page 188

06. [Shamos] Let x[1:n] and y[1:n] contain two sets of integer,
each sorted in nondecereasing order. Write a algorithm that finds the
median of the 2n combined elements. What is the time complexity of your
algorithm.
*/
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
using namespace std;
void mergeArrays(int A[], int R, int B[], int S, int C[])
{
    int NA = 0, NB = 0, PTR = 0;
    while (NA < R && NB < S)
    {
        if (A[NA] < B[NB])
            C[PTR++] = A[NA++];
        else
            C[PTR++] = B[NB++];
    }
    while (NA < R)
        C[PTR++] = A[NA++];
    while (NB < S)
        C[PTR++] = B[NB++];
}
void InsertionSort(int a[], int low, int high)
{
    int item = 0, i;
    for (int j = low; j < high; j++)
    {
        // a[1:j-1] is already sorted
        item = a[j];
        i = j - 1;
        while ((i >= low) && (item < a[i]))
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = item;
    }
}
// A simple function to find median of arr[].  This is called
// only for an array of size R in this program.
int findMedian(int arr[], int n)
{
    InsertionSort(arr, 0, n); // Sort the array
    return arr[n / 2];        // Return middle element
}
void PrintArray(int array[], int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << setw(4) << array[i];
    }
    cout << "\n";
}
int main()
{
    srand(time(0));
    int sizex = 20;
    int sizey = 25;
    int x[sizex], y[sizey], combine[sizex + sizey];
    for (int i = 0; i < sizex; i++)
    {
        x[i] = rand() % 100;
    }
    for (int i = 0; i < sizey; i++)
    {
        y[i] = rand() % 100;
    }

    InsertionSort(x, 0, sizex);
    InsertionSort(y, 0, sizey);
    mergeArrays(x, sizex, y, sizey, combine);
    PrintArray(x, 0, sizex);
    PrintArray(y, 0, sizey);
    PrintArray(combine, 0, sizex + sizey);
    cout << "Midian -> " << (combine[(sizex + sizey) / 2]);
    // cout << "Midian" << findMedian(combine, sizex + sizey);

    return 0;
}
/*
 0   4  17  25  26  30  31  37  51  62  68  74  75  76  85  86  89  93  96  98
   0   2   9  12  16  16  27  34  40  43  46  48  48  52  53  57  60  63  68  70  73  79  85  91  94
   0   0   2   4   9  12  16  16  17  25  26  27  30  31  34  37  40  43  46  48  48  51  52  53  57  60  62  63  68  68  70  73  74  75  76  79  85  85  86  89  91  93  94  96  98
Midian -> 52


complixity
time -> O(1)+O(2n);
space complexity  O(2n);

*/