/*
Page 621
Algorithm 12.12 Function for Exercises 4

Algorithm MSC(F)
//Same variable as in SetCover
{
    T = 0 ;
    left = {S[i] | 1 <= i <= m};
    G = U S[i];
    while(G != 0)
    {
        Let S[i] be a set in Left such that
        |S[j] - G| / S[j] intersect G| <= S[q] / intersect G| for all S[q] in Left
        T = T U S[j];
        G = G - S[j];
        Left = Left - S[j];
    }
    return T
}
*/