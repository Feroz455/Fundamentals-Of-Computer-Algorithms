/*
Given n boolean variable x1, x2,...... and xn. We wish to print all possible combination of truth values they can
assume.For instance, if n = 2; there are four possiblities: true,true; true,fasle; false,true; false,false;
*/
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;
int main()
{
    int const n = 4, temp = pow(2, n);
    for (int i = 0; i < temp; i++)
    {
        cout << std::bitset<n>(i) << " \n";
    }
}
/*
0000 
0001 
0010 
0011 
0100 
0101 
0110 
0111 
1000 
1001 
1010 
1011 
1100 
1101 
1110 
1111
*/