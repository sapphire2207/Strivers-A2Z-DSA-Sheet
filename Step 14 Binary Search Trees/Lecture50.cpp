// Binary Search Tree Iterator

// Problem Statement: Implement the BSTIterator class that represents an iterator over the inorder traversal of a Binary Search Tree:
// BSTIterator(TreeNode root): Initialises an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialised to a non-existent number smaller than any element in the BST.
// boolean hasNext ( ): Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next ( ): Moves the pointer to the right, then returns the number at the pointer.
// The first call to next ( ) will return the smallest element in the BST. Next ( ) calls are always valid, ie. there will be at least a next number in the in order traversal when next ( ) is called.

// Brute Force Approach:
// Perform an inorder traversal of the Binary Search Tree and store the nodes in an array, we obtain a sorted array. Maintain a pointer or index variable to keep track of the current position within the array during iteration. BSTIterator() initiailses this index to -1 and we access the elements in ascending order incrementing the index every time next() is called.

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

class BSTIterator {
    private:
        // Store inorder traversal
        vector<int> inorderTraversal; 
        // Pointer to track current index
        int pointer; 
        
        // Perform inorder traversal of the
        // BST and store in the array
        void inorder(TreeNode* root) {
            if (root == nullptr) return;
            inorder(root->left);
            inorderTraversal.push_back(root->val);
            inorder(root->right);
        }
    
    public:
        // Constructor initializing the BSTIterator
        BSTIterator(TreeNode* root) {
             // Initialize pointer to
             // a non-existent value
            pointer = -1;
            // Store inorder traversal in the array
            inorder(root); 
        }
        
        // Checks if there exists a number in
        // the traversal to the right of the pointer
        bool hasNext() {
            return pointer + 1 < inorderTraversal.size();
        }
        
        // Moves the pointer to the right,
        // then returns the number at the pointer
        int next() {
            pointer++;
            return inorderTraversal[pointer];
        }
};

// Optimal Approach:
// The previous approach uses O(N) space complexity that grows linearly with the number of nodes in the BST. This can be optimised to a space complexity of O(H) where H is the height of the tree and O(1) time complexity for the next() and hasNext() operations by leveraging the properties of a Binary Search Tree.
// The optimised approach leverages Binary Search Tree (BST) properties to create an iterator with O(H) space complexity (where H is the tree height) and O(1) time complexity for next() and hasNext() operations.
// By using a stack and performing an iterative traversal, the constructor initialises by navigating to the leftmost nodes and storing them in a stack. The next() function retrieves the top element, explores its right subtree, and adds left descendants to the stack. hasNext() checks the stack for remaining elements to iterate over, signalling true if elements exist and false if the stack is empty.
// Complexity Analysis
// Time Complexity: O(1)as next() and hasNext() occur is constant time, the element pushed onto the stack during traversal to the leftmost node and during subsequent traversals will take O(H) time for each traversal.
// Space Complexity : O(h) where H is the height of the tree as the additional space required to store the nodes will be the height of the tree at maximum.
class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode -> right);
        return tempNode -> val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

    void pushAll(TreeNode* node){
        for(; node != nullptr; myStack.push(node), node = node -> left);
    }
};
