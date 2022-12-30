# Hash Table

From wikipedia

> In computing, a hash table, also known as hash map, is a data structure that  implements an associative array or dictionary. It is an abstract data type that maps keys to values. A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.

## Time Complexity Analysis of Hash Table

| Operation       | Insertion | Deletion | Searching |
|-----------------|-----------|----------|-----------|
| Time Complexity |   $O(1)$  (worst case: $O(n)$) |  $O(1)$ (worst case: $O(n)$) |  $O(1)$ (worst case: $O(n)$)  |

## 💻 Implementation in Python

```python
BLANK = object()

class HashTable:
    def __init__(self, capacity) -> None:
        self.values = capacity * [BLANK]

    def __len__(self):
        return len(self.values)
    
    def __setitem__(self, key, value):
        self.values[self._index(key)] = value

    def __getitem__(self, key):
        value = self.values[self._index(key)]
        if value is BLANK:
            raise KeyError(key)
        return value

    def __contains__(self, key, default=None):
        try:
            self[key]
        except KeyError:
            return False
        else:
            return True

    def get(self, key, default=None):
        try:
            return self[key]
        except KeyError:
            return default

    def __delitem__(self, key):
        if key in self:
            self[key] = BLANK
        else:
            raise KeyError(key)

    def _index(self, key):
        return hash(key) % len(self)

hash_table = HashTable(capacity=100)
hash_table["key1"] = 1
print("key1" in hash_table)          # True
print(hash_table["key1"])            # 1
hash_table["key1"] = 2
print(hash_table["key1"])            # 2
del hash_table["key1"]
print("key1" in hash_table)          # False
```

## 🔗 Further Reading

* [Build a Hash Table in Python With TDD](https://realpython.com/python-hash-table/), realpython.com
* [Python Hash Tables: Understanding Dictionaries](https://thepythoncorner.com/posts/2020-08-21-hash-tables-understanding-dictionaries/), thepythoncorner.com, 2020
* ▶️ [Hash Tables and Hash Functions](https://www.youtube.com/watch?v=KyUTuwz_b7Q), 
Computer Science, 2017
