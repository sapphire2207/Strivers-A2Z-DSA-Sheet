// Calculate the Diameter of a Binary Tree

// Problem Statement: Given the root of the Binary Tree, return the length of its diameter. The Diameter of a Binary Tree is the longest distance between any two nodes of that tree. This path may or may not pass through the root.

// Brute Force:
// To find the diameter of a binary tree, we can think of every node as a potential `Curving Point` of the diameter path. This Curving Point is the node along the diameter path that holds the maximum height and from where the path curves uphill and downhill.
// Recursively start traversing from the root, consider the current node to be a potential Curving Point and for each node:
// Recursively calculate the height of its left and right subtrees.
// Compute the diameter at the current node by summing heights of the left and right subtrees.
// Update the global variable diameter as the max of the current diameter and the largest diameter encountered so far.
// Time Complexity: O(N*N) where N is the number of nodes in the Binary Tree.
// This arises as we calculate the diameter of each node and to calculate the height of its left and right children, we traverse the tree which is proportional to the number of nodes.
// Since this calculation is performed for each node in the tree, the complexity becomes: O(N x N) ~ O(N2).
// Space Complexity : O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.
#include <bits/stdc++.h>
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
    int diameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void findMaxDiameter(TreeNode* root) {
        if (root == nullptr) return;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        findMaxDiameter(root->left);
        findMaxDiameter(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        findMaxDiameter(root);
        return diameter;
    }
};

// Optimal Approach:
// The O(N2) time complexity of the previous approach can be optimised by eliminating the steps of repeatedly calculating subtree heights. The heights of the left and right subtrees are computed multiple times for each node, which leads to redundant calculations.Instead, we can compute these heights in a bottom-up manner. The Postorder method allows us to validate balance conditions efficiently during the traversal.
// The postorder traversal operates in a bottom-up manner, calculating subtree information before moving to the parent node. We efficiently compute the heights of both the subtrees and at the same time calculate the diameter and update the maximum diameter encountered.
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.
// Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode* root, int& diameter){
        if(!root){
            return 0;
        }

        int leftHeight = height(root -> left, diameter);
        int rightHeight = height(root -> right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};