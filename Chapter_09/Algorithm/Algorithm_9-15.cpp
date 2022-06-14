/*
Page 473 
Algorithm 9.15 Balaced interpolation

Algorithm BalancedInterp(U1, U2, Q1, Q2, k)
//U1, U2, Q1 and Q2 are all polynomials in x. U1 interpolates 
//the first k/2 points and U2  interpolates the next k/2 points 
{
    //a mod b computes the poly reminder of a a(x)/b(x)
     P1 = U1 % Q2;
    P2 = Q1 % Q2;
    //The extended Euclidean alg. for polynomials
    P3 = ExEuclid(P2, Q2);
    P4 = P3 = % Q2;
   return U1 + (U2 - P1) * P4 * Q1;
}
*/