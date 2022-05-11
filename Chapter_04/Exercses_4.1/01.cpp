/*
page 213

2. Write Control abstraction for greedy method by using ordering paradigm?
Ans .
The general rule is that program i is stored on tape Ti mod m .
on any given tape the programs are stored in nondecreasing order of their lengths

Greedy method control abstraction for the ordering paradigm

Algorithm store(n,m)
{
J=0;
For i=1 to n do
{
Write(“append program”,I,”to permutation for tape”,j);
J=(j+1) mod m;
}
*/
