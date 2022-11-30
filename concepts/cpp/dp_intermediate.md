# Dynamic Programming (Intermediate)

From wikipedia

> Dynamic programming is both a mathematical optimization method and a computer programming method. The method was developed by Richard Bellman in the 1950s and has found applications in numerous fields, from aerospace engineering to economics. In both contexts it refers to simplifying a complicated problem by breaking it down into simpler sub-problems in a recursive manner.

Dynamic programming is a technique that combines the correctness of complete 
search and the efficiency of greedy algorithms. Dynamic programming can be
applied if the problem can be divided into overlapping subproblems that can be 
solved independently.

There are two uses for dynamic programming:

* Finding an optimal solution: We want to find a solution that is as large as possible or as small as possible.
* Counting the number of solutions: We want to calculate the total number of possible solutions.

## 💢 Problem: Longest Common Subsequences

LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.

* A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

**Examples:**

* LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
* LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. 

**Algorithms**

Recursive

```cpp
// Algorithm: Longest Common Subsequence
// Input    : Two sequences
// Output   : Length of longest common subsequences

int LCS(m: int, n: int) {
  if(m*n == 0) return 0;
  if(a[m] == b[n]) return LCS(m-1, n-1) + 1;
  else
    return max(LCS(m-1, n), LCS(m, n-1));
}
```

Use dynamic programming with Memoization

```cpp
// Algorithm: Longest Common Subsequence
// Input    : Two sequences
// Output   : Length of longest common subsequences

string A, B
int L[M][N];
if (a[i] == b[j]){
  L[M][N] = L[M-1][N-1] + 1
} else {
  L[M][N] = max(L[M][N-1], L[N][M-1]);
}
```

Complexity: $O(M \times N)$

**Implementation**

```cpp

```

**Complexity**: Time: exponential, space: $O(n)$

## 🔗 Further Reading

* [Longest common subsequence problem](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem), wikipedia
* ▶️ [Dynamic Programming | Set 4 (Longest Common Subsequence) | GeeksforGeeks](https://www.youtube.com/watch?v=HgUOWB0StNE&ab_channel=GeeksforGeeks), GeeksforGeeks, 2017
* [Longest Common Subsequence | DP-4](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/), GeeksforGeeks, 2022
* ▶️ [Longest Common Subsequence (Dynamic Programming)](https://www.youtube.com/watch?v=Qf5R-uYQRPk&ab_channel=CSDojo), CS Dojo, 2016
