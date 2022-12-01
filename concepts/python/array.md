# Array

From wikipedia

> In computer science, an array is a data structure consisting of a collection of elements (values or variables), each
> identified by at least one array index or key. An array is stored such that the position of each element can be computed
> from its index tuple by a mathematical formula.

## Time Complexity Analysis of Array

| Operation       | Creation | Insertion        | Accessing | Update | Deletion         | Searching |
|-----------------|----------|------------------|-----------|--------|------------------|-----------|
| Time Complexity | $O(1)$   | $O(1)$ or $O(n)$ | $O(1)$    | $O(n)$ | $O(1)$ or $O(n)$ | $O(n)$    |

## Array implementation in Python

```python
# Creation of Array ($O(1)$)
import array as arr

a = arr.array('i', [1, 2, 3])          # [1, 2, 3]
b = arr.array('f', [1.5, 2.6, 3.7])    # [1.5, 2.6, 3.7]

# Accessing elements from the Array ($O(1)$)
a = arr.array('i', [1, 2, 3])          # [1, 2, 3]
print(a[0])                            # 1
print(a[2])                            # 3
print(a[-1])                           # 3

# Adding elements to an Array ($O(1)$ or $O(n)$)
# Adding at specific position
a = arr.array('i', [1, 2, 3])          # [1, 2, 3]
a.insert(1, 4)                         # [1, 4, 2, 3]
# Adding to the end of Array
a.append(5)                            # [1, 4, 2, 3, 5]

# Updating elements in an Array ($O(n)$)
a = arr.array('i', [1, 2, 3])          # [1, 2, 3]
a[2] = 6                               # [1, 2, 6]

# Removing elements from the Array ($O(1)$ or $O(n)$)
a = arr.array('i', [1, 2, 3, 1, 5])    # [1, 2, 3, 1, 5]
# using pop() to remove element at 2nd position
a.pop(2)                               # [1, 2, 1, 5]
# using pop() to remove the last element
a.pop()                                # [1, 2, 1]
# using remove() to remove 1st occurrence of 1
a.remove(1)                            # [2, 1]

# Slicing of an Array ($O(k)$)
a = arr.array('i', [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])  # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# print elements of a range
print(a[4:8])                          # [5, 6, 7, 8]
# print elements from beginning to a pre-defined point
print(a[:5])                           # [1, 2, 3, 4, 5]
# print elements from a pre-defined point to end
print(a[5:])                           # [6, 7, 8, 9, 10]
# print elements from beginning to end
print(a[:])                            # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# print elements from end to beginning
print(a[::-1])                         # [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

# Searching element in an Array ($O(n)$)
a = arr.array('i', [1, 2, 3, 1, 2, 5]) # [1, 2, 3, 1, 2, 5]
# using index() to print index of 1st occurrence of 2
print(a.index(2))                      # [1]
# using index() to print index of 1st occurrence of 1
print(a.index(1))                      # [0]
```

## 🔗 Further Reading

* [Python Arrays](https://www.geeksforgeeks.org/python-arrays/), geeksforgeeks.org
* ▶️ [CS50 2020 - Lecture 2 - Arrays](https://www.youtube.com/watch?v=tI_tIZFyKBw&t=3009s&ab_channel=CS50), CS50
