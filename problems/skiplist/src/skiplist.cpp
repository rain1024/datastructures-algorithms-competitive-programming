#include <iostream>
#include "skiplist.h"

using namespace std;

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