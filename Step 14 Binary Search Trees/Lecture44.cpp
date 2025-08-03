// Delete Node in a BST

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.
// Example:
// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.

// Optimal Solution:
// Here first traverse till the node above the node which has to be deleted (so that we can attach any sub tree to it's node above making it a valid tree)
// Now you can solve this in two ways....
// 1) By taking the left sub tree and joining it with the node above + joining the right leaf node of left sub tree with the right child of the node to be deleted.
// 2) By taking the right sub tree and joining it with the node above + joining the deleted node's first left node to the left leaf node of the right sub tree.
// TC: O(Log2N)
// SC: O(1)
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }

        if(root -> val == key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root != nullptr){
            if(root -> val > key){
                if(root -> left != nullptr && root -> left -> val == key){
                    root -> left = helper(root -> left);
                    break;
                }
                else{
                    root = root -> left;
                }
            }
            else{
                if(root -> right != nullptr && root -> right -> val == key){
                    root -> right = helper(root -> right);
                }
                else{
                    root = root -> right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root -> left == nullptr){
            return root -> right;
        }
        if(root -> right == nullptr){
            return root -> left;
        }
        TreeNode* rightChild = root -> right;
        TreeNode* leftSubTreeLastRight = findLastRightInLeftSubTree(root -> left);
        leftSubTreeLastRight -> right = rightChild;
        return root -> left;
    }

    TreeNode* findLastRightInLeftSubTree(TreeNode* root){
        if(root -> right == nullptr){
            return root;
        }
        return findLastRightInLeftSubTree(root -> right);
    }
};