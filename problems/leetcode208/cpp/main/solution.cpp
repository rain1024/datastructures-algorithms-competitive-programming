#include "solution.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  bool is_use_file = false;

  filesystem::path filepath =
      filesystem::current_path().parent_path().parent_path() / "data" / "1.in";
  ifstream file(filepath);

  if (is_use_file) {
    cin.rdbuf(file.rdbuf());  // redirect cin to file
  }

  // get input and print output

  Trie* trie = new Trie();
  trie->insert("apple");
  cout << trie->search("apple") << endl;   // return True
  cout << trie->search("app") << endl;     // return False
  cout << trie->startsWith("app") <<endl; // return True
  trie->insert("app");
  cout << trie->search("app") << endl;     // return True

  return 0;
}