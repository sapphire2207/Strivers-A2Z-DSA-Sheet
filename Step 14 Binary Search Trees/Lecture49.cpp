// Inorder Successor/Predecessor in BST

// Problem Statement: Given a Binary Search Tree and a ‘key’ value which represents the data data of a node in this tree. Return the inorder predecessor and successor of the given node in the BST.
// The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. Return nullptr if the given node is the one that is visited first in the inorder traversal.
// The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. Return nullptr if the given node is visited last in the inorder traversal.

// Example 1:
// Input:Binary Search Tree: 5 3 7 2 4 6 9 1 -1 -1 -1 -1 -1 8 10, Key = 8
// Output:Inorder Predecessor : 7, Inorder Successor : 9

// Brute Force Approach:
// Perform an inorder traversal of the binary search tree to generate a sorted list of node values. On these values, do a binary search on this sorted list to identify the first value greater than the key hence determining the successor. In scenarios where the given key represents the maximum value within the BST ie. the last node in the inorder traversal ,return null.
// Time Complexity: O(N + logN) where N is the number of nodes of the binary search tree. O(N) to traverse all nodes and store them in an inorder array and O(log N) for the binary search.
// Space Complexity: O(N) as an array of size N is used to store the inorder traversal of the binary search tree.
class Solution {
public:
    // Function to find the inorder 
    // successor of a node in a BST
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // Store the inorder traversal of the tree
        vector<int> inorder;
        // Perform in-order traversal to
        // generate the sorted list
        inorderTraversal(root, inorder);
        
        // Binary search to find the
        // index of the node's value
        int idx = binarySearch(inorder, p->val);
        
        // If index is out of range or it's the
        // last element, return nullptr
        if (idx == inorder.size() - 1 || idx == -1) {
            return nullptr;
        }
        
        // Return the next element
        // as the inorder successor
        return new TreeNode(inorder[idx + 1]);
    }
    
    // Function to perform in-order traversal
    // and store in 'inorder' vector
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        // Base case: If the node is NULL, return
        if (root == nullptr) {
            return;
        }
        
        // Traverse left subtree
        inorderTraversal(root->left, inorder);
        
        // Store current node's value
        // in 'inorder' vector
        inorder.push_back(root->val);
        
        // Traverse right subtree
        inorderTraversal(root->right, inorder);
    }
    
    // Function to perform
    // binary search on array
    int binarySearch(vector<int>& arr, int target) {
        // Initialize pointers for binary search
        int left = 0;
        int right = arr.size() - 1;
        
        // Binary search algorithm to find the
        // index of the target value
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If target found, return the index
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // If target not found,
        // return the index for insertion
        return left == arr.size() ? -1 : left;
    }
};

// Better Solution:
// An optimised approach would be to perform an inorder traversal and while performing the inorder traversal, the first value that is encountered at is greater than the key is the inorder successor. In a binary search tree, the nodes are arranged in ascending order during the inorder traversal making it efficient to determine the next node value following a given key.
// Time Complexity: O(N) where N is the number of nodes in the binary search tree. This complexity arises from the fact that we have to traverse all nodes in an inorder fashion to get to the inorder successor.
// Space Complexity: O(1) as no additional data structure or memory allocation is done during the traversal and algorithm. Only a value comparison at each node.
class Solution {
public:
    // Function to find the inorder 
    // successor of a node in a BST
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // Initialize the successor as NULL
        TreeNode* successor = nullptr;
        
        // Traverse the tree until we
        // reach the node or a leaf node
        while (root != nullptr) {
            // If the current node value is
            // greater than the given node 'p'
            if (root->val > p->val) {
                // Update the successor and
                // move to the left subtree
                successor = root;
                root = root->left;
            } else {
                // Move to the right subtree
                root = root->right;
            }
        }
        
        // Return the identified successor
        return successor;
    }
};

// Optimal Approach:
// Up until now, none of the approaches leverage the special properties of a Binary Search Tree. The structure of a BST offers an efficient way to navigate through nodes based on their values. To find an element's successor in a BST, initially set a variable, 'successor,' to null.As we traverse the BST based on whether the node's value is greater or smaller than the given key, we keep track of any value larger than the key. When we encounter a value greater than the key, we update the 'successor' to be the minimum value between the current 'successor' and the encountered value.
// Time Complexity: O(H) where H is the height of the binary search tree as we are traversing along the height of the tree.
// Space Complexity: O(1)as no additional data structure or memory allocation is done during the traversal and algorithm.
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

class Solution{
    public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        TreeNode* successor = nullptr;
        while(root != nullptr){
            if(p -> val >= root -> val){
                root = root -> right;
            }
            else{
                successor = root;
                root = root -> left;
            }
        }
        return successor;
    }
};