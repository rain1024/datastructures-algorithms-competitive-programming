#include <iostream>
#include "skiplist.h"

using namespace std;

int main(){
  cout << "Hello world!" << endl;
  // create an skiplist
  Skiplist sl;
  // insert 3 elements
  sl.insert(4);
  sl.insert(2);
  sl.insert(3);
  sl.show();
  return 0;
}