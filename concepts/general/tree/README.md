# Tree

*See implementation in* 
[C++](/concepts/cpp/tree/README.md), 
Java, 
[Python](/concepts/python/tree/README.md),
Typescript, 


Tree is a data structure that consists of nodes in a parent / child relationship. A tree can be empty with no nodes or a tree is a structure consisting of one node called the root and zero or one or more subtrees.

Tree are prefered over arrays when we need to search for a specific value or when we need to insert/delete a value.

## Type of Trees

* Binary Tree: A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.
* Binary Search Tree: A binary search tree (BST) is a node-based binary tree data structure which has the following properties:
  * The left subtree of a node contains only nodes with keys less than the node's key.
  * The right subtree of a node contains only nodes with keys greater than the node's key.
  * The left and right subtree each must also be a binary search tree.
* AVL Tree: An AVL tree is a self-balancing binary search tree. It was the first such data structure to be invented. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property.
* Red-Black Tree: A red–black tree is a kind of self-balancing binary search tree in computer science. Each node of the binary tree has an extra bit, and that bit is often interpreted as the color (red or black) of the node. These color bits are used to ensure the tree remains approximately balanced during insertions and deletions.
* Segment Tree: A segment tree is a tree data structure for storing intervals, or segments. It allows querying which of the stored segments contain a given point.
* Fenwick Tree: A Fenwick tree or binary indexed tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.

## Tree Operations

Here are some basic operations that you can perform on trees:

* Initialization: Create a tree with given value
* Traversal: Visit all nodes of the tree
* Insertion: Insert a node in the tree
* Deletion: Delete a node from the tree

## 🔗 Further Reading

* [Tree (data structure)](https://en.wikipedia.org/wiki/Tree_(data_structure)), wikipedia
* ▶️ [Introduction to tree algorithms](https://www.youtube.com/watch?v=1XC3p2zBK34&list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc&ab_channel=WilliamFiset), WilliamFiset
* ▶️ [Beginner tree algorithms](https://www.youtube.com/watch?v=0qgaIMqOEVs&list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc&index=2&ab_channel=WilliamFiset), WilliamFiset