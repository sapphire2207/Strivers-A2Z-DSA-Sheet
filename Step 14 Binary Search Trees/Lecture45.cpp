// Kth Smallest Element in a BST

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Example:
// Input:Binary Search Tree: 5 3 7 1 4 6 8 -1 2, K =3
// Output: 3rd smallest: 3, 3rd largest: 6
// Explanation: All the elements of the BST in the sorted order would be: [1, 2, 3, 4, 5, 6, 7, 8]. From this array is it evident that the index of the Kth smallest element would be K-1 and the index of the Kth largest element would be 1-K or (size of elements) - K. Hence 3rd smallest = 3 and 3rd largest = 6

// Brute Force Approach
// Here we find the inorder traversal of a BST, because it automatically gives you all node values in the ascending sorted order. After this we retrieve the Kth smallest element by accessing the element at index k-1 in the array considering array indices start from 0.
// Here you can use recursive or iterative method....
// TC: O(N)
// SC: O(N)
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node -> val);
                node = node -> right;
            }
        }
        return inorder[k - 1];
    }
};

// Optimal Solution:
// Another way is to maintain a counter variable while doing an inorder traversal... so whenever we visit any middle node we'll increase the counter.... and when we are at the required kth position we can exit.
// TC: O(N)
// SC: O(1)
class Solution {
public:

    void inorder(TreeNode* root, int& counter, int k, int& kthSmallest){
        if(!root || counter >= k) return;
        inorder(root -> left, counter, k, kthSmallest);
        counter++;
        if(counter == k){
            kthSmallest = root -> val;
            return;
        }
        inorder(root -> right, counter, k, kthSmallest);
    }

    int kthSmallest(TreeNode* root, int k) {
        int kthSmallest = INT_MAX;
        int counter = 0;
        inorder(root, counter, k, kthSmallest);
        return kthSmallest;
    }
};

// Similarly try kthLargest