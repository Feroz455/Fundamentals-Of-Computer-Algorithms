/*
Page 469
Algorithm 9.14 Moving down a tree

//n = 2^(m-1) and t[1,1] is given. Also a[1:m, 1:n] is given
//containing a binary tree of values. The algorithm produces
//elements and stores them in the arry t[1:m, 1:n] at the
//position that corresponding to the nodes of the binary tree in figure 9.4
{
    for i = 2 to m do
    {
        p = 1;
        for(j = 1 to 2^(i-1) step 2 do)
        {
            t[i,j] = s[i,j]*t[i-1][p];
            t[i,j+1] = s[i][j+1] * t[i-1][p];
            p = p + 1;
        }
    }
}
*/