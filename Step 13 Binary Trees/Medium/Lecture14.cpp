// Maximum depth of a Binary Tree

// Problem Statement: Given the root of a Binary Tree, return the height of the tree. The height of the tree is equal to the number of nodes on the longest path from root to a leaf.

// Recursive Solution:
// For every node the height can be represented as: 1 + max(leftHeight, rightHeight);
// So when you visit a node and find the leftHeight first.... then find the rightHeight... and finally calculate the maxDepth. This is a recursion process since for a node there will be continous leftHeight calls until you reach a leaf node whose value or height will be zero... and there will many other functions calls in the recursion process....
#include<bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    // Function to find the
    // maximum depth of a binary tree
    int maxDepth(Node* root){
        // If the root is NULL
        // (empty tree), depth is 0
        if(root == NULL){
            return 0;
        }
        
        // Recursive call to find the
        // maximum depth of the left subtree
        int lh = maxDepth(root->left);
        
        // Recursive call to find the
        // maximum depth of the right subtree
        int rh = maxDepth(root->right);
        
        // Return the maximum depth of the
        // tree, adding 1 for the current node
        return 1 + max(lh, rh);
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    

    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}

// Complexity Analysis
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the traversal to determine the maximum depth.
// Space Complexity: O(N) where N is the number of nodes in the Binary Tree because in the worst case scenario the tree is balanced and has N/2 nodes in its last level which will have to be stored in the queue.

// Iterative Approach:
// To find the maximum depth of the binary tree using level order traversal, we employ a breadth-first approach. Initialise a queue and push the root node. Traverse through the levels and track the depth by counting the number of levels traversed. At each level pop the nodes and push their left and right children, incrementing the depth counter as we explore.This process continues until all levels are traversed at which point the depth variable holds the maximum depth of the tree.
// TC: O(N)
// SC: O(N)
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         queue<TreeNode*> q;
//         int level = 0;
//         if(root == nullptr){
//             return 0;
//         }
//         TreeNode* head = root;
//         q.push(head);
//         while(!q.empty()){
//             level++;
//             int size = q.size();
//             for(int i = 0;i < size; i++){
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 if(temp -> left != nullptr){
//                     q.push(temp -> left);
//                 }
//                 if(temp -> right != nullptr){
//                     q.push(temp -> right);
//                 }
//             }
//         }
//         return level;
//     }
// };