# Binaray Search Tree

A `binary search tree (BST)` is a type of binary tree data structure in which each node has at most two child nodes, usually referred to as left and right children. In a binary search tree, the value of each node is greater than or equal to the values of all nodes in its left subtree and less than or equal to the values of all nodes in its right subtree.

## Binary Search Tree Implementation in C++

Binary Search TreeNode Struct:


```c++
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
}
```


```c++
TreeNode* root = new TreeNode(10);
```

**Print**: Print the tree in order


```c++
void print(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  int count;
  while(!q.empty()){
    count = q.size();
    while(count > 0){
      TreeNode* node = q.front();
      q.pop();
      cout << node->val << " ";
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
      count--;
    }
    cout << endl;
  }
}
```

**Insertion**: Insert a new node into the tree


```c++
TreeNode* insertIntoBST(TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }

  if (val < root->val) {
    root->left = insertIntoBST(root->left, val);
  } else if (val > root->val){
    root->right = insertIntoBST(root->right, val);
  }

  return root;
}
```


```c++
root = insertIntoBST(root, 2);
root = insertIntoBST(root, 1);
root = insertIntoBST(root, 5);
root = insertIntoBST(root, 15);
root = insertIntoBST(root, 11);
root = insertIntoBST(root, 20);
print(root)
```

    10 
    2 15 
    1 5 11 20 


**Deletion**: Delete a node from the tree


```c++
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
```


```c++
root = deleteNode(root, 5);
print(root)
```

    10 
    2 15 
    1 11 20 



```c++
root = deleteNode(root, 10);
print(root)
```

    15 
    11 20 
    2 
    1 


## 🔗 Further Reading

* [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
* [An Introduction To Binary Search And Red-black Trees](https://www.topcoder.com/thrive/articles/An%20Introduction%20to%20Binary%20Search%20and%20Red-Black%20Trees), TopCoder 
* ▶️ [Binary Search Tree Introduction](https://www.youtube.com/watch?v=JfSdGQdAzq8&pp=ygUgYmluYXJ5IHNlYXJjaCB0cmVlIHdpbGxpYW0gZmlzZXQ%3D&ab_channel=WilliamFiset), WilliamFiset
* ▶️ [Binary Search Tree Insertion](https://www.youtube.com/watch?v=LwpLXm3eb6A&ab_channel=WilliamFiset), WilliamFiset
* ▶️ [Data Structures: Binary Search Tree](https://www.youtube.com/watch?v=i_Q0v_Ct5lY&ab_channel=HackerRank), HackerRank
