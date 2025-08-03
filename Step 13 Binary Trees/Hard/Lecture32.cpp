// Count Number of Nodes in a Binary Tree

// Problem Statement: Given a Complete Binary Tree, count and return the number of nodes in the given tree. A Complete Binary Tree is a binary tree in which all levels are completely filled, except possibly for the last level, and all nodes are as left as possible.

// Brute Force Approach:
// Complete Binary Tree: A complete binary tree is a binary tree where all levels, except possibly the last one, are completely filled, and the nodes in the last level are as left as possible. Read more about it here: Introduction to Trees
// A brute force approach would be to traverse the tree using inorder (or any) traversal and count the number of nodes as we are traversing the tree. In Inorder traversal, we visit the left subtree first, then the current node, and finally the right subtree. By incrementing the counter for each visited node, we effectively count all nodes in the binary tree.
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
// Space Complexity : O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes. In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).       
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    // Function to perform inorder
    // traversal and count nodes
    void inorder(TreeNode* root, int &count) {
        // Base case: If the current
        // node is NULL, return
        if (root == NULL) {
            return;
        }

        // Increment count
        // for the current node
        count++;

        // Recursively call inorder
        // on the left subtree
        inorder(root->left, count);

        // Recursively call inorder
        // on the right subtree
        inorder(root->right, count);
    }

    // Function to count nodes in the binary tree
    int countNodes(TreeNode* root) {
        // Base case: If the root is NULL,
        // the tree is empty, return 0
        if (root == NULL) {
            return 0;
        }

        // Initialize count variable to
        // store the number of nodes
        int count = 0;

        // Call the inorder traversal
        // function to count nodes
        inorder(root, count);

        // Return the final count of
        // nodes in the binary tree
        return count;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    // Call the countNodes function
    int totalNodes = sol.countNodes(root);

    // Print the result
    cout << "Total number of nodes in the Complete Binary Tree: "
            << totalNodes << endl;
    return 0;
}

// Optimal Approach:
// Given that the binary is a complete binary tree, we can exploit its properties to optimise the algorithm and achieve a better time complexity. In a complete binary tree, the last level may not be completely filled, but the nodes are positioned from left to right. This property allows us to determine the number of nodes using just the height. The relationship between the height of the binary tree (h) and the maximum number of nodes it can have, denoted by the formula: Maximum Number of Nodes: 2^h-1
// If the last level of a binary tree is perfectly filled, known as a perfect binary tree, the count of nodes can be determined by the formula: 2h-1, where h is the height. To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.
// If the left height equals right height, it indicates that the last level is completely filled.
// If the left height does not equal right height, the last level is not completely filled.
// In the case where left height and right height differ, we can employ a recursive approach. We recursively calculate the number of nodes in the left subtree and in the right subtree , and then return the total count as 1 + leftNodes + rightNodes. If the height of the left subtree is equal to the height of the right subtree, we can directly calculate using the 2h-1 formula.
// Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree.
// The calculation of leftHeight and rightHeight takes O(log N) time.
// In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).
// Therefore, the total time complexity is O(log N * log N).
// Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree.
// The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.
// Since the given tree is a complete binary tree, the height will always be log N.
// Therefore, the space complexity is O(log N).                    
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to count nodes
    // in a binary tree
    int countNodes(TreeNode* root) {
        // Base case: If the root
        // is NULL, there are no nodes
        if (root == NULL) {
            return 0;
        }
        
        // Find the left height and
        // right height of the tree
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        
        // Check if the last level
        // is completely filled
        if (lh == rh) {
            // If so, use the formula for
            // total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1 << lh) - 1; 
        }
        
        // If the last level is not completely
        // filled, recursively count nodes in
        // left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Function to find the left height of a tree
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        // Traverse left child until
        // reaching the leftmost leaf
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    // Function to find the right height of a tree
    int findHeightRight(TreeNode* node) {
        int height = 0;
        // Traverse right child until
        // reaching the rightmost leaf
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    // Call the countNodes function
    int totalNodes = sol.countNodes(root);

    // Print the result
    cout << "Total number of nodes in the Complete Binary Tree: "
            << totalNodes << endl;
    return 0;
}