// Ceil in a Binary Search Tree

// Problem Statement: Given a Binary Search Tree and a key, return the ceiling of the given key in the Binary Search Tree.
// Ceiling of a value refers to the value of the smallest node in the Binary Search Tree that is greater than or equal to the given key.
// If the ceiling node does not exist, return nullptr.

// Algorithm / Intuition
// The strategy to find the `ceil` value is to keep track of the smallest node value encountered that is greater than or equal to the key. Traverse the tree recursively and move through it until it reaches the end or locates the key. During the traversal, at every node, if the key matches the node’s values, it directly assigns the node’s value as the ceiling and concludes the search. If the key is greater than the current node’s value, the algorithm navigates to the right subtree to potentially find a larger value and if the key is smaller the algorithm updates the ceil value with the current node’s values and explores the left subtree for potentially smaller values.
// Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.
// Space Complexity: O(1) since the algorithm does not use any additional space or data structures.

#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the ceiling of
    // a key in a Binary Search Tree (BST)
    int findCeil(TreeNode* root, int key){
        // Initialize the variable
        // to store the ceiling value
        int ceil = -1; 
        
        // Traverse the BST until reaching
        // the end or finding the key
        while(root){
             // If the key is found, assign it
             // as the ceiling and return
            if(root->val == key){
                ceil = root->val;
                return ceil;
            } 
            
             // If the root->val is smaller,
             // move to the right subtree
            if(root->val < key){
                root = root->right;
            }
            else{ 
                // If the If the root->val is greater, update ceil
                // and move to the left subtree
                ceil = root->val;
                root = root->left;
            }
        }
         // Return the computed ceiling value
        return ceil;
    }
};
