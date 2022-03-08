/*
The Fibonacchi number are defined as f0 = 0; f1 = 1; fi = fi-1 + fi-2 for i > 1;
a) List the value of f2 through f7;
b) write both a recusive ans an iterative algorithm to compute fi;
*/
#include <iostream>
using namespace std;
void fibonacchi(int F0, int F1, int n)
{
    int fib = 0;
    if (n <= 1)
        return;
    else
    {
        fib = F0 + F1;
        cout << fib << " ";
        F0 = F1;
        F1 = fib;
        fibonacchi(F0, F1, n - 1);
    }
    return;
}
void fibonacchi_Nonrecursive(int fibA, int fibB, int N)
{
    int fib = 0;
    for (int i = 0; i < N - 1; i++)
    {
        fib = fibA + fibB;
        cout << fib << " ";
        fibA = fibB;
        fibB = fib;
    }
}
int main()
{
    int fibA, fibB;
    int N;
    cin >> N;
    fibA = 0;
    fibB = 1;
    fibonacchi(fibA, fibB, N);
    cout << "\n";
    fibonacchi_Nonrecursive(fibA, fibB, N);
    return 0;
}
/*
20
1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 
1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 
*/
