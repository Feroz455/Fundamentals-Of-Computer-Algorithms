/*
Page 468 
Algorithm 9.13 Moving up a tree
Algorithm MOveUpTree(t, n)
//n = 2^(m-1) value are stored in t[1:m,1:n] in locations
//t[m,1:n]. The algorithm causes the nodes of a binary tree 
//to be visited so that at each node an abstruct binary oearation 
//denoted by  *  is performed. the resulting values are stored 
//in the array as indicated in figure 9.4 
{
    for(i = m - 1; to 1 step -1 do)
    {
        p = 1;
        for(j = 1 to 2^(i-1) do)
        {
            t[i][j] = t[i+1][p] * t[i+1][p+1];
            p = p + 2;
        }
    }
}
*/