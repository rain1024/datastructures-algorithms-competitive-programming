# Array

From wikipedia

> In computer science, an array is a data structure consisting of a collection of elements (values or variables), each identified by at least one array index or key. An array is stored such that the position of each element can be computed from its index tuple by a mathematical formula.

## Time Complexity Analysis of Array

| Operation       | Access  | Insertion | Deletion   | Search   |
|-----------------|---------|-----------|------------|----------|
| Time Complexity | $O(1)$  | $O(n)$    | $O(n)$     | $O(n)$   |

## Array implementation in Typescript

```js
// INITIALIZE
let nums: number[] = [1, 2, 3, 4];                // [1, 2, 3, 4]

// ACCESS: O(1)
nums = [1, 2, 3, 4]; nums[3]                      // 3

// UPDATE: O(1)
nums = [1, 2, 3, 4]; nums[3] = 10;                // [1, 2, 3, 10, 5]

// INSERTION: O(n)
//   Inserts new elements at the start of an array
nums = [1, 2, 3, 4]; nums.unshift(100, 200);      // [100, 200, 1, 2, 3, 4] 
//   Appends new elements to the end of an arry
nums = [1, 2, 3, 4]; nums.push(100);              // [1, 2, 3, 4, 100]
nums = [1, 2, 3, 4]; nums.push(100, 200);         // [1, 2, 3, 4, 100, 200]
//   Add elements at start index of an array
nums = [1, 2, 3, 4]; nums.splice(1, 0, 100);      // [1, 100, 2, 3, 4]
nums = [1, 2, 3, 4]; nums.splice(1, 0, 100, 200); // [1, 100, 200, 2, 3, 4]

// DELETION: O(n)
//   Removes the first element from an array 
nums = [1, 2, 3, 4]; nums.shift();                // [2, 3, 4]
//   Removes the last element from an array 
nums = [1, 2, 3, 4]; nums.pop();                  // [1, 2, 3]
// Removes n elements at start index of an array 
nums = [1, 2, 3, 4]; nums.splice(1, 1);           // [1, 3, 4] 
nums = [1, 2, 3, 4]; nums.splice(1, 2);           // [1, 4] 

// SEARCH: O(n)
let nums: number[] = [1, 2, 3, 4];

nums.indexOf(3) != -1        // true
nums.indexOf(5) != -1        // false
nums.some((e) => e == 3)     // true

nums.find((e) => e == 3)     // 3
nums.find((e) => e == 5)     // undefined
nums.filter((e) => e == 3)   // [3]
```

## 🔗 Further Reading

* [Array](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array), developer.mozilla.org
* 2022, [Data Structures in Typescript #4 - Static and Dynamic Arrays](https://www.youtube.com/watch?v=SycPba7pYR0&list=PLn4fTSbSpY5cL4_0MP83wq5khbmG3IKKd&index=5&ab_channel=JeffZhang), Jeff Zhang
