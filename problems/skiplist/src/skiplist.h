#include <iostream>

using namespace std;

// create class Skiplist

// Node struct
struct Node {
  int key;
  int level;
  Node** forwards;
  // constructor
  Node(int key, int level){
    this->key = key;
    forwards = new Node*[level+1];
    for(int i=0; i<=level; i++){
      forwards[i] = NULL;
    }
  }
};

class Skiplist {
  public:
    Skiplist();
    ~Skiplist();
    void insert(int key);
    void insert2(int key);
    bool search(int key);
    void erase(int key);
    void show();
  private:
    Node* head;
    int MAX_LEVEL;
};

Skiplist::Skiplist(){
  MAX_LEVEL = 16;
  Node* head = new Node(INT_MIN, MAX_LEVEL);
}


void Skiplist::insert(int key){
  cout << "Skiplist::insert " << key << endl;
  // Create a new node with the given key.
  int level = rand() % MAX_LEVEL;
  cout << "level = " << level << endl;
  Node* newNode = new Node(key, level);
  
  // Create a pointer to the current node
  Node* current = head;
  // Create an array of pointers to the previous nodes
  // with size equal to the random level
  Node** update = new Node*[level+1];
  for(int i=0; i<=level; i++){
    update[i] = NULL;
  }

  // // Traverse the list from the highest level to the lowest level
  // // and find the previous node for each level
  // for(int i=level; i>=0; i--){
  //   cout << "i = " << i << endl;
  //   // while(current->forwards[i] != NULL && current->forwards[i]->key < key){
  //   //   // update the curent node
  //   //   current = current->forwards[i];
  //   //   cout << "current = " << current->key << endl;
  //   // }
  //   cout << "current = " << current->key << endl;
  //   // update the previous node for the current level
  //   update[i] = current;
  //   cout << "Debug" << endl;
  // }

  // cout << "Debug" << endl;
  
  // // Set the next node for the new node to the next node of the previous node
  // // for the lowest level
  // newNode->forwards[0] = update[0]->forwards[0];
  // // Set the next node of the previous node for the lowest level to the new node
  // update[0]->forwards[0] = newNode;

  // for(int i=1; i<=level; i++){
  //   newNode->forwards[i] = update[i]->forwards[i];
  //   update[i]->forwards[i] = newNode;
  // } 
  cout << "End Skiplist::insert" << endl;
}

void Skiplist::show(){
  cout << "Skiplist::show" << endl;

  Node* current = head;
  while(current->forwards[0] != NULL){
    cout << current->forwards[0]->key << " ";
    current = current->forwards[0];
  }
}