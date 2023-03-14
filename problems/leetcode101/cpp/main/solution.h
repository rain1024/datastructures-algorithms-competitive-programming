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
  bool isEquals(vector<TreeNode *> lefts, vector<TreeNode *> rights) {
    if (lefts.size() != rights.size()) {
      return false;
    }
    int n = lefts.size();
    TreeNode *left, *right;
    for (int i = 0; i < lefts.size(); i++) {
      left = lefts[i];
      right = rights[n - 1 - i];
      if (left == nullptr && right == nullptr) {
        continue;
      } else if (left != nullptr && right != nullptr) {
        if (left->val != right->val) {
          return false;
        }
      } else {
        return false;
      }
    }
    vector<TreeNode *> left_nexts, right_nexts;
    int num_not_nulls = 0;
    for (int i = 0; i < lefts.size(); i++) {
      left = lefts[i];
      right = rights[i];
      if (left != nullptr) {
        num_not_nulls += 1;
        left_nexts.push_back(left->left);
        left_nexts.push_back(left->right);
      }
      if (right != nullptr) {
        right_nexts.push_back(right->left);
        right_nexts.push_back(right->right);
      }
    }
    if (num_not_nulls > 0) {
      return isEquals(left_nexts, right_nexts);
    } else {
      return true;
    }
  }

  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    return isEquals({root->left}, {root->right});
  }
};