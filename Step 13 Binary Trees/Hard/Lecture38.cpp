// Flatten Binary Tree to Linked List

// Problem Statement: Given a Binary Tree, convert it to a Linked List where the linked list nodes follow the same order as the pre-order traversal of the binary tree.
// Use the right pointer of the Binary Tree as the ‘next’ pointer for the linked list and set the left pointer to null. Do this in place and do not create extra nodes.

// Brute Force:
// The intuition behind this approach is to perform a reverse pre-order traversal where, instead of simply visiting nodes, we flatten the tree into a linked list as we traverse it.
// We start at the root of the tree and recursively do the following for each node, we first ensure that the right subtree is flattened into a linked list. This means that all nodes in the right subtree are processed and attached to the linked list in the correct order.
// Next, we do the same for the left subtree. This ensures that all nodes in the left subtree are processed and attached to the linked list in the correct order. Once both subtrees are flattened, we attach the flattened left subtree as the right child of the current node. Since we're using the right pointer of the binary tree as the next pointer for the linked list, this effectively attaches the left subtree to the current node in the linked list. Finally, we attach the flattened right subtree to the rightmost node of the flattened left subtree. This ensures that the right subtree is properly attached to the end of the linked list.

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

    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        flatten(root -> right);
        flatten(root -> left);
        root -> right = prev;
        root -> left = nullptr;
        prev = root;
    }
};


// Better Solution:
// This approach is an extension of the previous approach where we use a stack to simulate recursion.
// Algorithm
// Step 1: Base Case: If the root node is null, we return as there is no tree to flatten.
// Step 2: Initialise Stack: Create a stack to perform an iterative traversal of the binary tree. Push the root node onto the sack to start the traversal.
// Step 3: Iterative Traversal with Stack: While the stack is not empty, repeat the following steps:
// Pop the top node from the stack.
// If the popped node has a right child, push it onto the stack. This ensures that the right child is processed after the left child nodes.
// If the popped node has a left child, push it onto the stack.
// If the stack is not empty after pushing the left child, connect the right pointer of the current node (popped from the stack) to the top node of the stack. This creates the linked list structure by setting the next pointer.
// Set the left pointer of the current node to null as we have to form a right skewed linked list.
// Step 4: Once the stack becomes empty, the traversal is complete and the binary tree is flattened into a right next linked list structure.
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. Each node of the binary node is visited exactly once. At each node, constant-time operations are performed. Hence the time complexity is O(N).
// Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr -> right != nullptr){
                st.push(curr -> right);
            }
            if(curr -> left != nullptr){
                st.push(curr -> left);
            }

            if(!st.empty()){
                curr -> right = st.top();
            }
            curr -> left = nullptr;
        }
    }
};

// Optimal Approach:
// Morris Traversal is an algorithm that allows preorder/inorder tree traversal without using any extra space for stack or recursion. It utilises threaded binary trees to traverse the tree without requiring a stack for saving the path. Read more about Morris Preorder Traversal here
// Step 1: Start with the current node as the root of the tree.
// Step 2: While the current node is not null we traverse the tree in a while loop:
// If the current node has a left child:
// Find the rightmost node in the left subtree.
// Connect the rightmost node of the left subtree to the current node’s right child.
// Update the current node’s right child to be its left child.
// Set the current node’s left child to null.
// Move to the current node’s right child.
// If the current node has no right child:
// Move to the current node’s left child (if it exists) or null.
// Step 3: Repeat until all nodes are processed.
// Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
// The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
// In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.
// Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.
// Morris Traversal does not use any additional data structures like stacks or recursion, making it an in-place algorithm.
// The only space utilised is for a few auxiliary variables, such as pointers to current and in-order predecessor nodes.

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr -> left){
                TreeNode* prev = curr -> left;
                while(prev -> right){
                    prev = prev -> right;
                }
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = nullptr;
            }
            curr = curr -> right;
        }
    }
};