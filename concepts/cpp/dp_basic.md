# Dynamic Programming (Basic)

Dynamic programming is a technique that combines the correctness of complete 
search and the efficiency of greedy algorithms. Dynamic programming can be
applied if the problem can be divided into overlapping subproblems that can be 
solved independently.

There are two uses for dynamic programming:

* Finding an optimal solution: We want to find a solution that is as large as possible or as small as possible.
* Counting the number of solutions: We want to calculate the total number of possible solutions.

## Fibonnaci Number

The Fibonacci numbers are the numbers in the following integer sequence.

$0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...$

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

$F_n = F_{n-1} + F_{n-2}$

with seed values

$F_0 = 0$ and $F_1 = 1$