/*
If S is a set of n elements, the powerset of S is the set of all possible
subset of S.
For example , if S = (a, b, c) then powerset (S) = { (), (a), (b), (c), (a,b), (a,c), (b,c), (a,b,c)};
Write a recursive algorithm to copmpute powerset;
*/
#include <iostream>
#include <string>
using namespace std;

// str : Stores input string
// curr : Stores current subset
// index : Index in current subset, curr
void powerSet(string str, int index = 0, string curr = "")
{
    int n = str.length();

    // base case
    if (index == n)
    {
        cout << curr << endl;
        return;
    }

    // Two cases for every character
    // (i) We consider the character
    // as part of current subset
    // (ii) We do not consider current
    // character as part of current
    // subset
    powerSet(str, index + 1, curr + str[index]);
    powerSet(str, index + 1, curr);
}

// Driver code
int main()
{
    string str = "abc";
    powerSet(str);
    return 0;
}
/*
abc
ab
ac
a
bc
b
c
*/