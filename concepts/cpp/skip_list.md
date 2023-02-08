# Skip list

From wikipedia

> A skip list (or skiplist) is a probabilistic data structure that allows $O(log\ n)$
average complexity for search as well as $O(log\ n)$ average complexity for insertion 
within an ordered sequence of n elements.

## Time complexity of Skip list

|            | Time complexity         |
|------------|-------------------------|
| Insertion  | $O(log\ n)$              |
| Deletion   | $O(log\ n)$              |
| Search     | $O(log\ n)$              |
| Access     | $O(n)$                  |

## 💻 Implementation

ℹ️ Here is the implementation of the Skip list in C++

```cpp
#include <climits>
#include <iostream>

using namespace std;

struct Node {
  int key;
  int level;
  Node** forwards;
  // constructor
  Node(int key, int level) {
    this->key = key;
    this->level = level;
    forwards = new Node*[level + 1];
    for (int i = 0; i <= level; i++) {
      forwards[i] = NULL;
    }
  }
};

class Skiplist {
 public:
  Skiplist(int max_level);
  ~Skiplist();
  void insert(int key);
  bool search(int key);
  void remove(int key);
  void show();

 private:
  Node* head;
  int MAX_LEVEL;
};

Skiplist::Skiplist(int max_level = 4): MAX_LEVEL(max_level) {
  head = new Node(INT_MIN, MAX_LEVEL);
  srand(time(NULL));
}

Skiplist::~Skiplist() { delete head; }

void Skiplist::insert(int key) {
  int level = 0;
  while (rand() % 2 && level < MAX_LEVEL) {
    level++;
  }
  Node* newNode = new Node(key, level);

  Node* current = head;
  Node** update = new Node*[level + 1];
  for (int i = 0; i <= level; i++) {
    update[i] = NULL;
  }

  for (int i = level; i >= 0; i--) {
    while (current->forwards[i] != NULL && current->forwards[i]->key < key) {
      current = current->forwards[i];
    }
    update[i] = current;
  }

  for (int i = 0; i <= level; i++) {
    newNode->forwards[i] = update[i]->forwards[i];
    update[i]->forwards[i] = newNode;
  }
}

bool Skiplist::search(int key) {
  Node* current = head;
  for (int i = MAX_LEVEL; i >= 0; i--) {
    while (current->forwards[i] != NULL && current->forwards[i]->key < key) {
      current = current->forwards[i];
    }
  }
  if (current->forwards[0] != NULL && current->forwards[0]->key == key) {
    return true;
  }
  return false;
}

void Skiplist::remove(int key) {
  Node* current = head;
  Node** update = new Node*[MAX_LEVEL + 1];
  for (int i = 0; i <= MAX_LEVEL; i++) {
    update[i] = NULL;
  }

  for (int i = MAX_LEVEL; i >= 0; i--) {
    while (current->forwards[i] != NULL && current->forwards[i]->key < key) {
      current = current->forwards[i];
    }
    update[i] = current;
  }

  current = current->forwards[0];

  if (current && current->key == key) {
    for (int i = 0; i <= MAX_LEVEL; i++) {
      if (update[i]->forwards[i] != current) {
        break;
      }
      update[i]->forwards[i] = current->forwards[i];
    }
    delete current;
  }
  delete[] update;
}

void Skiplist::show() {
  Node* current = head;
  while (current->forwards[0] != NULL) {
    cout << current->forwards[0]->key << " ";
    current = current->forwards[0];
  }
  cout << endl;

  for (int i = MAX_LEVEL; i >= 0; i--) {
    cout << "Level " << i << ": ";
    Node* current = head;
    while (current->forwards[i] != NULL) {
      cout << current->forwards[i]->key << " -> ";
      current = current->forwards[i];
    }
    cout << endl;
  }
}

int main(){
  cout << "Skiplist Program" << endl;

  // create an skiplist
  Skiplist sl;
  
  cout << "\nInsert elements into Skiplist" << endl;
  sl.insert(4);
  sl.insert(2);
  sl.insert(3);
  sl.insert(9);
  sl.insert(1);
  sl.show();

  cout << "\nSearch elements" << endl;
  cout << "- Search for 3: " << sl.search(3) << endl;
  cout << "- Search for 5: " << sl.search(5) << endl;
  
  cout << "\nRemove elements" << endl;
  sl.remove(3);
  sl.remove(5);  
  sl.show();

  return 0;
}
```

Output

```
Skiplist Program

Insert elements into Skiplist
1 2 3 4 9 
Level 4: 
Level 3: 1 -> 
Level 2: 1 -> 
Level 1: 1 -> 9 -> 
Level 0: 1 -> 2 -> 3 -> 4 -> 9 -> 

Search elements
- Search for 3: 1
- Search for 5: 0

Remove elements
1 2 4 9 
Level 4: 
Level 3: 1 -> 
Level 2: 1 -> 
Level 1: 1 -> 9 -> 
Level 0: 1 -> 2 -> 4 -> 9 -> 
```

## 🔗 Further Reading

* ▶️ [Skip Lists](https://www.youtube.com/watch?v=NDGpsfwAaqo&ab_channel=AlgorithmsLab), Algorithms Lab
* [Skip list](https://en.wikipedia.org/wiki/Skip_list), wikipedia
* ▶️ [8 Key Data Structures That Power Modern Databases](https://www.youtube.com/watch?v=W_v05d_2RTo&ab_channel=ByteByteGo)


