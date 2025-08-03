// Two Sum In BST | Check if there exists a pair with Sum K

// Problem Statement: Given the root of a Binary Search Tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

// Brute Force Approach:
// By getting the inorder traversal of a Binary Search Tree, we get a sorted sequence. On this sorted sequence we can apply the Two Sum problem to return the pair with sum equal to K. This can be done by initialising two pointers at the sequences starts and end, navigating based on their sum compared to the target. This approach leverages the sorted nature of the inorder traversal of a Binary Search Tree.
// Time Complexity: O(N+N) where N is the number of nodes in the Binary Search Tree. To create the array that will store the inorder sequence, we have to traverse the entire BST, hence O(N) and to apply the two pointer approach and get the pair equal to sum again requires O(N) hence O(N+N) ~ O(2N) ~ O(N).
// Space Complexity : O(N)where N is the number of nodes in the BST, as we have to store all the nodes in an additional data structure array. The two pointer approach does not use any additional space hence the space complexity is O(N).
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
    // Function to find if there exists
    // a pair with a given sum in the BST
    bool findTarget(TreeNode* root, int k) {
        // Vector to store in-order traversal of BST
        vector<int> inorder;
        // Get the in-order traversal of the BST
        inorderTraversal(root, inorder);

        // Apply two-pointer approach
        // on the in-order array
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            
            // Calculate sum of elements
            // at left and right pointers
            int sum = inorder[left] + inorder[right];
            if (sum == k) {
                // Pair found
                return true; 
                
            } else if (sum < k) {
                // Increment left pointer
                left++; 
                
            } else {
                // Decrement right pointer
                right--; 
            }
        }
        
        // No pair found
        return false; 
    }

private:
    // Helper function to perform in-order
    // traversal and populate the vector
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (!root) {
            return;
        }
        // Traverse left subtree
        inorderTraversal(root->left, inorder); 
        
        // Push current node's value to vector
        inorder.push_back(root->val); 
        
        // Traverse right subtree
        inorderTraversal(root->right, inorder); 
    }
};

// Optimal Approach:
// The previous approach uses O(N) space complexity which can be eliminated by leveraging the properties of a Binary Search Tree instead. As a prerequisite for this problem, make sure you are thorough with the concepts of Binary Search Tree Iterator. This BSTIterator class allows one to access the next and previous elements (in order predecessor and successor) in a BST.
// Using the BSTIterator class implementation, initialise pointers 'i' and 'j' to the first and last elements of the BST's inorder traversal, respectively. These pointers are navigated through the BST using the next() and before() functions of the BSTIterator. The 'i' pointer progresses towards larger values with next(), while 'j' moves towards smaller values with before(). This approach leverages on the BST properties to efficiently navigate through the elements and identify the pair satisfying the given sum without using any additional data structure to store the inorder traversal.
// Time Complexity: O(N) where N is the number of nodes in the BST as we have to traverse all the nodes using the i and j pointers to find the pair with sum ‘k’.
// Space Complexity : O(H) where H is the height of the Binary Search Tree as the BSTIterator class uses a stack to store the nodes. At maximum the size of such a stack will be equal to the height of the Binary Tree.
class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tempNode -> right);
        else pushAll(tempNode -> left);
        return tempNode -> val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

    private:
    void pushAll(TreeNode* node){
        for(; node != nullptr; ){
            myStack.push(node);
            if(reverse == true){
                node = node -> right;
            }
            else{
                node = node -> left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};