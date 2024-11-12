
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

// This solution is a recursive attempt and beats 100% in runtime. 

#include <climits>

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
    bool isValidBST(TreeNode* root) {
        return breadfirst(root, LONG_MIN, LONG_MAX);
    }
    bool breadfirst (TreeNode* node, long long low, long long high) {

        if (node == nullptr) { 
            return true;
        }

        if (node->val >= high || node->val <= low) { // we want the current node to be correct
            return false;
        }

        return breadfirst(node->left, low, node->val) && breadfirst(node->right, node->val, high);
    }
};