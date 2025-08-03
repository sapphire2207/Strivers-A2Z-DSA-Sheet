// Largest BST in Binary Tree

// Problem Statement: Given a Binary Tree, return find the size of the largest subtree that is a Binary Search Tree. Size here refers to the number of nodes in the BST Subtree.

// Brute Force Approach
// A brute force approach for finding the largest Binary Search Tree subtree within a given binary tree would be to traverse each node in the tree and validating whether the subtree rooted at that node conforms to the rules of the BST.
// This can be done by recursively checking each node and its children to enure that the left child’s values are less than the nodes values and the right child’s values are greater than the nodes values.
// Validate a BST is a prerequisite to this question ans is ised as a function call for each node in the tree evaludaitng whether the subtree rooted at the node is a valid BST. Whenever a valid BST is confirmed, the size of that particular subtree is calculated and compared against the current maximum subtree size stored. Ultimately, the global maximum BST subtree size is returned.
// Time Complexity: O(N*N) twhere N is the number of nodes in the Binary Tree. O(N) to traverse through each node in the tree and for each node, the validation ot check whether its subtree is a valid BST takes O(N) time hence the overall time complexity is O(N * N).
// Space Complexity : O(1)as the there no additional space required for storing variables or data structures. The recursive calls for validation can reach a depth of the entire tree’s height hence the auxiliary space can be O(H) for the recursive stack.
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
    // Function to find the size
    // of the largest BST subtree
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        if (isValidBST(root, INT_MIN, INT_MAX)) {
            // If the current node is a valid BST,
            // return the size of the entire subtree
            return countNodes(root);
        } else {
            // If not, explore left and right subtrees
            int left = largestBSTSubtree(root->left);
            int right = largestBSTSubtree(root->right);
            return max(left, right);
        }
    }
    
    // Function to check if a given root is a valid BST
    bool isValidBST(TreeNode* root, int minVal, int maxVal) {
        if (root == nullptr) return true;
        if (root->val >= maxVal || root->val <= minVal) return false;
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
    
    // Function to count the number of  
    // nodes given the root of a subtree
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Optimal Approach
// A more optimised approach would be to traverse the tree and simultaneously check is each subtree is a BST. Utilise a bottom up recursive approach to traverse the tree efficiently.
// For each node the minimum value, maximum value, size of the BST and whether or not it is a BST which the node as root is passed and updated based on its children’s information. In the end, the size of the largest BST subtree found is returned.
// Time Complexity: O(N)where N is the number of nodes in the Binary tree as we traverse through all the nodes in the tree. The information update for each nodes takes constant time hence the overall time complexity is O(N) as the tree is traversed once.
// Space Complexity : O(N) where N is number of nodes in the Binary Tree as for each node we store additional information using a struct class whose new object is initialised. This additional space for variables is proportional to the number of nodes. An additional memory stack space proportional to the height of the Binary Tree O(H) is used by the recursive called to reach the leaf nodes.
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    // Constructor to initialize
    // the NodeValue object
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    // Helper function to find the
    // largest BST subtree recursively
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right
        // subtrees of the current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Check if the current tree is a BST based
        // on its left and right subtrees' properties
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST, update the values for the current tree
            return NodeValue(min(root->val, left.minNode),
                max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        // If the current tree is not a BST,
        // return values indicating invalid tree properties
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    // Function to find the size
    // of the largest BST subtree
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};
