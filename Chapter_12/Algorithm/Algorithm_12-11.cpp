/*
Algorithm 12.10 Function for Exercises
Algorithm SetCover(F)
//S [i] 1 <= i <= m are the sets in F. |S[i| is the number of elements in S[i] |U S[i| = n
{
    G = U S[i];
    for i = 1; to m do 
    R[i] = S[i];
    con = -; // ELements covered 
    T = 0; // Cover being constructed 
    while(cov != G )
    {
        Let R[j] be such that |R[j]| >= R[q] 1 <= q <= m;
        cov = cov U R[j];
        T = T U S[j];
        for i  = 1; to m do R[i] = R[i] - R[j]; 
    }
    return T;
}
*/