// Construct a BST from a preorder traversal

// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

// Brute Force:
// Here for every node you check whether the preorder traversal you are following is making sense or not... based on that you create nodes.... (since we have to add the node either to the left or right)
// TC: O(N*N) => here for every node you have to make a check
// SC: O(1)

// Better Approach:
// Here since we know that a inorder traversal will give us all the nodes in an ascending order, so sort the preorder array to get the inorder traversal, after that use the approach of lecture 34 (constructing a tree using preorder and inorder)

// Optimal Approach:
// Here, since we know that you can create a BST by maintaining the ranges concept, So what we'll do is, while traversing the preorder array, we create nodes based on the bound (Only maintain upper bound bcz at any point you have to decrease the bound or pass the same bound inorder to determine the placement of the node). So if the condition is not satisifying it means it's a null node.
// TC: O(3*N) => O(N)
// SC: O(N)
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int& i, int bound){
        if(i == preorder.size() || preorder[i] > bound){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root -> left = build(preorder, i, root -> val);
        root -> right = build(preorder, i, bound);
        return root;
    }
};