// Construct Binary Tree from Inorder and Postorder Traversal

// Problem Statement: Given the Postorder and Inorder traversal of a Binary Tree, construct the Unique Binary Tree represented by them.

// Example :
// Input: Inorder: [9, 3, 15, 20, 7], Postorder: [9, 15, 7, 20, 3]

// Optimal Approach:
// Optimal Approach:
// So initially, take the last element of the postorder traversal, because it's the root element.
// Now figure out the position of that element in the inorder traversal, because it distinguishes the left and right sub trees. (Keep a track of the inorder elements in a map to make it easier)
// Now break down the problem into two parts, write the inorder and postorder traversals for each sub tree.
// While performing the above steps, you'll get to know about the positions or indexes of the inorder traversal of left sub tree and the postorder traversal of left sub tree => using this we again determine the left sub tree and right sub tree of this particular left sub tree.
// Similarly you'll get to know about the positions or indexes of the inorder traversal of right sub tree and the postorder traversal of right sub tree => using this we again determine the left sub tree and right sub tree of this particular right sub tree.
// Whenever you find indexes (start and end) cross each other, it means that there's no elements to it's left or right... meaning it has reached the leaf node.
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This is because each node is processed and visited exactly once.
// The algorithm processes each element in the inorder traversal and for each element it performs constant-time operations (lookup in the hashmap, recursive calls and variable operations).
// Space Complexity: O(N + log2N) where N is the number of elements in the iwhere N is the number of nodes in the Binary Tree.
// This complexity arises from the space used by the recursion stack during the recursive calls. In the worst case, the maximum depth of the recursion stack would be equal to the height of the Binary Tree and in the optimal case the recursion stack complexity would be O(log2N).

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildingTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);

        return root;
    }

    TreeNode* buildingTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mpp){
        if(postStart > postEnd || inStart > inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[root -> val];
        int numsLeft = inRoot - inStart;

        root -> left = buildingTree(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, mpp);
        root -> right = buildingTree(postorder, postStart + numsLeft , postEnd - 1, inorder, inRoot + 1, inEnd, mpp);
        return root;
    }
};