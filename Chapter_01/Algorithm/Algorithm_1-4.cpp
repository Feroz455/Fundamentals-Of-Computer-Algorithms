/*

page 13
Algorithm Perm(a,k,n)
{
    if(k = n) then write (a[1:n]); // output permution
    else  // a[k:n] has more than one permutaion
    //Generate these recursively
    for i := k to n do
    {
        t := a[k];
        a[k] = a[i];
        a[i] = t;

        Perm(a, k+1, n);
        //All permutation s of a[k+1 : n];
        t := a[k];
        a[k] = a[i];
        a[i] = t;
    }
}
*/
#include <iostream>
using namespace std;
template <typename T>
void interchange(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
    return;
}
void Perm(char a[], int k, int n)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    else
        for (int i = k; i < n; i++)
        {
            interchange<char>(a[i], a[k]);
            Perm(a, k + 1, n);
            interchange<char>(a[i], a[k]);
        }
}
int main()
{
    int n = 5, k = 0;
    char a[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = 65+i;
       // cout << a[i] << " ";
    }
    Perm(a, k, n);
    return 0;
}
/*
output 
A B C D E 
A B C E D 
A B D C E 
A B D E C 
A B E D C 
A B E C D 
A C B D E 
A C B E D 
A C D B E 
A C D E B 
A C E D B 
A C E B D
A D C B E
A D C E B
A D B C E
A D B E C
A D E B C
A D E C B
A E C D B 
A E C B D
A E D C B
A E D B C
A E B D C
A E B C D
B A C D E
B A C E D
B A D C E 
B A D E C
B A E D C
B A E C D
B C A D E
B C A E D
B C D A E 
B C D E A
B C E D A
B C E A D
B D C A E
B D C E A 
B D A C E
B D A E C
B D E A C
B D E C A
B E C D A 
B E C A D
B E D C A
B E D A C
B E A D C
B E A C D 
C B A D E
C B A E D
C B D A E
C B D E A
C B E D A
C B E A D 
C A B D E
C A B E D
C A D B E
C A D E B
C A E D B
C A E B D
C D A B E 
C D A E B
C D B A E
C D B E A
C D E B A
C D E A B
C E A D B
C E A B D 
C E D A B
C E D B A
C E B D A
C E B A D
D B C A E
D B C E A
D B A C E
D B A E C 
D B E A C
D B E C A
D C B A E
D C B E A
D C A B E
D C A E B
D C E A B
D C E B A
D A C B E
D A C E B 
D A B C E
D A B E C
D A E B C
D A E C B
D E C A B
D E C B A
D E A C B 
D E A B C
D E B A C
D E B C A
E B C D A
E B C A D
E B D C A
E B D A C 
E B A D C
E B A C D
E C B D A
E C B A D
E C D B A
E C D A B
E C A D B
E C A B D 
E D C B A
E D C A B
E D B C A
E D B A C
E D A B C 
E D A C B
E A C D B
E A C B D 
E A D C B
E A D B C
E A B D C
E A B C D
*/