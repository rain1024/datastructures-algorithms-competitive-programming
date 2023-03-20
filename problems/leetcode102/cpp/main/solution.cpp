#include "solution.h"
#include "helpers.h"

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
  TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

  Solution solution;
  vector<vector<int>> output = solution.levelOrder(root);

  // print output
  for (auto iter : output) {
    for(auto i: iter){
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}