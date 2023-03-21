# Stack in C++

In computer science, a stack is an abstract data type that serves as a collection of elements, with two main operations: `Push`, which adds an element to the collection, and `Pop`, which removes the most recently added element that was not yet removed.

## Stack implementation in C++

C++ provides a standard template library (STL) `stack` class that implements the stack data structure. The `stack` class is defined in the `stack` header file. The `stack` class is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO (last-in first-out) data structure.


```c++
#include <iostream>
#include <stack>

using namespace std;
```

**`push(item)`**: Adds an item to the top of the stack.


```c++
stack<int> st;
st.push(5);
st.push(10);
st.push(7);
```

**`pop()`**: Removes the top item from the stack.


```c++
st.pop();
```

**`top()`**: Returns the top of the stack.


```c++
st.top()
```




    10



**`empty()`**: Returns true if and only if the stack is empty.


```c++
st.empty()
```




    false



**`size()`**: Returns the number of items in the stack.


```c++
st.size()
```




    2



## 🔗 Further Reading

* ▶️ [Stack Introduction](https://youtu.be/L3ud3rXpIxA?list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu), Data structures playlist, WilliamFiset, 2017
* ▶️ [Stack Implementation](https://www.youtube.com/watch?v=RAMqDLI6_1c&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=9&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* ▶️ [Stack Code](https://www.youtube.com/watch?v=oiZssCfk4_U&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=10&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
es the most recently added element that was not yet removed.
