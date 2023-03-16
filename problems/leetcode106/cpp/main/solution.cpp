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

  // get input
  int x;
  cin >> x;

  vector<int> inorder;
  for(int i=0; i<x; i++){
    cin >> inorder[x];
  }

  vector<int> postorder;
  for(int i=0; i<x; i++){
    cin >> postorder[x];
  }

  Solution solution;
  TreeNode* tree = solution.buildTree(inorder, postorder);

  // print output
  cout << tree->val << endl;

  return 0;
}