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
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
      TreeNode* node = q.front();
      q.pop();
      if(node == nullptr){
        while(!q.empty()){
          if(q.front() != nullptr){
            return false;
          }
          q.pop();
        }
      } else {
        q.push(node->left);
        q.push(node->right);
      }
    }
    return true;
  }
};