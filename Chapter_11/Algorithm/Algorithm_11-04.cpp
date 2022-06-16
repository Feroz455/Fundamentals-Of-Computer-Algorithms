/*
Page 521 
Algorithm 11.4 Nondeterministic knapsack algorithm

Algorithm DKP(p, w, n, m, r, x)
{
    W = 0;
    P = 0;
    for i = 1 to n do
    {
        x[i] = Choice(1,0);
        W = W + x[i] * w[i];
        P = P + x[i] * p[i];
    }
    if((W > m) or (P < r)) 
    Failure();
    else Success(); 
}
*/