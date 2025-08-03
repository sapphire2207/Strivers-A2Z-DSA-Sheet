// Check if the Binary Tree is Balanced Binary Tree

// Problem Statement: Given a Binary Tree, return true if it is a Balanced Binary Tree else return false. A Binary Tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

// Recusive approach and Brute Force:
// As a prerequisite, make sure you are thorough with the concepts of Calculating the Height of a Binary Tree.
// Base Case:If the root node is null, signifying an empty tree, return true as an empty tree is considered balanced.
// Recursive Algorithm: The `isBalanced` function is used to check if a Binary Tree is balanced, accepting a `root` node. Calculate the height of the left subtree and store it in a variable. Calculate the height of the right subtree and store it in a variable. Check if the absolute difference in heights of the left and right subtree is less than or equal to 1. If true then call the `isBalanced` recursive function for both the left and right child.
// If the condition is satisfied and both the left and right subtrees are balanced (recursive calls to isBalanced return true), return true, indicating a balanced tree.
// If the absolute difference of heights is greater than 1 or the recursive calls to left and right subtrees return false then return false.
// Time Complexity: O(N2) where N is the number of nodes in the Binary Tree.This arises as we calculate the height of each node and to calculate the height for each node, we traverse the tree which is proportional to the number of nodes. Since this calculation is performed for each node in the tree, the complexity becomes: O(N x N) ~ O(N2).
// Space Complexity : O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);

        if(abs(lh - rh) > 1){
            return false;
        }

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        if(!left || !right){
            return false;
        }
        return true;
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1 + max(lh, rh);
    }
};

// Optimal approach:
// Traverse the Binary Tree is post-order manner using recursion. Visit left subtree, then right subtree, and finally the root node.
// During the traversal, for each node, calculate the heights of the its left and right subrees. Use the obtained subtree heights to validate the balance conditions for the current node.
// At each node, if the absolute difference between the heights of the left and right subtrees is greater than 1 or if any subtree is unbalanced (returns -1), return -1 immediately indicating an unbalanced tree.
// If the tree is balanced, return the height of the current node by considering the maximum height of its left and right subtree plus 1 accounting for the current node.
// Complete the traversal until all nodes are visited and return the final result - either the height of the entire tree if balanced or -1 if unbalanced.
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.
// Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHeight = dfsHeight(root -> left);
        if(leftHeight == -1) return -1;
        int rightHeight = dfsHeight(root -> right);
        if(rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }
};