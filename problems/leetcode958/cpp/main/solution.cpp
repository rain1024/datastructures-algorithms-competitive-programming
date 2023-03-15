#include "solution.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

TreeNode* parse_tree(string s) {
  // parse tree from string with format
  // 1 2 3 4 5 6 null 7
  string value = "";
  vector<TreeNode*> nodes;
  TreeNode* node;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      if (value == "null") {
        node = nullptr;
      } else {
        node = new TreeNode(stoi(value));
      }
      value = "";
      nodes.push_back(node);
    } else {
      value += s[i];
    }
  }
  if (value == "null") {
    node = nullptr;
  } else {
    node = new TreeNode(stoi(value));
  }
  nodes.push_back(node);
  int n = nodes.size();
  queue<TreeNode*> q;
  TreeNode* head = nodes[0];
  q.push(head);
  int i = 1;
  while (!q.empty() && i < n) {
    node = q.front();
    q.pop();
    node->left = nodes[i];
    node->right = nodes[i + 1];
    q.push(nodes[i]);
    q.push(nodes[i + 1]);
    i += 2;
  }
  return head;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  bool is_use_file = false;

  filesystem::path filepath =
      filesystem::current_path().parent_path().parent_path() / "data" / "2.in";
  ifstream file(filepath);

  if (is_use_file) {
    cin.rdbuf(file.rdbuf());  // redirect cin to file
  }

  // get input
  string line;
  getline(cin, line);
  TreeNode* root = parse_tree(line);

  Solution solution;
  bool output = solution.isCompleteTree(root);

  // print output
  cout << output << endl;

  return 0;
}