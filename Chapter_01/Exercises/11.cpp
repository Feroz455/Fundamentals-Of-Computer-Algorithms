/*
Consider the function F(x) that is defined by "if x is even then F(x) = x % 2
else F(x) = F(F(2*x+1))". Prove that F(x) terminates for all integer x.
(Hints . consider integer of the form (2i + 1)2^k -1 and use induction
*/
/*
Let x be an integer. If x2+x+1 is even, then x is odd.

To prove this, I prove its contrapositive. If x is even, x2+x+1 is odd.

All even numbers can be shown as 2k and all odd can we shown as 2k+1, where k is an integer.

Let 2k=x.

4k2+2k+1. I can substitute 1=k and show that the answer is 7 and therefore odd.

What is the next step to show that all k+1 or k+2 or k+x is odd? What is the next step?
*/