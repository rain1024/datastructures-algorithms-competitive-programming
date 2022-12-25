# Linked List

From wikipedia

> In computer science, a linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.

## Time Complexity Analysis of Linked List

INSERTION

| Operation       | Singly Linked List  | Double Linked List  |
|-----------------|---------------------|---------------------|
| Insert head     | $O(1)$              | $O(1)$              |
| Insert middle   | $O(n)$              | $O(n)$              |
| Insert tail     | $O(n)$              | $O(1)$              |

DELETION

| Operation       | Singly Linked List  | Double Linked List  |
|-----------------|---------------------|---------------------|
| Delete head     | $O(1)$              | $O(1)$              |
| Delete middle   | $O(n)$              | $O(n)$              |
| Delete tail     | $O(n)$              | $O(1)$              |

SEARCHING

| Singly Linked List  | Double Linked List  |
|---------------------|---------------------|
| $O(n)$              | $O(n)$              |

## Singly Linked List Implementation in Python

```python
# Implement using collections.deque
from collections import deque


linked_list = deque(['a','b','c','d','e'])  # a -> b -> c -> d -> e -> None
linked_list.append('f')                     # a -> b -> c -> d -> e -> f -> None
linked_list.pop()                           # a -> b -> c -> d -> e -> None
linked_list.appendleft('z')                 # z -> a -> b -> c -> d -> e -> None
linked_list.popleft()                       # a -> b -> c -> d -> e -> None

# Implement from scratch
class LinkedList:
    def __init__(self, nodes=None):
        self.head = None
        if nodes is not None:
            node = Node(data=nodes.pop(0))
            self.head = node
            for item in nodes:
                node.next = Node(data=item)
                node = node.next

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next

    def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)

    def add_first(self, node):
        node.next = self.head
        self.head = node

    def add_last(self, node):
        if self.head is None:
            self.head = node
            return
        for current_node in self:
            pass
        current_node.next = node

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return self.data

linked_list = LinkedList(['b','c','d','e']) # b -> c -> d -> e -> None
linked_list.add_first(Node("a"))            # a -> b -> c -> d -> e -> None
linked_list.add_last(Node("f"))             # a -> b -> c -> d -> e -> f -> None
```
## 🔗 Further Reading

* [Linked Lists in Python](https://realpython.com/linked-lists-python/), realpython.com
* ▶️ [Linked Lists Introduction](https://www.youtube.com/watch?v=-Yn5DU0_-lw&t=7s&ab_channel=WilliamFiset), WilliamFiset, 2017
* ▶️ [CS50 2018 - Lecture 4 - Linked Lists](https://www.youtube.com/watch?v=wh4TS7RJDTA), CS50, 2018
