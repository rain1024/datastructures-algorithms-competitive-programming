#include <iostream>
#include <climits>

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
    this->level = level;
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
  head = new Node(INT_MIN, MAX_LEVEL);
  srand(time(NULL));
}

Skiplist::~Skiplist(){
  delete head;
}

void Skiplist::insert(int key){
  // Create a new node with the given key.
  // The level of the new node is a random number between 0 and MAX_LEVEL
  // create random number between 0 to 1, if < 0.5, level++; otherwise, break
  int level = 0;
  
  while(rand() % 2 && level < MAX_LEVEL){
    level++;
  }
  Node* newNode = new Node(key, level);
  // print newNode key and level
  cout << "newNode (" << newNode->key << ", " << newNode->level << ")" << endl;
  
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
  for(int i=level; i>=0; i--){
    while(current->forwards[i] != NULL && current->forwards[i]->key < key){
      // update the curent node
      current = current->forwards[i];
    }
    // update the previous node for the current level
    update[i] = current;
  }

  // cout << "Debug" << endl;
  
  // // Set the next node for the new node to the next node of the previous node
  // // for the lowest level
  newNode->forwards[0] = update[0]->forwards[0];
  // // Set the next node of the previous node for the lowest level to the new node
  update[0]->forwards[0] = newNode;

  for(int i=1; i<=level; i++){
    newNode->forwards[i] = update[i]->forwards[i];
    update[i]->forwards[i] = newNode;
  } 
}

// show skiplist of all levels
// level 0 will have all elements
// if an element is not exist in a level, print " "
void Skiplist::show(){
  cout << "Skiplist::show" << endl;

  Node* current = head;
  while(current->forwards[0] != NULL){
    cout << current->forwards[0]->key << " ";
    current = current->forwards[0];
  }

  // show for each levels
  for(int i=MAX_LEVEL; i>=0; i--){
    cout << "Level " << i << ": ";
    Node* current = head;
    while(current->forwards[i] != NULL){
      cout << current->forwards[i]->key << " -> ";
      current = current->forwards[i];
    }
    cout << endl;
  }
}