# Queue

From wikipedia

> In computer science, a queue is a collection of entities that are maintained in a sequence and can be modified by the
> addition of entities at one end of the sequence and the removal of entities from the other end of the sequence.

## 🎨 Design

**Queue Operations**

|         | Definition                                                  |
|---------|-------------------------------------------------------------|
| Enqueue | Add element to the queue                                    |
| Dequeue | Remove element from the queue                               |
| Peek    | Get the value of the front of the queue without removing it |

## Time Complexity Analysis of Queue

| Operation       | Enqueueing | Dequeuing | Peeking  |
|-----------------|------------|-----------|----------|
| Time Complexity | $O(1)$     | $O(1)$    | $O(1)$   |

## 💻 Implementation in Python

```python
# Queue implementation using collections.deque
from collections import deque

# Initializing a queue
q = deque()

# Adding elements to a queue
q.append('a')
q.append('b')
q.append('c')
print(q)            # deque(['a', 'b', 'c'])

# Peek front element of queue
print(q[0])         # a

# Removing elements from a queue
print(q.popleft())  # a
print(q.popleft())  # b
print(q.popleft())  # c
print(q)            # deque([])
```

```python
# Queue implementation using queue.Queue
from queue import Queue

# Initializing a queue
q = Queue(maxsize=3)

# Adding of element to queue
q.put('a')
q.put('b')
q.put('c')
print(q.qsize())   # 3

# Peek front element of queue
print(q.queue[0])  # a

# Removing elements from a queue
print(q.get())     # a
print(q.get())     # b
print(q.get())     # c
print(q.qsize())   # 0
```

## 🔗 Further Reading

* [Queue in Python](https://www.geeksforgeeks.org/queue-in-python/), geeksforgeeks.org, 2022
* [Queue in Python](https://realpython.com/queue-in-python/), realpython.com, 2022
* ▶️ [Queue Introduction](https://www.youtube.com/watch?v=KxzhEQ-zpDc&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=11&ab_channel=WilliamFiset),
Data structures playlist, WilliamFiset, 2017
