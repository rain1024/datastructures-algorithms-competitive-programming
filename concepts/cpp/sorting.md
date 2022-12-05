# Sorting

From wikipedia

> Sorting refers to ordering data in an increasing or decreasing manner according to some linear relationship among the data items. Ordering: arranging items in a sequence ordered by some criterion. Categorizing: grouping items with similar properties.


## 💻 Implementation in C++

C++ has built in function `sort` in `algorithm` package.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  // sorting with array
  int a[4] = {2, 4, 1, 3};
  sort(a, a+4);                    // 1 2 3 4
  
  for(auto i: a){
      cout << i << " ";
  }
  cout << endl;
  
  // sorting with vector
  vector<int> b = {2, 4, 1, 3};
  sort(b.begin(), b.end());        // 1 2 3 4
  
  for(auto i: b){
      cout << i << " ";
  }
  cout << endl;
}
```

## 📈 Complexity Analysis


| Operation       | Complexity          |
|-----------------|---------------------|
| Sort            | $O(nlog(n))$        |

## 🔗 Further Reading

* [Sorting](https://en.wikipedia.org/wiki/Sorting), wikipedia
* ▶️ [Sorting in C++](https://www.youtube.com/watch?v=x0uUKWJzSO4&ab_channel=TheCherno), The Cherno, 2018
* ▶️ [Sorting In C++ | Sorting Algorithms - Bubble, Selection, Insertion Sort | C++ Tutorial](https://www.youtube.com/watch?v=SWLLKLov_qs&ab_channel=Simplilearn), Simplilearn, 2021
