// Iterative Preorder Traversal of Binary Tree

// Problem Statement: Given the root of a Binary Tree, write a function that returns an array containing the preorder traversal of the tree using an iterative approach with a stack.

// Algorithm / Intuition
// As a prerequisite to this approach, please understand Preorder Traversal in detail.The preorder traversal of a Binary Tree follows the order: Root, Left then Right.An iterative approach maintains a stack structure to simulate the recursive nature of the traversal without using actual recursion. The stack follows a last-in-first-out methodology and stores the nodes yet to be processed mimicking the depth-first search characteristic of preorder traversal.Initially the root node is pushed into the stack. While the stack is not empty, we continuously pop nodes from the stack and for each popped node, we add its value to the resultant traversal vector, push its right child onto the stack followed by its left child.This sequence ensures that the left child, which should be processed first in the preorder traversal, is visited before the right child due to the Last In, First Out behaviour of the stack. This process continues until all nodes are traversed.                    
#include<bits/stdc++.h>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform preorder traversal
    // of a binary tree iteratively
    vector<int> preorderTraversal(TreeNode* root) {
        // Initialize vector to store
        // the preorder traversal result
        vector<int> preorder;
        
        // If the root is null, return
        // an empty traversal result
        if(root == nullptr) {
            return preorder;
        }
        
        // Create a stack to store
        // nodes during traversal
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack
        st.push(root);
        
        // Perform iterative preorder traversal
        while(!st.empty()) {
            // Get the current node
            // from the top of the stack
            root = st.top();
            // Remove the node
            // from the stack
            st.pop();
            
            // Add the node's value to
            // the preorder traversal result
            preorder.push_back(root->val);
            
            // Push the right child
            // onto the stack if exists
            if(root->right != nullptr) {
                st.push(root->right);
            }
            
            // Push the left child onto
            // the stack if exists
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        
        // Return the preorder
        // traversal result
        return preorder;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the preorder traversal
    vector<int> result = sol.preorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Output Preorder Traversal: 1 2 3 4 5
// Complexity Analysis
// Time Complexity: O(N) where N is the number of nodes in the binary tree. Every node of the binary tree is visited exactly once, and for each node, , the operations performed (pushing and popping from the stack, accessing node values, etc.) are constant time operations.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the stack can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.