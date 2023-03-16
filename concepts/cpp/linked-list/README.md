# Linked List in C++

From wikipedia

> In computer science, a `linked list` is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.

## Linked List implementation in C++

## Basic Operations


```c++
#include <iostream>

using namespace std;
```

**Initialization**: Create a linked list with given values


```c++
struct Node {
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int val): val(val), next(NULL){}
    Node(int val, Node* next): val(val), next(next){}
};

Node* node1 = new Node(1);
Node* node2 = new Node(2, node1);
```

**Insertion**: Insert a new element at the beginning, end or in the middle of the list

**Deletion**: Delete an element from the beginning, end or in the middle of the list



```c++
struct Node {
    int val;
    Node* next;
    
    Node(int val) : val(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    void deleteNode(int val) {
        Node* current = head;
        Node* prev = nullptr;
        
        while (current != nullptr && current->val != val) {
            prev = current;
            current = current->next;
        }
        
        if (current == nullptr) {
            std::cout << "Value not found in list" << std::endl;
        } else if (prev == nullptr) {
            head = current->next;
            delete current;
        } else {
            prev->next = current->next;
            delete current;
        }
    }
    
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
```


```c++
LinkedList list;

// Insert some values
list.insert(1);
list.insert(2);
list.insert(3);
list.insert(4);
list.insert(5);

std::cout << "List before deletion: ";
list.printList();

// Delete a node
list.deleteNode(3);

std::cout << "List after deletion: ";
list.printList();
```

    List before deletion: 1 2 3 4 5 
    List after deletion: 1 2 4 5 


## 🔗 Further Reading

* [Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/), geeksforgeeks
* ▶️ [Linked Lists Introduction](https://www.youtube.com/watch?v=-Yn5DU0_-lw&t=7s&ab_channel=WilliamFiset), WilliamFiset, 2017
* ▶️ [CS50 2018 - Lecture 4 - Linked Lists](https://www.youtube.com/watch?v=wh4TS7RJDTA), CS50, 2018
