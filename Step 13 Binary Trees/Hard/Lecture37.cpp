// Morris Inorder Traversal of a Binary tree

// Problem Statement: Given a Binary Tree, implement Morris Inorder Traversal and return the array containing its inorder sequence.
// Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure. The algorithm should efficiently visit each node in the binary tree in inorder sequence, printing or processing the node values as it traverses, without using a stack or recursion.

// Optimal Approach
// Morris Traversal is a tree traversal algorithm that allows for an in-order traversal of a binary tree without using recursion or a stack. It uses threading to traverse the tree efficiently. The key idea is to establish a temporary link between the current node and its in-order successor
// The inorder predecessor of a node is the rightmost node in the left subtree. So when we traverse the left subtree, we encounter a node whose right child is null, this is the last node in that subtree.Hence, we observe a pattern whenever we are at the last node of a subtree such that the right child is pointing to none, we move to the parent of this subtree./p>
// When we are currently at a node, the following cases can arise:
// Case 1: The current node has no left subtree.
// Print the value of the current node.
// Then to the right child of the current node.
// If there is no left subtree, we simply print the value of the current node because there are no nodes to traverse on the left side. After that, we move to the right child to continue the traversal.
// Case 2: There is a left subtree, and the right-most child of this left subtree is pointing to null.
// Set the right-most child of the left subtree to point to the current node.
// Move to the left child of the current node.
// In this case, we haven't visited the left subtree yet. We establish a temporary link from the rightmost node of the left subtree to the current node. This link helps us later to identify when we've completed the in-order traversal of the left subtree. After setting the link, we move to the left child to explore the left subtree.
// Case 3: There is a left subtree, and the right-most child of this left subtree is already pointing to the current node.
// Print the value of the current node.
// Revert the temporary link (set it back to null).
// Move to the right child of the current node.
// This case is crucial for maintaining the integrity of the tree structure. If the right-most child of the left subtree is already pointing to the current node, it means we've completed the in-order traversal of the left subtree. We print the value of the current node and then revert the temporary link to restore the original tree structure. Finally, we move to the right child to continue the traversal.
// Note: The temporary links added in Case 2 are essential for identifying the completion of the left subtree in Case 3. It's critical to revert these links to avoid altering the original structure of the tree.

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr -> left == nullptr){
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                TreeNode* prev = curr -> left;
                while(prev -> right && prev -> right != curr){
                    prev = prev -> right;
                }
                if(prev -> right == nullptr){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                else{
                    prev -> right = nullptr;
                    inorder.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
        return inorder;
    }
};

// Morris Preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure. The algorithm should efficiently visit each node in the binary tree in preorder sequence, printing or processing the node values as it traverses, without using a stack or recursion.

// Optimal Approach
// A prerequisite to this problem is Morris Inorder Traversal of Binary Tree. We extend Morris Inorder Traversal to Preorder Morris Traversal and modify the algorithm to print the current node’s value before moving to the left child when the right child of the inorder predecessor is null.
// This change ensures that the nodes are processed in the desired order for Preorder Traversal. The basic structure of Morris Traversal remains intact, but the printing step is adjusted, resulting in a Preorder Traversal that is still in-place and has a constant space complexity.
// In Morris Inorder Traversal, we are traversing the tree in the way: Left, Root, Right. In Morris Preorder traversal we want to traverse the tree in the way: Root, Left, Right. Therefore, the following code changes are required:
// When the current node has a left child:
// In Morris Inorder Traversal, a new thread is created by establishing a temporary link between the current node and its in-order predecessor. In Morris Preorder Traversal, we want to print the root before visiting the left child. Therefore, after setting the thread (establishing the link), we print the current node's value before moving it to its left child.
// When the current node has no left child:
// This case remains unchanged from Morris Inorder Traversal. If the current node has no left child, there is nothing to visit on the left side. In both Inorder and Preorder traversals, we want to print the current node's value and move to the right child. Therefore, there is no code modification needed for this scenario.
// Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
// The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
// In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.
// Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.
// Morris Traversal does not use any additional data structures like stacks or recursion, making it an in-place algorithm.
// The only space utilised is for a few auxiliary variables, such as pointers to current and in-order predecessor nodes

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr -> left == nullptr){
                preorder.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                TreeNode* prev = curr -> left;
                while(prev -> right && prev -> right != curr){
                    prev = prev -> right;
                }
                if(prev -> right == nullptr){
                    prev -> right = curr;
                    preorder.push_back(curr -> val);
                    curr = curr -> left;
                }
                else{
                    prev -> right = nullptr;
                    curr = curr -> right;
                }
            }
        }
        return preorder;
    }
};