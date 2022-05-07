/*
page 179
Algorithm 3.18 Finding the kth-smallest element

//Selects the kth-smallest element in a[1:n] and place it
//in the kth position of a[]. The remaingn elemnets are
//rearranged such that a[m] < a[k] for 1 <= m < k, and
//a[m] >= a[k] for k < m <= n

Algorithm Select1(a,n,k)
{
    low = 1;
    up = n + 1;
    a[n+1] = INF; // a[n+1] is set to infinity
    do
    {
        //Each time the loop is entered
        //1 <= low <= k <= up <= n+1
        j = partition(a,low, up);
        //j is such that a[j] is the jth-smallest value in a[]

        if(k = j)
        return;
        else if(k<j)
        up = j; // j is the new upper limit
        else
        low = j + 1; // j+1 is the new lower limit
    }while(false);

}
 = {65, 70, 75, 80, 85, 60, 55, 50, 45, INF};
 65 70 75 80 85 60 55 50 45 2147483647
*/
#include <iostream>
#include <ctime>
#define INF 2147483647
using namespace std;
void MIN(int A[], int K, int N, int &LOC)
{
    int min = A[K];
    LOC = K;
    for (int i = K + 1; i < N; i++)
    {
        if (min > A[i])
        {
            min = A[i];
            LOC = i;
        }
    }
}
void selection(int A[], int N)
{
    int LOC = 0;
    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        MIN(A, i, N, LOC);
        temp = A[i];
        A[i] = A[LOC];
        A[LOC] = temp;
    }
}
int partition(int a[], int l, int u)
{
    int v, i, j, temp;
    v = a[l];
    i = l;
    j = u + 1;

    do
    {
        do
            i++;
        while (a[i] <= v && i <= u);

        do
            j--;
        while (v < a[j]);

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    a[l] = a[j];
    a[j] = v;
    return (j);
}
void Select1(int a[], int n, int k)
{
    int low = 1, j;
    int up = n + 1;
    a[n + 1] = INF; // a[n+1] is set to infinity
    do
    {
        // Each time the loop is entered
        // 1 <= low <= k <= up <= n+1
        j = partition(a, low, up);
        // j is such that a[j] is the jth-smallest value in a[]

        if (k == j)
            return;
        else if (k < j)
            up = j; // j is the new upper limit
        else
            low = j + 1; // j+1 is the new lower limit
    } while (true);      // Until its become false
}

void PrintArray(int array[], int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    srand(time(0));
    int size = 10, key;
    int array[100];
    for (int i = 1; i < size; i++)
    {
        cin >> array[i];
    }
    PrintArray(array, 1, size);
    // Select1(array, size, 5);
    for (int i = 1; i < size; i++)
        Select1(array, size, 7);
    PrintArray(array, 1, size);

    return 0;
}
/*
now its making sence
65 70 75 80 85 60 55 50 45
65 70 75 80 85 60 55 50 45
45 50 55 60 65 70 75 80 85
*/