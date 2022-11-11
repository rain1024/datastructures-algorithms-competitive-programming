# Array

```js
let nums: number[] = [1, 2, 3, 4];  // [1, 2, 3, 4]

// UPDATE: O(1)
nums = [1, 2, 3, 4]; nums[3] = 10;  // [1, 2, 3, 10, 5]

// INSERT 
//   Inserts new elements at the start of an array
nums = [1, 2, 3, 4]; nums.unshift(100, 200); // [100, 200, 1, 2, 3, 4] 
//   Appends new elements to the end of an arry
nums = [1, 2, 3, 4]; nums.push(100);         // [1, 2, 3, 4, 100]
nums = [1, 2, 3, 4]; nums.push(100, 200);      // [1, 2, 3, 4, 100, 200]
//   Add elements at start index of an array
nums = [1, 2, 3, 4]; nums.splice(1, 0, 100); // [1, 100, 2, 3, 4]
nums = [1, 2, 3, 4]; nums.splice(1, 0, 100, 200); // [1, 100, 200, 2, 3, 4]

// DELETE 
//   Removes the first element from an array 
nums = [1, 2, 3, 4]; nums.shift(); // [2, 3, 4]
//   Removes the last element from an array 
nums = [1, 2, 3, 4]; nums.pop(); // [1, 2, 3]
// Removes n elements at start index of an array 
nums = [1, 2, 3, 4]; nums.splice(1, 1); // [1, 3, 4] 
nums = [1, 2, 3, 4]; nums.splice(1, 2); // [1, 4] 
```