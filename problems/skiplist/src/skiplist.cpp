#include <iostream>
#include "skiplist.h"

using namespace std;

// add class Class 
class Class {
public:
  int id;
  string name;
  Class(int id, string name) {
    this->id = id;
    this->name = name;
  }
};

class Student {
public:
  int id;
  string name;
  Class* classes[10];

  Student(int id, string name) {
    this->id = id;
    this->name = name;
  }
  
  void addClass(Class* c) {
  
    for (int i = 0; i < 10; i++) {
      if (classes[i] == NULL) {
        classes[i] = c;
        break;
      }
    }
  }
};

int main(){
  cout << "Skiplist Program" << endl;

  // create an skiplist
  Skiplist sl;
  // // insert 3 elements
  sl.insert(4);
  sl.insert(2);
  sl.insert(3);
  sl.insert(8);
  sl.insert(1);
  sl.show();
  return 0;
}