/*
Page 596

Algorithm 12.3 Scheduling 

Algorithm Schedule(f,t)
{
    for( i = 1; i <= m ; i++)
    {
        f[i] = 0;
    }
    for( i = 1; i <= n ; i++)
    {
       k = least j suc that 
       f[j] + t[i][j] <= f[l] + t[i][l], 1 < l <= m
       f[k] = f[k]+ t[i][k];
    }
}
*/