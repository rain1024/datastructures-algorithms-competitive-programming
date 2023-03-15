# Big O

*See implementation in* [C++](../cpp/big-o.md), [Java](../java/big-o/README.md), [Python](../python/big-o.md), [Typescript](../typescript/big-o.md)

> In computer science, the time complexity is the computational complexity that describes the amount of computer time it takes to run an algorithm. Time complexity is commonly estimated by counting the number of elementary operations performed by the algorithm, supposing that each elementary operation takes a fixed amount of time to perform.

<h5 align="center">
<img src="/concepts/general/basic-concepts/big-o-notation.png" width="400px"/>
</h5>

## Constant Run Time

$O(1)$: Constant time, the time complexity of the algorithm is independent of the size of the input. Examples include accessing an element in an array by its index or performing a single operation on a single value.

```cpp
def do_random_stuff():
    foo = True  # 1 operation
    bar = 8 * 3  # 1 operation
    if bar < 20:  # 1 operation
        print("bar is small")  # 1 operation
    for i in range(0, bar):  # 24 operations
        print(i)  # 1 operation


do_random_stuff()  # O(1)
do_random_stuff()  # O(1)
do_random_stuff()  # O(1)
```

Run time for `doRandomStuff` is $O(1)$

## Linear Run Time

$O(n)$: Linear time, the time complexity of the algorithm increases linearly with the size of the input. Examples include linear search, traversing a list, or calculating the sum of an array.

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isContains(int target, vector<int> numbers){
    for(int number: numbers){
        if(target == number){
            return true;
        }
    }
    return false;
}

int main() {
    cout << isContains(8, {1, 2, 3, 4, 5, 8, 10}) << endl;          // 1
                                                                    // O(n)

    cout << isContains(8, {1, 2, 3, 4, 5, 6, 7, 9, 10}) << endl;    // 0
                                                                    // O(n)

    cout << isContains(8, {1, 2, 100, 200, 300, 500}) << endl;      // 0
                                                                    // O(n)
}
```

Run time for `isContains` function is $O(n)$

## Quadaric Run Time

$O(n^2)$: Quadratic time, the time complexity of the algorithm increases as the square of the size of the input. Examples include bubble sort and selection sort.

```cpp
#include <iostream>
#include <vector>

using namespace std;

void printPairs(int n){
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            cout << "(" << i << ", " << j << ") ";
        }
        cout << endl;
    }
}

int main() {
    printPairs(4);
}
```

Output

```
(1, 2) (1, 3) (1, 4) 
(2, 3) (2, 4) 
(3, 4) 
```

$f(n) = n * (n-1) * 1$

$O(f(n)) = O(n^2)$

Run time for `printPairs` is $O(n^2)$

## Logarithm Run Time

$O(log n)$: Logirthm time describes an algorithm that performs a logarithmic number of operations, where the log is typically base 2. Examples include binary search and finding the height of a balanced binary tree.

```cpp
// binaray search - nums is sorted array
#include <iostream>
#include <vector>
using namespace std;

bool isContains(int target, vector<int> numbers){
    int lo = 0;                 // 1 operation 
    int hi = numbers.size();    // 1 operation
    int mid;
    while(lo <= hi){  // log(n) times
        mid = (lo + hi) / 2;
        if(numbers[mid] == target){  // 1 operation
            return true;
        }
        else if(target > numbers[mid]){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return false;
}

int main() {
    cout << isContains(8, {1, 2, 3, 4, 5, 8, 10}) << endl;    // true
                                                              // O(log(n))
    cout << isContains(8, {1, 2, 3, 4, 5, 9, 10}) << endl;    // false
                                                              // O(log(n))    
    cout << isContains(8, {4, 5, 6, 7, 8}) << endl;           // true
                                                              // O(log(n))
    cout << isContains(8, {8, 9, 10, 11, 12}) << endl;        // true
                                                              // O(log(n))
}
```

$f(n) = 1 + 1 + 1 + 3log(n)= 3 + 3log(n)$

$O(f(n)) = O(log(n))$

Run time for `isContains` is $O(log(n))$

## Combined Run Time

```cpp
void combine = (vector<int> nums) => {
    foo(nums);  // O(1)
    fuu(nums);  // O(log(n))
    bar(nums);  // O(n)
    baz(nums);  // O(n^2)
}

combine({1, 2, 3, 4, 5, 6}); // O(n^2)
```

$f(n) = 1 + log(n) + n + n^2$

$O(f(n)) = O(n^2)$

Runtime for `combine()` is $O(n^2)$

## 🔗 Further Reading

* [bigocheatsheet.com](https://www.bigocheatsheet.com/)
* [Time complexity](https://en.wikipedia.org/wiki/Time_complexity), wikipedia
* [Space complexity](https://en.wikipedia.org/wiki/Space_complexity), wikipedia
* ▶️ [Asymptotic Notation](https://www.youtube.com/watch?v=iOq5kSKqeR4&ab_channel=CS50), CS50
* ▶️ 2020, [Data Structures in Typescript #3 - Big-O Algorithm Analysis](https://www.youtube.com/watch?v=F2wwpDgoSoc&ab_channel=JeffZhang), Jeff Zhang
