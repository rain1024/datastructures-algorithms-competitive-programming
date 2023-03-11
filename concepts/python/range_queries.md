# Range Queries

**Prefix sum**

From wikipedia

> In computer science, the prefix sum, cumulative sum, inclusive scan, or simply scan of a sequence of numbers $x_0, x_1, x_2, ...$ is a second sequence of numbers $y_0, y_1, y_2, ...$, the sums of prefixes (running totals) of the input sequence: $y_0 = x_0, y_1 = x_0 + x_1, y_2 = x_0 + x_1+ x_2, ...$

## 🎨 Design

**Methods**

|                     | Definition                         |
|---------------------|------------------------------------|
| Query(left, right)  | Sum of range from left to right    |


## 📈 Complexity Analysis


| Operation       | Complexity          |
|-----------------|---------------------|
| Queries         | $O(N+Q)$            |


## 💻 Implementation

ℹ️ Here is the implementation of the prefix sum in Python

```python
input = [1, 3, 4, 5, 6 , 1, 4]
print(input)

prefix_sum = []
prefix_sum.append(input[0])
for i in range(1, len(input)):
    prefix_sum.append(prefix_sum[i-1] + input[i])
print(prefix_sum)  # [1, 4, 8, 13, 19, 20, 24]

queries = [(0,4), (0,2), (2,4), (3,5)]
for query in queries:
    left, right = query[0], query[1]
    if left == 0:
        result = prefix_sum[right]
    else:
        result = prefix_sum[right] - prefix_sum[left-1]
    print(f'Q({left},{right})={result}') 
    # Q(0,4)=19
    # Q(0,2)=8
    # Q(2,4)=15
    # Q(3,5)=12
```


## 🔗 Further Reading

* ▶️ [Range Query Problems and Data Structures](https://www.youtube.com/watch?v=8wJzUFZOqK4), Kartik Arora 2021
* ▶️ [Prefix Sum Algorithm](https://www.youtube.com/watch?v=pVS3yhlzrlQ), JavaAID 2019
* [Prefix sum](https://en.wikipedia.org/wiki/Prefix_sum), wikipedia
* [Python | Prefix sum list](https://www.geeksforgeeks.org/python-prefix-sum-list/), geeksforgeeks 2023