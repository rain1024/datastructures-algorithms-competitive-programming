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
  WordDictionary* obj = new WordDictionary();
  cout << "Insert bad" << endl;
  obj->addWord("bad");
  cout << "Insert dad" << endl;
  obj->addWord("dad");
  cout << "Insert mad" << endl;
  obj->addWord("mad");
  cout << "Search pad: " << obj->search("pad") << endl;
  cout << "Search bad: " << obj->search("bad") << endl;
  cout << "Search .ad: " << obj->search(".ad") << endl;
  cout << "Search b..: " << obj->search("b..") << endl;

  return 0;
}