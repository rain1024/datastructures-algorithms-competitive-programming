#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int bfs(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    if (!node->left && !node->right) {
      return node->val;
    }
    if (node->left) {
      node->left->val = node->val * 10 + node->left->val;
    }
    if (node->right) {
      node->right->val = node->val * 10 + node->right->val;
    }
    return bfs(node->left) + bfs(node->right);
  }

  int sumNumbers(TreeNode *root) { return bfs(root); }
};