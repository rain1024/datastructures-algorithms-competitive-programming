# Big O

From wikipedia

> In computer science, the time complexity is the computational complexity that describes the amount of computer time it takes to run an algorithm. Time complexity is commonly estimated by counting the number of elementary operations performed by the algorithm, supposing that each elementary operation takes a fixed amount of time to perform.

## Constant Run Time

```python
def do_random_stuff():
    foo = True  # 1 operation
    bar = 8 * 3  # 1 operation
    if bar < 20:  # 1 operation
        print("bar is small")  # 1 operation
    for i in range(0, bar):  # 24 operations
        print(i)  # 1 operation


do_random_stuff()  # O(1)
do_random_stuff()  # O(1)
do_random_stuff()  # O(1)
```

f(n) = 1 + 1 + 1 + 1 + 24(1)

O(f(n)) = O(1)

## Linear Run Time

```python
from typing import List


def contains(target: int, nums: List[int]):
    for n in nums:  # n times
        if target == n:  # 1 operation
            return True  # 1 operation
    return False  # 1 operation


print(contains(8, [3])) # False 
                        # O(n)
print(contains(8, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))  # True
                                                     # O(n)
print(contains(8, [1, 2, 100, 200, 300, 5000]))  # False
                                                 # O(n)
```

f(n) = n(1+1) + 1 = 2n

O(f(n)) = O(n)

## Quadratic Run Time

```python
def print_pairs(n: int):
    for i in range(0, n):  # n times
        for j in range(i + 1, n):  # n-i times
            print(i, j)  # 1 operation


print_pairs(4)  # (0, 1) (0, 2) (0, 3)
                #        (1, 2) (1, 3)
                #               (2, 3)
                # O(n^2)
```

f(n) = n * (n-i) * 1

O(f(n)) = O(n^2)

## Logarithm Run Time

```python
# Binary Search - nums is sorted array
import math
from typing import List


def contains(target: int, nums: List[int]):
    low = 0  # 1 operation
    high = len(nums) - 1  # 1 operation

    while low <= high: # log(n) times
        mid = math.floor((low + high) / 2)  # 1 operation
        if nums[mid] == target:  # 1 operation
            return True  # 1 operation
        elif nums[mid] < target:  # 1 operation
            low = mid + 1  # 1 operation
        elif nums[mid] > target:  # 1 operation
            high = mid - 1  # 1 operation
    return False  # 1 operation


print(contains(8, [1, 2, 5, 8, 10]))  # True
                                      # O(log(n))
```

f(n) = 1 + 1 + 1 + 7log(n) = 3 + 7log(n)

O(f(n)) = O(log(n))

## Combined Run Time

```python
from typing import List


def combine(nums: List[int]):
    foo(nums)  # O(1)
    fuu(nums)  # O(log(n))
    bar(nums)  # O(n)
    baz(nums)  # O(n^2)


combine([1, 2, 3, 4, 5, 6]) # O(n^2)
```

f(n) = 1 + log(n) + n + n^2

O(f(n)) = O(n^2)

## 🔗 Further Reading

* [Time complexity](https://en.wikipedia.org/wiki/Time_complexity), wikipedia
* [Space complexity](https://en.wikipedia.org/wiki/Space_complexity), wikipedia
* ▶️ [Asymptotic Notation](https://www.youtube.com/watch?v=iOq5kSKqeR4&ab_channel=CS50), CS50
* ▶️ 2020, [Data Structures in Typescript #3 - Big-O Algorithm Analysis](https://www.youtube.com/watch?v=F2wwpDgoSoc&ab_channel=JeffZhang), Jeff Zhang
