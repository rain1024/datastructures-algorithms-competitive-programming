#include <algorithm>
#include <cmath>
#include <map>
#pragma once

#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (root == nullptr) return vector<int>{};
    vector<int> v;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      Node* current = s.top();
      v.push_back(current->val);
      s.pop();
      for (int i = current->children.size() - 1; i >= 0; i--) {
        s.push(current->children[i]);
      }
    }
    return v;
  }
};