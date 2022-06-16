/*
Page 522
Algorithm 11.5 Nondeterministic clique pseudocode

Algorithm DCK(G, n, k)
{
    S = 0; // S is an inititally empty set
    for(i = 1 to k do)
    {
        t = Choice(1,n);
        if( t belong S)
        {
            then Failure();
        }
        S = S U {t}; // Add t to set S
    }
    //At this point S contains k distinct vertex indices
    for all pairs(i, j) such that i belong S, j belong S, and i != j do
    if(i, j) is not an edge of G then Failure();
    Success();
}
*/