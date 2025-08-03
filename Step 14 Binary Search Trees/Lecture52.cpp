// Recover BST | Correct BST with Two Nodes Swapped

// Problem Statement: GIven the root of a Binary Search Tree (BST), where the values of exactly two nodes of the BST have been swapped. Recover the tree without changing its structure.

// Brute Force Approach:
// Perform an inorder traversal of the BST to gather the node values in an array. Sort this array to get the corrected inorder traversal of the BST, this traversal has the correct node positions of the swapped nodes.
// Traverse the BST in inorder again while comparing each node’s values with the corresponding index from the sorted inorder array. At positions where the mismatch occurs, update the tree with the correct values from the sorted array, effectively fixing the swaps without altering the tree’s structure.
// Time Complexity: O(2N + N log N) This is because O(N) for obtaining the traversal then O(N logN) for sorting the traversal and another O(N) traversal to compare and correct the swaps resulting in O( N + NlogN + N) ~ O(2N + NlogN).
// Space Complexity : O(N) for storing the traversal in an auxiliary data structure and extra recursion space for getting the inorder traversal.
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
    private:
        // Function to store the inorder traversal
        void inorder(TreeNode* root, vector<int>& values) {
            if (root == nullptr) return;
            inorder(root->left, values);
            values.push_back(root->val);
            inorder(root->right, values);
    }
    public:
        void recoverTree(TreeNode* root) {
            vector<int> sortedVals;
            // Perform an inorder traversal
            // to obtain values in sorted order
            inorder(root, sortedVals);
        
            // Sort the obtained values to
            // get the corrected inorder traversal
            sort(sortedVals.begin(), sortedVals.end());
            
            // Initialize pointers for tree
            // traversal and sortedVals array
            TreeNode* current = root;
            int index = 0;
        
            // Morris Traversal to traverse the
            // tree without recursion or stack
            while (current != nullptr) {
                // If there is no left subtree
                if (current->left == nullptr) {
                    // Compare the current node's
                    // value with the sortedVals array
                    if (current->val != sortedVals[index]) {
                        // Update the current node's
                        // value if there's a mismatch
                        current->val = sortedVals[index];
                    }
                    ++index;
                    // Move to the right subtree
                    current = current->right;
                } else {
                    // Find the predecessor of the current node
                    TreeNode* predecessor = current->left;
                    while (predecessor->right != nullptr && predecessor->right != current) {
                        predecessor = predecessor->right;
                    }
        
                    // If the right pointer of
                    // predecessor is not set
                    if (predecessor->right == nullptr) {
                        // Set the threaded pointer
                        // to the current node
                        predecessor->right = current;
                        // Move to the left subtree
                        current = current->left;
                    } else {
                        // Revert threaded
                        // pointer back to nullptr
                        predecessor->right = nullptr;
                        
                        // Compare the current node's
                        // value with the sortedVals array
                        
                        if (current->val != sortedVals[index]) {
                            // Update the current node's
                            // value if there's a mismatch
                            current->val = sortedVals[index];
                        }
                        ++index;
                        // Move to the right subtree
                        current = current->right;
                    }
                }
            }
        }
};

// Optimal Approach:
// The inorder traversal of a Binary Search Tree which results in a sorted sequence. However due to the swapped elements, the sorted order is disrupted by these misplaced nodes. While traversing the tree, we keep a track of the previous and next node to each visited node. As we identify nodes that violate the sorted order we store them.
// By tracking these violations and handling the cases where the swapped nodes could be adjacent or non-adjacent, the algorithm can effectively pinpoint the two nodes that are out of place.
// Time Complexity: O(N) where N is the number of nodes in the Binary Search Tree as the algorithm involves performing an inorder traversal to identify the swapped nodes.
// Space Complexity : O(1) as only the algorithm maintains a constant number of pointers to track the nodes during traversal. The algorithm doesn’t use any additional data structures that scale with the input size or the number of nodes in the tree.
class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

public:

    void inorder(TreeNode* root){
        if(root == nullptr) return;

        inorder(root -> left);

        if(prev != nullptr && (root -> val < prev -> val)){
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }

        prev = root;
        inorder(root -> right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first -> val, last -> val);
        else if(first && middle) swap(first -> val, middle -> val);
    }
};