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