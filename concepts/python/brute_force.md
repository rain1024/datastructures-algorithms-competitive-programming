# Bruteforce

alias: `complete search`, `brute-force search`, `exhaustive search`

From usaco

> In many problems it suffices to check all possible cases in the solution space, whether it be all elements, all pairs of elements, or all subsets, or all permutations. Unsurprisingly, this is called **complete search** (or **brute force**), because it completely searches the entire solution space.

From wikipedia

> In computer science, brute-force search or exhaustive search, also known as generate and test, is a very general problem-solving technique and algorithmic paradigm that consists of systematically enumerating all possible candidates for the solution and checking whether each candidate satisfies the problem's statement.

## 💻 Implementation

### Problems: N Queens

N - Queens problem is to place n - queens in such a manner on an n x n chessboard that no queens attack each other by being in the same row, column or diagonal.

```python
def is_valid_state(state, n):
    # check if it is a valid solution
    return len(state) == n


def get_candidates(state, n):
    # get candidate positions for the next queen in the state
    if not state:
        return range(n)
    
    position = len(state)
    candidates = set(range(n))
    for row, col in enumerate(state):
        candidates.discard(col)
        dist = position - row
        candidates.discard(col + dist)
        candidates.discard(col - dist)
    return candidates


def search(state, solutions, n):
    if is_valid_state(state, n):
        solutions.append(state.copy())

    for candidate in get_candidates(state, n):
        state.append(candidate)
        search(state, solutions, n)
        state.pop()    

if __name__ == '__main__':
    number_of_queens = 4
    solutions = []
    state = []
    search(state, solutions, number_of_queens)
    print(solutions)    # [[1, 3, 0, 2], [2, 0, 3, 1]]
```

## 🔗 Further Reading

* [Python Program for N Queen Problem](https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/), geeksforgeeks 2022
* ▶️ [What is backtracking and how to use it](https://www.youtube.com/watch?v=7TAmGm3aoqA), taptap 2022
* ▶️ [Solve Coding Interview Backtracking Problems](https://www.youtube.com/watch?v=A80YzvNwqXA), FreeCodeCamp, 2021
