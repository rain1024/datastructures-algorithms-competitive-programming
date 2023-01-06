# Set

> A set is an abstract data type that is used to store a collection of elements. It is a container that stores a collection of unique elements in a specific order. The elements in a set are usually sorted according to their keys, which are used to identify the elements in the set.

![](../abstract/data-structures/set.png)

Sets are typically implemented using balanced binary search trees, such as red-black trees or AVL trees. These data structures allow for fast insertions, deletions, and searches in the set.

In addition to the basic operations of inserting, deleting, and searching for elements, sets also support a number of other operations, such as union, intersection, and difference.

![](../abstract/data-structures/set_2.png)

Sets are often used to implement logic operations in computer science, such as union-find algorithms, and are also useful for efficiently storing and manipulating large collections of data.

## 💻 Set Implementation in C++

In C++, the `std::set` is a container that stores a collection of unique elements in a specific order. The elements in a set are sorted according to their keys, which are stored in the set.

Here is an example of how to use `std::set` in C++:

```cpp
#include <iostream>
#include <set>

using namespace std;
int main() {
  set<int> s;

  // Insert elements into the set
  s.insert(2);
  s.insert(3);
  s.insert(5);
  s.insert(2); // This element is not inserted, since 2 is already in the set

  cout << "Print the elements of the set" << endl;
  for (int x : s) {
    cout << x << endl;
  }

  return 0;
}
```

Output:

```
Print the elements of the set
2
3
5
```