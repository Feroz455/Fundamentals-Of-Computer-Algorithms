/*
Algorithm 12.6 Subalgorithm for function EpsilonApprox

Algorithm LBound(L, p, w, m, n)
{

    s = 0;
    t = m - SumOf(w[i]);
    for(int i = 1; i <= n; i++)
    {
        if( i != l && (w[i] <= t))

        {
            s = s + p[i];
            t = t - w[i];
        }
    }
}
*/