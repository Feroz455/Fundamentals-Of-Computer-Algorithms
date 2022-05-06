/*
Supporse a[1:m] and b[1:n] both contain soted elements in nondecreasing orer.
Write an algorithm that merges these items into c[1:m+n] Your algorthm should be sorter algorithm 3.9 
(merge) since you can now place a large value in a[m+1] and b[n+1];
*/#include <iostream>
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
int main()
{
    int R = 6, S = 7, C[R + S];
    int A[R] = {45, 12, 34, 66, 99, 88};
    int B[S] = {65, 25, 35, 15, 75, 55, 45};
    selection(B, S);
    selection(A, R);
    mergeArrays(A, R, B, S, C);
    cout << "\n";
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : B)
    {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : C)
    {
        cout << x << " ";
    }
}
/*
12 15 23 25 35 45 45 65 66 75 87 95
*/