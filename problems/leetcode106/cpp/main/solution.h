#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* solve(vector<int>&inorder, vector<int>& postorder, int i0, int i1, int p0, int p1){
        if(p0 == p1){
            return new TreeNode(postorder[p0]);
        }
        int val = postorder[p1];
        TreeNode* root = new TreeNode(val);
        int index;
        // search val in inorder
        for(int i=i0; i<=i1; i++){
            if(inorder[i] == val){
                index = i;
                break;
            }
        }
        TreeNode* left;
        TreeNode* right;
        if(index == i0){
            left = nullptr;
        } else {
            left = solve(
                inorder, postorder,
                i0, index-1,
                p0, p0 + index - i0 -1
            );
        }
        root->left = left;
        
        if(index == i1){
            right = nullptr;
        } else {
            int size = i1 - (index + 1);
            right = solve(
                inorder, postorder,
                index+1, i1,
                p1-1-size, p1-1
            );
        }
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(
            inorder, postorder,
            0, inorder.size()-1,
            0, postorder.size()-1);
    }
};