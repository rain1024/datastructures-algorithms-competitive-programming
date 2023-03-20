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
  vector<vector<int>> depths(vector<TreeNode *> nodes) {
    if (nodes.size() == 0) {
      return {};
    }
    vector<int> current = {};
    vector<TreeNode *> next_nodes = {};
    for (auto node : nodes) {
      if (node != nullptr) {
        current.push_back(node->val);
        if (node->left != nullptr) {
          next_nodes.push_back(node->left);
        }
        if (node->right != nullptr) {
          next_nodes.push_back(node->right);
        }
      }
    }
    vector<vector<int>> result = {current};
    vector<vector<int>> children = depths(next_nodes);
    if (children.size() != 0) {
      result.insert(result.end(), children.begin(), children.end());
    }
    return result;
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> result = {{root->val}};
    if (root->left == nullptr && root->right == nullptr) {
      return result;
    }
    vector<vector<int>> children = depths({root->left, root->right});
    if (children.size() != 0) {
      result.insert(result.end(), children.begin(), children.end());
    }
    return result;
  }
};