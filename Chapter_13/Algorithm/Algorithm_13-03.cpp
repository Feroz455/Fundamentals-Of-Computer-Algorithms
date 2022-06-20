/*
Page 635
Algorithm 13.3 Work-Optimal logarithmic time prefix computation 
Step 1: Processor i ( i = 1,2,,,,,(n/log n)) in paralel computer the prefixes of its
log n assigned elements x(i-1) log n + 1, x(i-1) log n + 2,......, x[i] log n. This 
takes O(log n) time. Let the result be Z(i-1) log n + 1, Z(i -1) log n  + 2 ,......Zi log n,

step 2: A total of n / log n processor collectively employ Algorithm 13.2 to compute the prefixs
of te n/log n elemets zlog n, z log n, z3 log n, ...... , Zn. Let W log n,W2 log n,W3 log n,.... Wn be
the result.

Step 3: Each processor updates the presixes it compute in step 1 as follows. Processor i computes
and Outputs W(i-1) logn associative(+) z(i-1) log n , W(i - 1) log n associative(+) z(i-1) logn + 2
.....W(i -1) log n associative zi log n for i = 2, 3, ....n / log n. Processor 1 outputs z1, z2, ... zlogn 
without any modifications.
*/