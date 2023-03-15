# Array in C++

In computer science, an `array` is a data structure consisting of a collection of elements (values or variables), each identified by at least one array index or key. An array is stored such that the position of each element can be computed from its index tuple by a mathematical formula.

## Time Complexity Analysis of Array

| Operation       | Creation | Insertion        | Accessing | Update | Deletion         | Searching |
|-----------------|----------|------------------|-----------|--------|------------------|-----------|
| Time Complexity | $O(1)$   | $O(1)$ or $O(n)$ | $O(1)$    | $O(n)$ | $O(1)$ or $O(n)$ | $O(n)$    |

## Array implementation in C++

## Basic Operations


```c++
#include <iostream>

using namespace std;
```

**Initialize an array**


```c++
int a[5] = {1, 2, 3, 4, 5};
a
```




    { 1, 2, 3, 4, 5 }



**Access element by index (zero-based)**


```c++
// Access elements in array
cout << "a[0] = " << a[0] << endl;
cout << "a[2] = " << a[2] << endl;
```

    a[0] = 1
    a[2] = 3


**Set value of an element at a given index**


```c++
a[0] = 100;
cout << "a[0] = " << a[0];
```

    a[0] = 100

**Read array from input stream**

Using fixed array 

```cpp
int N;
int numbers[N];
for(int i=0; i<N; i++){
  cin >> numbers[i];
}
```

Using vector

```cpp
#include <vector>

int N;
vector<int> numbers(N);
for(int i=0; i<N; i++){
  cin >> numbers[i];
}
```

## 🔗 Further Reading

* [Arrays](https://cplusplus.com/doc/tutorial/arrays/), cplusplus.com
* ▶️ [Dynamic and Static Arrays](https://www.youtube.com/watch?v=PEnFFiQe1pM&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=4&ab_channel=WilliamFiset), WilliamFiset
* ▶️ [CS50 2020 - Arrays](https://youtu.be/tI_tIZFyKBw?t=3834), CS50

