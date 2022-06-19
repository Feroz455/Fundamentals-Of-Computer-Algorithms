/*
Page 600 
Algorithm 12.5 Heuristic algorithm for Knapsack problem
Algoritthm  EpsilonApprox(p, w, m, n, k)
//The size of a combination is the number of objects in it
//The height of a combinations is the sum of the weight 
//of the objects in that combination k is a nonnegative 
//integet that defines the orer of the algorithm 
{
    Pmax = 0;
    for(all combinations l  size <= k and weight <= m do)
    {
        P[l] = SUM_Of(P[i]);
        Pmax = max(Pmax, p[l] + LBound(l, p, w, m, n)); 
    }
    return Pmax;
}
*/