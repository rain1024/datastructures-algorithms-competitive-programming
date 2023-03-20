#include "solution.h"
#include "helpers.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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

  // get input
  string line;
  getline(cin, line);
  Node* root = parse_nary_tree<Node>(parse_line(line));

  Solution solution;
  vector<int> v = solution.preorder(root);
  
  // print output
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}