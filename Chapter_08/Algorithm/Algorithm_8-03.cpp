/*
Page 420

Algorithm 8.3 Reduction pseudocode for knapsack problem 

Algorithm Reduce(p, w, n, m, l1, l2)
//Variable are as described in the discussion 
//p[i]/w[i] >= p[i+1]/w[i+1], 1 <= i < n
{
    l1 = l2 = 0;
    q = lbb(0, 0);
    k = largest j such that w[1] + .... + w[j] < m
    for(i = 1; to k do)
    {
        if(Ubb(0,{i}) < q) then l1 = l1 U {i};
        else 
        if(Lbb(0,{i}) > q) 
        q = Lbb(0,{i});

    }
    for(i = k + 1; to n do)
    {
        if(Ubb({i}, 0) < q) 
        I2 = I2 U {i};
        else if (Lbb({i},0) > q)
        q = Lbb({i},0);
    }
}
*/