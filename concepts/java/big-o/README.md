# Big-O in Java

## Constant Run Time

$O(1)$: Constant time, the time complexity of the algorithm is independent of the size of the input. Examples include accessing an array element by index or pushing/popping from a stack.


```Java
void doRandomStuff(){
  boolean foo = true;  // 1 operation
  int bar = 8 * 3;
  
  if(bar < 20){
    System.out.println("bar is small");
  }

  for(int i=0; i<bar; i++){
    System.out.println(i);
  }
}

doRandomStuff() // O(1)
```

    0
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    11
    12
    13
    14
    15
    16
    17
    18
    19
    20
    21
    22
    23


## Linear Run Time 

$O(n)$: Linear time, the time complexity of the algorithm increases linearly with the size of the input. Examples include linear search, traversing a list, or calculating the sum of an array.


```Java
boolean isContains(int target, int[] arr){
  for(int i=0; i<arr.length; i++){
    if(arr[i] == target){
      return true;
    }
  }
  return false;
}
```




    true




```Java
int[] arr;

arr = new int[]{1, 2, 3, 4, 5, 8, 10}; 
System.out.println(isContains(8, arr)); // O(n)

arr = new int[]{1, 2, 3, 4, 5, 6, 7, 9, 10}; 
System.out.println(isContains(8, arr)); // O(n)

arr = new int[]{1, 2, 100, 200, 300, 500}; 
System.out.println(isContains(8, arr)); // O(n)

```

    true
    false
    false


Run time for `isContains` function is $O(n)$

## Quadaric Run Time

$O(n^2)$: Quadratic time, the time complexity of the algorithm increases as the square of the size of the input. Examples include bubble sort and selection sort.


```Java
void printPairs(int n){
  for(int i=1; i<=n; i++){
    for(int j=i+1; j<=n; j++){
      System.out.print("(" + i + ", " + j + ") ");
    }
    System.out.println();
  }
}

printPairs(4)
```

    (1, 2) (1, 3) (1, 4) 
    (2, 3) (2, 4) 
    (3, 4) 
    


$f(n) = n * (n-1) * 1$

$O(f(n)) = O(n^2)$

Run time for `printPairs` is $O(n^2)$

## Logarithm Run Time

$O(log n)$: Logirthm time describes an algorithm that performs a logarithmic number of operations, where the log is typically base 2. Examples include binary search and finding the height of a balanced binary tree.


```Java
boolean isContains(int target, int[] numbers){
  /* arr is sorted array */
  int lo = 0;
  int hi = numbers.length - 1;
  int mid;
  while(lo <= hi){
    mid = (lo + hi) / 2;
    if(numbers[mid] == target){
      return true;
    } else if(numbers[mid] < target){
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return false;
}

int[] numbers;

numbers = new int[]{1, 2, 3, 4, 5, 8, 10};
System.out.println(isContains(8, numbers)); // O(log n)

numbers = new int[]{1, 2, 3, 4, 5, 9, 10};
System.out.println(isContains(8, numbers)); // O(log n)

numbers = new int[]{8, 9, 10, 11, 12};
System.out.println(isContains(8, numbers));  // O(log n)
```

    true
    false
    true


$f(n) = 1 + 1 + 1 + 3log(n)= 3 + 3log(n)$

$O(f(n)) = O(log(n))$

Run time for `isContains` (with numbers is sorted array) is $O(log(n))$

## Combined Run Time

```java
void combine = (int[] nums) => {
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

* [Time complexity](https://en.wikipedia.org/wiki/Time_complexity), wikipedia
* [Space complexity](https://en.wikipedia.org/wiki/Space_complexity), wikipedia
* ▶️ [Asymptotic Notation](https://www.youtube.com/watch?v=iOq5kSKqeR4&ab_channel=CS50), CS50
* ▶️ 2020, [Data Structures in Typescript #3 - Big-O Algorithm Analysis](https://www.youtube.com/watch?v=F2wwpDgoSoc&ab_channel=JeffZhang), Jeff Zhang
