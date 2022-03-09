/*
Give an algorithm to solve the following problem. Give n a positive integer, determain whether n is sum of all
of its divisors, that is wether n is sum of all t such that 1 <= t < n, and t devides n;
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void Check_sum_of_divisors(int N)
{
    int sum = 0;

    for (int i = 1; i < N; i++)
    {
        if (N % i == 0)
        {
            sum += i;
        }
    }
    if (sum == N)
    {
        cout << N << " is the sum of all its divisors \n";
    }
    else
        cout << N << " IS NOT!!!\n";
}

int main()
{
    srand(time(0));
    int N;
    for (int i = 0; i < 100; i++)
    {
        N = rand() % 100;
        Check_sum_of_divisors(N);
    }

    return 0;
}
/*
output
34 IS NOT!!!
49 IS NOT!!!
64 IS NOT!!!
21 IS NOT!!!
5 IS NOT!!!
0 is the sum of all its divisors 
27 IS NOT!!!
37 IS NOT!!!
83 IS NOT!!!
8 IS NOT!!!
19 IS NOT!!!
52 IS NOT!!!
40 IS NOT!!!
21 IS NOT!!!
13 IS NOT!!!
83 IS NOT!!!
25 IS NOT!!!
88 IS NOT!!!
35 IS NOT!!!
78 IS NOT!!!
91 IS NOT!!!
56 IS NOT!!!
76 IS NOT!!!
26 IS NOT!!!
57 IS NOT!!!
80 IS NOT!!!
76 IS NOT!!!
33 IS NOT!!!
85 IS NOT!!!
38 IS NOT!!!
32 IS NOT!!!
97 IS NOT!!!
35 IS NOT!!!
14 IS NOT!!!
25 IS NOT!!!
79 IS NOT!!!
61 IS NOT!!!
31 IS NOT!!!
87 IS NOT!!!
1 IS NOT!!!
14 IS NOT!!!
37 IS NOT!!!
83 IS NOT!!!
14 IS NOT!!!
53 IS NOT!!!
32 IS NOT!!!
86 IS NOT!!!
60 IS NOT!!!
33 IS NOT!!!
84 IS NOT!!!
6 is the sum of all its divisors
65 IS NOT!!!
19 IS NOT!!!
53 IS NOT!!!
23 IS NOT!!!
42 IS NOT!!!
51 IS NOT!!!
85 IS NOT!!!
67 IS NOT!!!
38 IS NOT!!!
39 IS NOT!!!
76 IS NOT!!!
45 IS NOT!!!
63 IS NOT!!!
88 IS NOT!!!
27 IS NOT!!!
56 IS NOT!!!
90 IS NOT!!!
70 IS NOT!!!
32 IS NOT!!!
14 IS NOT!!!
7 IS NOT!!!
82 IS NOT!!!
57 IS NOT!!!
27 IS NOT!!!
38 IS NOT!!!
78 IS NOT!!!
43 IS NOT!!!
76 IS NOT!!!
49 IS NOT!!!
61 IS NOT!!!
28 is the sum of all its divisors
60 IS NOT!!!
98 IS NOT!!!
8 IS NOT!!!
32 IS NOT!!!
13 IS NOT!!!
37 IS NOT!!!
56 IS NOT!!!
33 IS NOT!!!
62 IS NOT!!!
41 IS NOT!!!
12 IS NOT!!!
85 IS NOT!!!
72 IS NOT!!!
45 IS NOT!!!
65 IS NOT!!!
73 IS NOT!!!
62 IS NOT!!!
2 IS NOT!!!
*/