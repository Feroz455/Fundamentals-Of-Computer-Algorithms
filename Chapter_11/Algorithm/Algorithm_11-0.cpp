/*
Algorithm 11.3 Deterministic sum

Algorithm Sum(A, n, m)
{
    s = 1; // s is an (m + 1) bit word. Bit zero is 1
    for ( i  = 1 to n do )
    {
        s = s or shift (s, A[i]);
        if the mth bit in s is 1 
        cout << "A subset sums to m";
        else 
        cout << "No subset sums to m";
    }
}
*/