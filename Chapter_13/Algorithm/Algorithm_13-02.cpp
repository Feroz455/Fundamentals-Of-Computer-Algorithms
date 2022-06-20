/*
Page 634 
Algorithm 13.2 Prefix computation in O (lon n) time



Step 0. If n = 1, one processor output x1
step 1: Let the first n/2 processor recursively compute the prefixes of x1, x2, ..... xn/2 and let
y1 , y2 .... yn / 2 be the result. At the same time let the rest of the processor recursively compute the prefixes 
of Xn/2+1,.....,Xn and let Yn/2+1, Yn/2+2 ,....., yn be the output

step 2 : Note that the first half of the answer is the same as y1, y2, .... yn/2. The second half of the final answer
Yn/2 associative(+) yn/2+1, Yn/2+2, .... , Yn /2 associative(+) yn

Let the second half of the processor read yn/2 concurrently from the global memory and update their answer. this step 
take O(1);
*/