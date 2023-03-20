/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }

  if (val < root->val) {
    root->left = insertIntoBST(root->left, val);
  } else if (val > root->val) {
    root->right = insertIntoBST(root->right, val);
  }

  return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
  if (root == nullptr) return root;
  if (key < root->val)
    root->left = deleteNode(root->left, key);
  else if (key > root->val)
    root->right = deleteNode(root->right, key);
  else {
    if (!root->left && !root->right) return nullptr;
    if (!root->left)
      return root->right;
    else if (!root->right)
      return root->left;
    else {
      TreeNode* temp = root->right;
      while (temp->left) temp = temp->left;
      temp->left = root->left;
      return root->right;
    }
  }
  return root;
}

void print(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);
  int count;
  while (!q.empty()) {
    count = q.size();
    while (count > 0) {
      TreeNode* node = q.front();
      q.pop();
      cout << node->val << " ";
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
      count--;
    }
    cout << endl;
  }
}

int main() {
  TreeNode* root =
      new TreeNode(10, new TreeNode(2, new TreeNode(1), new TreeNode(5)),
                   new TreeNode(15, new TreeNode(11), new TreeNode(20)));

  cout << "Before delete\n";
  print(root);

  // cout << "\nAfter delete 5\n";
  // root = deleteNode(root, 5);
  // print(root);

  // cout << "\nAfter delete 11\n";
  // root = new TreeNode(10, new TreeNode(2, new TreeNode(1), new TreeNode(5)),
  //                  new TreeNode(15, new TreeNode(11), new TreeNode(20)));
  // root = deleteNode(root, 11);
  // print(root);

  // cout << "\nAfter delete 2\n";
  // root = new TreeNode(10, new TreeNode(2, new TreeNode(1), new TreeNode(5)),
  //                     new TreeNode(15, new TreeNode(11), new TreeNode(20)));
  // root = deleteNode(root, 2);
  // print(root);

  cout << "\nAfter delete 10\n";
  root = new TreeNode(10, new TreeNode(2, new TreeNode(1), new TreeNode(5)),
                      new TreeNode(15, new TreeNode(11), new TreeNode(20)));
  root = deleteNode(root, 10);
  print(root);

  return 0;
}
