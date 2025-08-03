// Maximum Sum Path in Binary Tree

// Problem Statement: Given a Binary Tree, determine the maximum sum achievable along any path within the tree. A path in a binary tree is defined as a sequence of nodes where each pair of adjacent nodes is connected by an edge. Nodes can only appear once in the sequence, and the path is not required to start from the root. Identify and compute the maximum sum possible along any path within the given binary tree.

// To find the diameter of a binary tree, we can think of every node as a potential `Curving Point` of the path along which we find the sum. The maximum sum of a path through a turning point (like a curve) can be found by adding
// We can recursively traverse the tree, considering each node as a potential turning point and storing the maximum value (our final answer) in a reference variable. The recursive function should be defined in such a way that we consider both the possibilities:
// When the current node is the turning point and in this scenario we calculate the maximum path sum taking into sum contributions from both the left and right subtrees along with the value of the current node.
// When the current node is not the turning point, we consider only the left or the right subtree. The maximum of the two is returned as the maximum path sum of that subtree.
// Base Case: When the current node is null which indicates the end of a path or a lead node, we return the maximum path sum as 0.
// Recursive Function:
// Calculate the maximum path sum for the left and right subtrees by making recursive calls to the left and right child of the current node.
// Calculate the maximum path sum when the current node serves as the turning point: Maximum Path Sum when Current Node is Turning Point = Maximum Path Sum of Left Subtree + Maximum Path Sum of Right Subtree + Current Value of Node
// Update the overall maximum path sum (maxi) by considering the sum of the current node and the left and right subtree sums.
// Return the maximum sum considering only one branch (either left or right) along with the value of the current node as the maximum sum up until this node.
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the recursive traversal.
// Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.
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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }

    int maxPathDown(TreeNode* root, int& maxi){
        if(root == nullptr){
            return 0;
        }
        int leftSum = max(0, maxPathDown(root -> left, maxi));
        int rightSum = max(0, maxPathDown(root -> right, maxi));
        maxi = max(maxi, leftSum + rightSum + root -> val);
        return root -> val + max(leftSum, rightSum);
    }
};