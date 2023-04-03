# Set

From wikipedia

> In computer science, a set is an abstract data type that can store unique values, without any particular order. It is
> a computer implementation of the mathematical concept of a finite set. Unlike most other collection types, rather than
> retrieving a specific element from a set, one typically tests a value for membership in a set.

## 🎨 Design

**Sets Operations**

|              | Definition                                  |
|--------------|---------------------------------------------|
| Adding       | Add element with specified value to the set |
| Union        | Merge items in two sets                     |
| Intersection | Return common elements in two sets          |
| Difference   | Find difference in between sets             |
| Clearance    | Clear all items from the set                |

## Time Complexity Analysis of Sets

| Operation       | Adding | Union    | Intersection | Difference | Clearance |
|-----------------|--------|----------|--------------|------------|-----------|
| Time Complexity | $O(1)$ | $O(n+m)$ | $O(min(n,m)$ | $O(n)$     | $O(n)$    |

## 💻 Implementation in Python

```python
# Init sets
set_1 = {"a", "b", "c"}
set_2 = {"d", "e", "f"}
print(set_1)                        # {'c', 'b', 'a'}
# Add item to set
set_1.add("d")
set_1.add(1)
print(set_1)                        # {1, 'c', 'a', 'd', 'b'}
# Union sets
print(set_1.union(set_2))           # {'e', 1, 'b', 'c', 'd', 'f', 'a'}
# Find sets intersection
print(set_1.intersection(set_2))    # {'d'}
# Find sets difference
print(set_1.difference(set_2))      # {'b', 1, 'a', 'c'}
# Clear set
set_1.clear()
print(set_1)                        # set()
```

## 🔗 Further Reading

* [Sets in Python](https://www.geeksforgeeks.org/sets-in-python/), geeksforgeeks.org, 2022
* [Python Sets](https://docs.python.org/3/tutorial/datastructures.html#sets), geeksforgeeks.org, 2022
* ▶️ [Python Tutorial: Sets - Set Methods and Operations to Solve Common Problems](https://www.youtube.com/watch?v=r3R3h5ly_8g), Corey Schafer, 2018
