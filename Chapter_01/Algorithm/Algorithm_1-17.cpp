/*
page 51
Algorithm 1.17 Sequential search
*/
#include <iostream>
#include <ctime>
using namespace std;
int SeqSearch(int A[], int x, int n)
{
    int i = n;
    A[0] = x;
    while (A[i] != x)
    {
        i--;
    }
    return i;
}
int main()
{
    srand(time(0));
    int x, N = rand() % 100, A[N];
    for (int i = 0; i < 10; i++)
    {
        for (int i = 1; i <= N; i++)
        {
            A[i] = rand() % 20;
            cout << A[i] << " ";
        }

        x = rand() % 20;
        cout << "\nkey    = " << x << "\n";
        cout << "Position = " << SeqSearch(A, x, N) << "\n";
    }

    getchar();
    return 0;
}
/*
12 0 19 7 11 2 13 7 16 3 7 7 4 10 2 1 16 18 5 9 1 12 7 10 19 14 4 12 19 18 3 19 6 12 7 15 10 10 1 12 
key    = 11
Position = 5
11 17 8 14 2 17 11 17 8 10 2 4 11 16 3 14 0 0 3 19 11 12 9 12 17 3 3 3 3 5 7 5 13 5 12 5 13 6 4 15 
key    = 14
Position = 16
15 16 9 11 14 2 1 0 14 2 3 15 15 8 12 18 11 12 19 12 19 11 3 13 7 6 17 12 14 5 19 16 7 2 1 8 5 18 15 10 
key    = 18
Position = 38
10 4 5 13 1 9 15 6 14 17 15 5 17 11 16 19 3 5 9 0 10 12 18 16 13 11 2 4 3 12 19 4 13 5 7 15 11 12 0 2
key    = 8
Position = 0
9 7 8 13 3 8 9 6 5 17 2 10 10 12 4 16 4 18 17 19 13 17 11 15 6 4 10 8 19 5 9 10 0 4 16 6 7 6 0 9
key    = 17
Position = 22
9 18 1 5 14 5 0 6 14 18 15 17 13 13 19 7 8 13 8 17 14 12 6 16 6 8 4 5 19 14 5 14 11 13 13 14 0 13 4 15
key    = 16
Position = 24
16 2 1 0 0 14 1 7 15 8 7 4 15 5 12 1 6 13 0 9 1 0 19 1 3 8 4 14 8 14 7 2 15 18 11 4 5 12 7 9
key    = 11
Position = 35
8 19 17 18 10 17 13 12 18 9 18 18 10 12 17 0 6 12 0 8 7 0 10 3 7 9 19 4 0 2 14 2 19 4 6 0 11 9 6 11
key    = 14
Position = 31
1 12 12 18 14 9 19 4 8 15 3 17 8 7 15 10 11 3 4 18 9 10 12 18 18 11 11 16 19 4 11 2 9 13 1 9 16 8 5 13
key    = 6
Position = 0
9 15 8 18 4 12 19 7 6 15 4 12 14 9 8 6 13 1 18 7 16 4 1 1 12 7 3 6 9 3 10 2 0 10 11 7 15 18 1 11
key    = 15
Position = 37
*/