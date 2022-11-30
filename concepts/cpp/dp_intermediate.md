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

### Examples

* LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
* LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. 

### Algorithms

Use recursive

```cpp
// Algorithm: Longest Common Subsequence
// Input    : Two sequences
// Output   : Length of longest common subsequences

int LCS(n: int, m: int) {
  if(n*m == 0) return 0;
  if(a[n] == b[m]) return LCS(n-1, m-1) + 1;
  else
    return max(LCS(n-1, m), LCS(n, m-1));
}
```

Use dynamic programming with Memoization

```cpp
// Algorithm: Longest Common Subsequence
// Input    : Two sequences
// Output   : Length of longest common subsequences

string A, B
int dp[N][M];
if (A[i] == B[j]){
  dp[N][N] = 1 + dp[N-1][M-1]
} else {
  dp[N][M] = max(dp[N][M-1], dp[N-1][M]);
}
```

**Complexity**

* Time: $O(M \times N)$
* Space: $O(M \times N)$

### Implementation

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

int lcs(string a, string b) {
  int n = a.size();
  int m = b.size();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= m; j++) {
    dp[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == a[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

int main() {
  string a, b;
  
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> a >> b;
    cout << lcs(a, b) << endl;
  }
}
```

<table>
<thead>
<th>Input</th>
<th>Output</th>
</thead>
<tbody>
<tr>
<td valign="top">
<pre>5
aabc
aa
aabccc
aabcc
abcdefg
abcdefg
ABCDGH
AEDFHR
AGGTAB
GXTXAYB</pre>
</td>
<td valign="top">
<pre>2
5
7
3
4</pre>
</td>
</tr>
</tbody>
</table>

## 🔗 Further Reading

* [Longest common subsequence problem](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem), wikipedia
* ▶️ [Dynamic Programming | Set 4 (Longest Common Subsequence) | GeeksforGeeks](https://www.youtube.com/watch?v=HgUOWB0StNE&ab_channel=GeeksforGeeks), GeeksforGeeks, 2017
* [Longest Common Subsequence | DP-4](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/), GeeksforGeeks, 2022
* ▶️ [Longest Common Subsequence (Dynamic Programming)](https://www.youtube.com/watch?v=Qf5R-uYQRPk&ab_channel=CSDojo), CS Dojo, 2016
