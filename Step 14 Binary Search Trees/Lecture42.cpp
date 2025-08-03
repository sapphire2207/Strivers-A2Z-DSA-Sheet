// Floor in a Binary Search Tree

// Problem Statement: Given a Binary Search Tree and a key, return the floor of the given key in the Binary Search Tree.
// Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key.
// If the floor node does not exist, return nullptr.

// Algorithm / Intuition
// To find the `floor` value, the approach involves tracking the largest node value encountered that is smaller than or equal to the key. It traverses the tree, either finding the exact key or reaching the nodes that approach the given key’s value. During the traversal, at every node, if the key matches the node’s values, it directly assigns the node’s value as the floor and concludes the search. If the key is smaller than the current node’s value, the algorithm navigates to the left subtree to potentially find a smaller value and if the key is larger the algorithm updates the floor value with the current node’s values and explores the right subtree for potentially larger values..
// Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(N), as it would require traversing all nodes along the path from the root to the leaf.
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
    // Function to find the floor of a key
    // in a Binary Search Tree (BST)
    int floorInBST(TreeNode* root, int key){
        // Initialize the floor variable
        // to store the floor value
        int floor = -1;
        
        // Traverse the BST until reaching
        // the endor finding the key
        while(root){
            // If the key is found, assign it 
            // as the floor value and return
            if(root->val == key){
                floor = root->val;
                return floor;
            }
            
            // root -> val is less than the key, update the floor value and move to the right subtree to find the greatest value which is less than key.
            if(key > root->val){
                // Update the floor with the current node's
                // value and move to the right subtree
                floor = root->val;
                root = root->right;
            }
            else{
                // root -> val is greater than the key, there's no point in increasing the values so, move to the left subtree
                root = root->left;
            }
        }
        // Return the computed floor value
        return floor;
    }
};
                        