// Insert into a Binary Search Tree

// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST. Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

// Example:
// Input: root = [4,2,7,1,3], val = 5
// Output: [4,2,7,1,3,5]

// Optimal Approach:
// The simple approach is to find where it can be placed and insert it.
// And here the "where" will always be a leaf node.
// TC: O(log2N)
// SC: O(1)

// Definition for a binary tree node.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* curr = root;
        while(true){
            if(curr -> val <= val){
                if(curr -> right != nullptr){
                    curr = curr -> right;
                }
                else{
                    curr -> right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr -> left != nullptr){
                    curr = curr -> left;
                }
                else{
                    curr -> left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};