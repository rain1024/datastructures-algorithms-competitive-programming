# Queue

From wikipedia

> In computer science, a queue is a collection of entities that are maintained in a sequence and can be modified by the addition of entities at one end of the sequence and the removal of entities from the other end of the sequence.



## 💻 Queue Implementation in C++


Here are the implementation of [awesome type] in `Awesome Language` from scratch.

ℹ️ C++ has standard built-in [queue](https://en.cppreference.com/w/cpp/container/queue) in `std` library.


```cpp
#include <iostream>
#include <queue>
  
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(4);
    
    while(!q.empty()){
        int value = q.front();
        cout << value << endl;
        q.pop();
    }
}
```

Output

```
1
3
4
```

## 📈 Complexity Analysis

| Operation       | Complexity          |
|-----------------|---------------------|
| push            | $O(1)$              |
| empty           | $O(1)$              |
| front           | $O(1)$              |

## 🔗 Further Reading

* ▶️ [Queue Introduction](https://www.youtube.com/watch?v=KxzhEQ-zpDc&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=11&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* ▶️ [Queue Implementation](https://www.youtube.com/watch?v=EoisnPvUkOA&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=12&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* ▶️ [Queue Code](https://www.youtube.com/wat
* ▶️ [Queue | C++ STL (Standard Template Library) | std::queue](https://www.youtube.com/watch?v=M73wcfBwX7Y&ab_channel=KnowledgeCenter), Knowledge Center, 2020
