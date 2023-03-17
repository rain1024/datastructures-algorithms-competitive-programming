# Binaray Search Tree

*See implementation in*
C++,
Java,
Python,
Typescript

A `binary search tree (BST)` is a type of binary tree data structure in which each node has at most two child nodes, usually referred to as left and right children. In a binary search tree, the value of each node is greater than or equal to the values of all nodes in its left subtree and less than or equal to the values of all nodes in its right subtree.

Binary search trees are often used for searching and sorting algorithms because they have a time complexity of $O(log n)$ for most operations, including searching, insertion, and deletion, where n is the number of nodes in the tree. However, the performance of a binary search tree can degrade to $O(n)$ in the worst case scenario, such as when the tree is unbalanced. To maintain optimal performance, it is important to balance the tree periodically or use a self-balancing binary search tree.

## Binary Search Tree Operations

Here are some basic operations that you can perform on binary search trees:

* Insertion: Insert a new node into the tree
* Deletion: Delete a node from the tree
* Searching: Search for a node in the tree

**Insertion**: To insert a new node into a binary search tree, you start at the root node and compare the value of the new node with the value of the root node. If the new node's value is less than the root node's value, you recursively insert the node into the left subtree. If the new node's value is greater than the root node's value, you recursively insert the node into the right subtree. Once you reach a leaf node, you insert the new node as a child of that leaf node.

**Deletion**: To delete a node from a binary search tree, you first search for the node to be deleted. Once you've found the node, you need to decide how to reorganize the tree to maintain the binary search tree property. If the node has no children, you simply remove it. If the node has one child, you replace the node with its child. If the node has two children, you find the node with the next largest value (i.e. the smallest value in its right subtree), replace the node to be deleted with that node, and then delete the replacement node.

**Searching**: To search for a node in a binary search tree, you start at the root node and compare the value of the node you're searching for with the value of the root node. If the values are equal, you've found the node. If the value you're searching for is less than the root node's value, you recursively search the left subtree. If the value you're searching for is greater than the root node's value, you recursively search the right subtree. If you reach a leaf node without finding the value, then the value is not in the tree.



## 🔗 Further Reading

* [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
* [An Introduction To Binary Search And Red-black Trees](https://www.topcoder.com/thrive/articles/An%20Introduction%20to%20Binary%20Search%20and%20Red-Black%20Trees), TopCoder 
* ▶️ [Binary Search Tree Introduction](https://www.youtube.com/watch?v=JfSdGQdAzq8&pp=ygUgYmluYXJ5IHNlYXJjaCB0cmVlIHdpbGxpYW0gZmlzZXQ%3D&ab_channel=WilliamFiset), WilliamFiset
* ▶️ [Binary Search Tree Insertion](https://www.youtube.com/watch?v=LwpLXm3eb6A&ab_channel=WilliamFiset), WilliamFiset
* ▶️ [Data Structures: Binary Search Tree](https://www.youtube.com/watch?v=i_Q0v_Ct5lY&ab_channel=HackerRank), HackerRank