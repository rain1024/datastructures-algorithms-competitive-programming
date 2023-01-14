# Big O

> In computer science, the time complexity is the computational complexity that describes the amount of computer time it takes to run an algorithm. Time complexity is commonly estimated by counting the number of elementary operations performed by the algorithm, supposing that each elementary operation takes a fixed amount of time to perform.

## Constant Run Time

```cpp
#include <iostream>

using namespace std;

void doRandomStuff(){
    bool foo = true;    // 1 operation
    int bar = 8 * 3;    // 1 operation
    if(bar < 20){
        cout << "bar is small" << endl;    // 1 opeartion
    }
    for(int i=0; i<bar; i++){
        // 24 operations 
        cout << i << endl;
    }
}
int main() {
    doRandomStuff();    // O(1)
    doRandomStuff();    // O(1)
    doRandomStuff();    // O(1)
}
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

## Logarithm Run Time


```js
// binaray search - nums is sorted array
const contains = (target:number, nums: number[]) => {
    let lo = 0; // 1 operation 
    let hi = nums.length - 1; // 1 operation 

    while(lo <= hi){ // log(n) times
        let mid = Math.floor((lo + hi) / 2);
        // console.log(mid);
        if(target == nums[mid]){ // 1 operation 
            return true;
        } else if (target > nums[mid]) { // 1 operation 
            lo = mid + 1;
        } else { // 1 operation
            hi = mid - 1;
        }
    }
    return false;
}

console.log(contains(8, [1, 2, 5, 8, 10])); // true
                                            // O(log(n))

console.log(contains(8, [1, 2, 5, 9, 10])); // false
                                            // O(log(n))

console.log(contains(8, [8, 9, 10, 11]));   // true
                                            // O(log(n))

console.log(contains(8, [4, 5, 6, 7, 8]));  // true
                                            // O(log(n))
```

$f(n) = 1 + 1 + 1 + 3log(n)= 3 + 3log(n)$

$O(f(n)) = O(log(n))$

Run time for `contains` is $O(log(n))$

## Combined Run Time

```js
const combine = (nums: number[]) => {
    foo(nums);  // O(1)
    fuu(nums);  // O(log(n))
    bar(nums);  // O(n)
    baz(nums);  // O(n^2)
}

combine([1, 2, 3, 4, 5, 6]); // O(n^2)
```

$f(n) = 1 + log(n) + n + n^2$

$O(f(n)) = O(n^2)$

Runtime for `combine()` is $O(n^2)$

## 🔗 Further Reading

* [Time complexity](https://en.wikipedia.org/wiki/Time_complexity), wikipedia
* [Space complexity](https://en.wikipedia.org/wiki/Space_complexity), wikipedia
* ▶️ [Asymptotic Notation](https://www.youtube.com/watch?v=iOq5kSKqeR4&ab_channel=CS50), CS50
* ▶️ 2020, [Data Structures in Typescript #3 - Big-O Algorithm Analysis](https://www.youtube.com/watch?v=F2wwpDgoSoc&ab_channel=JeffZhang), Jeff Zhang
