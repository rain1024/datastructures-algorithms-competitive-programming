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

isContains(8, [1, 2, 3, 4, 5, 6, 8])
```


    |   isContains(8, [1, 2, 3, 4, 5, 6, 8])

    illegal start of expression

    

    |   isContains(8, [1, 2, 3, 4, 5, 6, 8])

    ']' expected

    



```Java

```
