// Validate Binary Search Tree

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 2:
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

// Optimal Approach:
// Here the approach is to maintain a range of minval and maxVal for each node while traversing a subtree...
// whenever you find someone not satisfying the range we can return false.
// TC: O(N)
// SC: O(1), but auxillary stack space is O(N) => no extra space
#include<bits/stdc++.h>
using namespace std;

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
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    private: bool isValid(TreeNode* root, long minVal, long maxVal){
        if(root == nullptr){
            return true;
        }
        if(root -> val >= maxVal || root -> val <= minVal) return false;
        return isValid(root -> left, minVal, root -> val) && isValid(root -> right, root -> val, maxVal);
    }
};