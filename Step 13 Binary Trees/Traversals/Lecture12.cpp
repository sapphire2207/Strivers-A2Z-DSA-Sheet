// Post-order Traversal of Binary Tree using 1 stack

#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(2N)
// SC: O(N)
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != nullptr || !st.empty()){
            if(curr != nullptr){
                st.push(curr);
                curr = curr -> left;
            }
            else{
                TreeNode* temp = st.top() -> right;
                if(temp == nullptr){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp -> val);
                    while(!st.empty() && temp == st.top() -> right){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp -> val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return postorder;
    }
};