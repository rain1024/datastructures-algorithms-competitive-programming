# Big O

## Constant Run Time

```js
const doRandomStuff = () => {
    const foo = true; // 1 operation
    const bar = 8 * 3; // 1 operation 
    if (bar < 20){
        console.log("bar is small"); // 1 operation
    }
    for(let i=0; i<bar; i++){
        // 24 operations
        console.log(i); // 1 operation
    }
}

doRandomStuff(); // O(1)
doRandomStuff(); // O(1)
doRandomStuff(); // O(1)
```

## Linear Run Time

```js
const contains = (target: number, nums: number[]) => {
    for(let num of nums){ // n times
        if(target == num){
            return true;
        }
    }
    return false;
}

console.log(contains(8, [1, 2, 3, 4, 5, 8, 10])); // O(n)
// true
console.log(contains(8, [1, 2, 3, 4, 5, 6, 7, 9, 10])); // O(n)
// false
console.log(contains(8, [1, 2, 100, 200, 300, 5000])); // O(n)
// false
```