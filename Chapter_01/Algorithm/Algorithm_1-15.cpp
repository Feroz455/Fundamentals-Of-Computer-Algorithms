/*
page 44
Example 1.20[Magic squre] The next example we consider is a problem from recreational
mathmatics. A magic squre is an n * n matrix of the integer to n^2 such that the sum
of every row column and diagonal is the same.

H. Coxeter has given the  following simpe rule for generating a magic squre when n is odd
start with 1 in the middle of the tp row; then go up and left assiginig numbers in increasing
order to empty squres; If you fall off the squre imagine the same squre as tilling the plane and
continue; if a squre is occupied , move down instead and continue;

Algorithm 1.15 Magic squre

Algorithm Magic(n)
//Create a magic squre of size n, n begin odd
{
    if((n mod 2) == 0) then
    {
        write ("n is even");
        return;
    }
    else
    {
        for i := 0 to n-1 do // Initialize squre to zero
            for j:=0 to n - 1 do squre[i,j] := 0;
        squre [0, (n-1)/2] := 1; //Middle of first row
        // (i,j) is the current position.
        j := (n-1)/2
        for key := 2 to n^2 do
        {
            // move up and left .The next two if statements
            //may be replaced by the mod operation if
            //-1 mod n has the value n -1
            if(i >= 1) then k:= i - 1; else k := n -1 ;
            if ( j >= 1) then l := j -1; else l := n -1;
            if(squre[k,l] > l) then i:= (i+1) mod n;
            else
             // squre[k,l] is empty
             {
                 i := k;
                 j := l;
             }
             suqure[i][j] = key;
        }
        // Output the magic squre
        for i := 0 to n - 1 do
            for j = 0 to n - 1 do write (square[i][j]);
    }

}

*/
#include <iostream>
using namespace std;
void Magic(int n)
{

    if (n % 2 == 0)
    {
        cout << n << " is even\n";
        return;
    }
    else
    {

        int squre[n][n], i, j, k, l, key;
        //
        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {
                squre[i][j] = 0;
            }
        }
        squre[0][(n - 1) / 2] = 1;
        i = 0;
        j = (n - 1) / 2;
        for (key = 2; key <= (n * n); key++)
        {

            if (i >= 1)
                k = i - 1;
            else
                k = n - 1;

            if (j >= 1)
                l = j - 1;
            else
                l = n - 1;
            if (squre[k][l] >= 1)
                i = (i + 1) % n;
            else
            {
                i = k;
                j = l;
            }
            squre[i][j] = key;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << squre[i][j] << "\t";
            }
            cout << "\n";
        }
    }
}
int main()
{
    int N;
    for (int i = 0; i < 10; i++)
    {
        N = i;
        cout << i << " * " << i << " Magic squre\n";
        Magic(N);
        cout << "\n\n\n\n";
    }

    return 0;
}
/*
0 * 0 Magic squre
0 is even        




1 * 1 Magic squre
1




2 * 2 Magic squre
2 is even




3 * 3 Magic squre
6       1       8
7       5       3
2       9       4




4 * 4 Magic squre
4 is even




5 * 5 Magic squre
15      8       1       24      17
16      14      7       5       23
22      20      13      6       4
3       21      19      12      10
9       2       25      18      11




6 * 6 Magic squre
6 is even




7 * 7 Magic squre
28      19      10      1       48      39      30
29      27      18      9       7       47      38
37      35      26      17      8       6       46
45      36      34      25      16      14      5
4       44      42      33      24      15      13
12      3       43      41      32      23      21
20      11      2       49      40      31      22




8 * 8 Magic squre
8 is even




9 * 9 Magic squre
45      34      23      12      1       80      69      58      47
46      44      33      22      11      9       79      68      57
56      54      43      32      21      10      8       78      67
66      55      53      42      31      20      18      7       77
76      65      63      52      41      30      19      17      6
5       75      64      62      51      40      29      27      16
15      4       74      72      61      50      39      28      26
25      14      3       73      71      60      49      38      36
35      24      13      2       81      70      59      48      37
*/