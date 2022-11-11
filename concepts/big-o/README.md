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

console.log(contains(8, [1, 2, 3, 4, 5, 8, 10]));         // true
                                                          // O(n)

console.log(contains(8, [1, 2, 3, 4, 5, 6, 7, 9, 10]));  // false
                                                         // O(n)

console.log(contains(8, [1, 2, 100, 200, 300, 5000]));   // false
                                                         // O(n)
```

## Quadaric Run Time

```js
const printPairs = (n: number) => {
    for(let i=1; i<=n; i++){ // n times 
        for(let j=i+1; j<=n; j++){ // n - i times
            console.log(`(${i}, ${j})`); // 1 operation
        }
    }
}

printPairs(4); // (1, 2) (1, 3) (1, 4)
               //        (2, 3) (2, 4)
               //                (3, 4)
               // O(n^2)
```

$f(n) = n * (n-1) * 1$

$O(f(n)) = O(n^2)$

Run time for `printPairs()` is $O(n^2)$