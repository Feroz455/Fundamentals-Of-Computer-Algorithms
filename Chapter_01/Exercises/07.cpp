/*
Give both a recursive and iterative algorithm to compute the binomial coefficient (n m) as defined in section 
1.2.2 where (n 0) = (n n) = 1;
*/
#include<iostream>
using namespace std;
int fact(int A)
{
    if (A <= 0)
    {
        return 1;
    }
    else
        return (A * fact(A - 1));
}
int fact_norecursive(int A)
{
    int temp = 1;
    if (A <= 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= A; i++)
        {
            temp = temp * i;
        }
    }
    return temp;
}

int main()
{
    int N, m, n;
    cin >> m >> n;
    N = fact(m)/(fact(n)*fact(m-n));
    cout << N << "\n";
    N = fact_norecursive(m)/(fact(n)*fact(m-n));
    cout << N;
}
/*
output 
run _ 1 

7 3
35
35
run _2

7 7
1
1
run _3
7 0
1 
1
*/