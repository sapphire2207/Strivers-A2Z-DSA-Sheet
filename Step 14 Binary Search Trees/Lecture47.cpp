// Lowest Common Ancestor of a Binary Search Tree

// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example:
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.

// Approach:
// Here they can be the following cases:
// Both values are to the left of any node
// Both values are to the right of any node
// One is at the left and other is at right of the node
// Any one of them is the node itself
// So while traversing, check if the current node's value is less than both the LCA's => then go to right sub tree
// check if the current node's value is greater than both the LCA's => then go to left sub tree
// For rest of the cases.... if the elements are on both sides of the current node or the current node itself is the LCA... it means this is the lowest common ancestor required.
// TC: O(log2N)
// SC: O(1)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        int current = root -> val;
        if(current < p -> val && current < q -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }
        if(current > p -> val && current > q -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }
        return root;
    }
};