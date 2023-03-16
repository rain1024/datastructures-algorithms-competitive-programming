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

## 🔗 Further Reading

* [Linked Lists in Python](https://realpython.com/linked-lists-python/), realpython.com
* ▶️ [Linked Lists Introduction](https://www.youtube.com/watch?v=-Yn5DU0_-lw&t=7s&ab_channel=WilliamFiset), WilliamFiset, 2017
* ▶️ [CS50 2018 - Lecture 4 - Linked Lists](https://www.youtube.com/watch?v=wh4TS7RJDTA), CS50, 2018