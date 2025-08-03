// Check if two trees are identical

// Problem Statement: Given two Binary Trees, return if true if the two trees are identical, otherwise return false.

// Optimal Approach:
// To determine if two binary trees are identical, we can follow a recursive approach. We traverse both trees in the preorder manner, meaning that the current node's value is checked before recursively traversing its left and right subtrees.
// The idea is to traverse both trees simultaneously, comparing the values of corresponding nodes at each step. We need to ensure that the left subtree of each node in the first tree is identical to the left subtree of the corresponding node in the second tree, and similarly for the right subtrees.
// Base Case: The base case for recursion is reached when both nodes are null, indicating the end of the subtree. In this case return true. If only one of the nodes in null while the other is not or vice versa, return false since they cannot be identical.
// Recursive Function:
// Check if the values of the current nodes in both tree are equal. If not, return false otherwise check the conditions below.
// Check if the left subtree of both the trees is identical or not by calling the recursive function on the left child.
// Check if the right subtree of both the trees is identical or not by calling the recursive function on the right child.
// If all recursive calls return true, indicating that the values and structures of the subtrees are identical, the function returns true, confirming that the entire trees are identical.
// Time Complexity: O(N+M) where N is the number of nodes in the first Binary Tree and M is the number of nodes in the second Binary Tree. This complexity arises from visiting each node of the two binary nodes during their comparison.
// Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case (its N).
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        return (p -> val == q -> val) && (isSameTree(p -> left, q -> left)) && (isSameTree(p -> right, q -> right));
    }
};