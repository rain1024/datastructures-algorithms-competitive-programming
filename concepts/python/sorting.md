# Sorting

From wikipedia

> Sorting refers to ordering data in an increasing or decreasing manner according to some linear relationship among the
> data items. Ordering: arranging items in a sequence ordered by some criterion. Categorizing: grouping items with
> similar properties.

## 🎨 Design

**Sorting Techniques**

|                | Definition                                                                                                                                                           |
|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Bubble Sort    | Repeatedly compares two adjacent elements and swaps them if they are in the wrong order                                                                              |
| Selection Sort | Repeatedly finds the minimum element and sort it in order                                                                                                            |
| Insertion Sort | This sorting algorithm maintains a sub-array that is always sorted. Values from the unsorted part of the array are placed at the correct position in the sorted part |

## 📈 Complexity Analysis

| Sort type      | Complexity |
|----------------|------------|
| Bubble Sort    | $O(n^2)$   |
| Selection Sort | $O(n^2)$   |
| Insertion Sort | $O(n^2)$   |

## 💻 Implementation in Python

Python has built-in function `sorted`.

```python
array = [8, 5, 9, 2, 1]  # [8, 5, 9, 2, 1]
sorted(array)  # [1, 2, 5, 8, 9]

words = ['banana', 'pie', 'Washington', 'book']  # ['banana', 'pie', 'Washington', 'book']
sorted(words, key=len)  # ['pie', 'book', 'banana', 'Washington']
```

Implement Bubble Sort in Python

```python
def bubble_sort(array):
    n = len(array)
    for i in range(n):
        already_sorted = True

        for j in range(n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                already_sorted = False

        if already_sorted:
            break
    return array


array = [8, 5, 9, 2, 1]  # [8, 5, 9, 2, 1]
bubble_sort(array)  # [1, 2, 5, 8, 9]
```

Implement Selection Sort in Python

```python
def selection_sort(array):
    n = len(array)
    for i in range(n):
        min_idx = i

        for j in range(i + 1, n):
            if array[j] < array[min_idx]:
                min_idx = j

        array[i], array[min_idx] = array[min_idx], array[i]
    return array


array = [8, 5, 9, 2, 1]  # [8, 5, 9, 2, 1]
selection_sort(array)  # [1, 2, 5, 8, 9]
```

Implement Insertion Sort in Python

```python
def insertion_sort(array):
    for i in range(1, len(array)):
        key_item = array[i]
        j = i - 1

        while j >= 0 and array[j] > key_item:
            # Shift the value one position to the left
            # and reposition j to point to the next element
            # (from right to left)
            array[j + 1] = array[j]
            j -= 1

        array[j + 1] = key_item
    return array


array = [8, 5, 9, 2, 1]  # [8, 5, 9, 2, 1]
insertion_sort(array)  # [1, 2, 5, 8, 9]
```

## 🔗 Further Reading

* [Sorting](https://en.wikipedia.org/wiki/Sorting), wikipedia
* [Sorting Algorithms in Python](https://realpython.com/sorting-algorithms-python/), realpython
* [How to Use sorted() and sort() in Python](https://realpython.com/python-sort/), realpython
* [Sorting Algorithms in Python](https://www.geeksforgeeks.org/sorting-algorithms-in-python/), geeksforgeeks 2022
* ▶️ [Python Sorting Algorithms](https://www.youtube.com/playlist?list=PLj8W7XIvO93rJHSYzkk7CgfiLQRUEC2Sq), Joe James, 2015
