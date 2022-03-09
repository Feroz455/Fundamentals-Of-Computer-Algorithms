/*
Given n boolean variable x1, x2,...... and xn. We wish to print all possible combination of truth values they can
assume.For instance, if n = 2; there are four possiblities: true,true; true,fasle; false,true; false,false;
*/
#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;
void truth_table(int n)
{
    /* generate a truth_table by transforming # of
     permutations into binary */
    int i, j, div, rem;
    string str;
    for (i = 0; i < pow(2, n); i++)
    { /*number of permutations or rows in the table */
        str = "\0";
        div = i;
        for (j = n; j > 0; j--)
        {
            /*number of bits needed for each row*/
            rem = div % 2;
            div = div / 2;
            if (!rem)
                str += "FALSE ";
            else
                str += "TRUE  ";
        }
        cout << setw(10) << str << "\n";
    }
}
int main()
{
    int n;
    cout << "(n:>=0): -> ";
    cin >> n;
    while (n <= 0)
    { /*error loop */
        cout << "(n:>=0): -> ";
        cin >> n;
    }
    truth_table(n);
    return 0;
}
/*
(n:>=0): -> 4
FALSE FALSE FALSE FALSE
TRUE  FALSE FALSE FALSE
FALSE TRUE  FALSE FALSE
TRUE  TRUE  FALSE FALSE
FALSE FALSE TRUE  FALSE
TRUE  FALSE TRUE  FALSE
FALSE TRUE  TRUE  FALSE
TRUE  TRUE  TRUE  FALSE
FALSE FALSE FALSE TRUE
TRUE  FALSE FALSE TRUE
FALSE TRUE  FALSE TRUE
TRUE  TRUE  FALSE TRUE
FALSE FALSE TRUE  TRUE
TRUE  FALSE TRUE  TRUE
FALSE TRUE  TRUE  TRUE
TRUE  TRUE  TRUE  TRUE
*/