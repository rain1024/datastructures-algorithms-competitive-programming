# Two Pointers

*See implementation in*
[C++](/concepts/cpp/two-pointers/README.md),
Java,
Python,
Typescript

The "Two Pointers" technique is a commonly used approach for solving algorithmic problems. This technique involves using two pointers that move through an array or string in a synchronized manner to solve the problem at hand.

## Two Variations of the Two Pointers Technique

> In the classic implementation of this technique, one pointer, known as the slow-runner, advances through the array or string one element at a time, while the other pointer, the fast-runner, moves ahead more quickly, checking for certain conditions or performing other operations.

For example, if the problem is to *remove duplicates from a sorted array*, the slow-runner would examine each element in the array, while the fast-runner would move ahead and skip over any duplicates that it encountered.

> Another variant of the Two Pointers technique involves starting with one pointer at the beginning of a string or array, and the other pointer at the end. The pointers move towards each other, swapping elements as they go, until they meet in the middle.

This variant is often used for problems that involve *reversing or rearranging elements in a string or array*.

## 🔗 Further Reading 

* [Two Pointers Technique](https://www.geeksforgeeks.org/two-pointers-technique/), geeksforgeeks
* [Two Pointers Technique](https://leetcode.com/articles/two-pointer-technique/), leetcode
* ▶️ [How to Use the Two Pointer Technique](https://www.youtube.com/watch?v=-gjxg6Pln50&ab_channel=TeamAlgoDaily), 
Team AlgoDaily
* ▶️ [LeetCode Day 8 - Middle of a Linked List (Two Pointers)](https://www.youtube.com/watch?v=wq4OZZ3YLj4&ab_channel=Errichto), Errichto