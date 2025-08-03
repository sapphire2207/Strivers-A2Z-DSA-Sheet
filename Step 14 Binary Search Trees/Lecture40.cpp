// Search in a Binary Search Tree

// Problem Statement: Given a Binary Search Tree and a key value return the node in the BST having data equal to ‘key’ otherwise return nullptr.

// Optimal Approach
// Starting from the root, continuously compare the key value with the current node’s value, traverse to left or right based on these comparisons. If the current node's value matches the target value, the algorithm stops and returns that node. Otherwise, it moves down the tree, choosing the left or right child depending on whether the target value is smaller or larger than the current node's value, respectively. This process continues until either the target value is found within a node or the algorithm reaches a nullptr node, indicating that the value is not present in the BST.
// Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.
// Space Complexity: O(1) since the algorithm does not use any additional space or data structures. The algorithm does use auxiliary stack space from recursion. In the average and worst-case scenarios, the space complexity for recursive stack space is O(h), where 'h' represents the height of the tree.

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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr && root -> val != val){
            root = val < root -> val ? root -> left : root -> right;
        }
        return root;
    }
};