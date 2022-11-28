# Dynamic Programming (Basic)

From wikipedia

> Dynamic programming is both a mathematical optimization method and a computer programming method. The method was developed by Richard Bellman in the 1950s and has found applications in numerous fields, from aerospace engineering to economics. In both contexts it refers to simplifying a complicated problem by breaking it down into simpler sub-problems in a recursive manner.

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

### Method 1: Using recursion

```cpp
#include <vector>
#include <iostream>

using namespace std; 

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
    int n = 5;
    cout << fib(n);
    return 0;
}
```

**Complexity**: Time: exponential, space: $O(n)$

### Method 2: Using dynamic programming 

```cpp
#include <vector>
#include <iostream>

using namespace std; 

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 5;
    cout << fib(n);
    return 0;
}
```

**Complexity**: Time: $O(n)$, space: $O(n)$

## 🔗 Further Reading

* ▶️ [What Is Dynamic Programming and How To Use It](https://www.youtube.com/watch?v=vYquumk4nWw&ab_channel=CSDojo), CS Dojo, 2017
* ▶️ [Dynamic Programming lecture #1 - Fibonacci, iteration vs recursion](https://www.youtube.com/watch?v=YBSt1jYwVfU&ab_channel=Errichto), Errichto, 2019
* [Dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming), wikipedia
