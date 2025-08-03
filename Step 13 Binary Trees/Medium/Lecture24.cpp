// Right/Left view of binary tree

// Problem Statement: Given a Binary Tree, return its right and left views.
// The Right View of a Binary Tree is a list of nodes that can be seen when the tree is viewed from the right side. The Left View of a Binary Tree is a list of nodes that can be seen when the tree is viewed from the left side.

// Algorithm / Intuition
// To get the left and right view of a Binary Tree, we perform a depth-first traversal of the Binary Tree while keeping track of the level of each node. For both the left and right view, we’ll ensure that only the first node encountered at each level is added to the result vector.
// Algorithm for Left View
// Step 1: Initialise an empty vector `res` to store the left view nodes.
// Step 2: Implement a recursive depth-first traversal of the binary tree.
// Base Case: Check if the current node is null, if true, return the function as we have reached the end of that particular vertical level.
// Recursive Function: The recursive function takes in arguments the current node of the Binary Tree, its current level and the result vector.

// Algorithm for Right View
// Step 1: Initialise an empty vector `res` to store the left view nodes.
// Step 2: Implement a recursive depth-first traversal of the binary tree.
// Base Case: Check if the current node is null, if true, return the function as we have reached the end of that particular vertical level.
// Recursive Function: The recursive function takes in arguments the current node of the Binary Tree, its current level and the result vector.
// Time Complexity: O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises as we travel along the height of the Binary Tree. For a balanced binary tree, the height is log2N but in the worst case when the tree is skewed, the complexity becomes O(N).
// Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises because we store the leftmost and rightmost nodes in an additional vector. The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.
// O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.
// The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.               
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

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

class Solution {
public:
    // Function to return the Right view of the binary tree
    vector<int> rightsideView(Node* root){
        // Vector to store the result
        vector<int> res;
        
        // Call the recursive function
        // to populate the right-side view
        recursionRight(root, 0, res);
        
        return res;
    }
    
    // Function to return the Left view of the binary tree
    vector<int> leftsideView(Node* root){
        // Vector to store the result
        vector<int> res;
        
        // Call the recursive function
        // to populate the left-side view
        recursionLeft(root, 0, res);
        
        return res;
    }

private:
    // Recursive function to traverse the
    // binary tree and populate the left-side view
    void recursionLeft(Node* root, int level, vector<int>& res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
        }
        
        // Recursively call the function for the
        // left child with an increased level
        recursionLeft(root->left, level + 1, res);
        
        // Recursively call the function for the
        // right child with an increased level
        recursionLeft(root->right, level + 1, res);
    }
    
    // Recursive function to traverse the
    // binary tree and populate the right-side view
    void recursionRight(Node* root, int level, vector<int> &res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
            
            // Recursively call the function for the
            // right child with an increased level
            recursionRight(root->right, level + 1, res);
            
            // Recursively call the function for the
            // left child with an increased level
            recursionRight(root->left, level + 1, res);
        }
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

        // Get the Right View traversal
    vector<int> rightView = solution.rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}