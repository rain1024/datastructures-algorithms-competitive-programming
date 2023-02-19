# Searching

From wikipedia

> In computer science, a search algorithm is an algorithm designed to solve a search problem. Search algorithms work to
> retrieve information stored within particular data structure, or calculated in the search space of a problem domain,
> with either discrete or continuous values.

## 🎨 Design

**Searching Techniques**

|               | Definition                                                                                                                                                                                                                                                                                                                   |
|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Binary Search | Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. |

## 📈 Complexity Analysis

| Sort type     | Complexity  |
|---------------|-------------|
| Binary Search | $O(log(n))$ |

## 💻 Implementation in Python

Implement Binary Search in Python

```python
def binary_search(list_to_search, item):
    low = 0
    high = len(list_to_search) - 1

    while low <= high:
        mid = (low + high) // 2
        mid_item = list_to_search[mid]
        if mid_item == item:
            return mid
        if mid_item > item:
            high = mid - 1
        else:
            low = mid + 1
    return None


sample_list = [1, 2, 4, 6, 7, 10, 100]
print(binary_search(sample_list, 4))   # 2
print(binary_search(sample_list, 10))  # 5
print(binary_search(sample_list, 30))  # None
```

## 🔗 Further Reading

* [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm), wikipedia
* [Python Program for Binary Search](https://www.geeksforgeeks.org/python-program-for-binary-search/), geeksforgeeks 2022
* ▶️ [Binary Search Algorithm in 100 Seconds](https://www.youtube.com/watch?v=MFhxShGxHWc), Fireship 2022
