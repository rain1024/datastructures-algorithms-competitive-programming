# Hash Table

From wikipedia

> In computing, a hash table, also known as hash map, is a data structure that implements an associative array or dictionary. It is an abstract data type that maps keys to values. A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.

## 💻 Implementation in C++

ℹ️ C++ has standard built-in object `std::map` and `std::unordered_map` 


```cpp
#include <map>
#include <iostream>

using namespace std;

int main(){
    map<int, int> m;
    m[0] = 1;                                // INSERTION 
    if(m.find(0) != m.end()){                // SEARCHING
        cout << "m has item 0: " << endl;
        cout << "m[0] = " << m[0] << endl;
    }
    if(m.find(2) == m.end()){
        cout << "m hasn't item 2" << endl;
    }
    
    m.erase(0);                              // DELETION
    
    return 0;
}
```

## 📈 Complexity Analysis


| Operation       | map               | unordered_map                 |
|-----------------|-------------------|-------------------------------|
| Search          | $O(log(n))$       | $O(1)$ (worst), $O(n)$ (best) |
| Insertion       | $O(log(n))$       | $O(log(n))$                   |
| Deleteion       | $O(log(n))$       | $O(log(n))$                   |

## 🔗 Further Reading

* [Hash table](https://en.wikipedia.org/wiki/Hash_table), wikipedia
* [map vs unordered_map in C++](https://www.geeksforgeeks.org/map-vs-unordered_map-c/), Geeksforgeeks, 2022
* ▶️ [Maps in C++ (std::map and std::unordered_map)](https://www.youtube.com/watch?v=KiB0vRi2wlc&ab_channel=TheCherno), 
The Cherno, 2022
* ▶️ [Data Structures: Hash Tables](https://www.youtube.com/watch?v=shs0KM3wKv8&t=10s&ab_channel=HackerRank), HackerRank, 2016