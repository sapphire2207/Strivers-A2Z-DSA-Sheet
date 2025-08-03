// All Nodes Distance K in Binary Tree

// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
// You can return the answer in any order.

// Approach
// Mark Parent Pointers: Since the tree is directed downward, we store parent references to move upward.
// Breadth-First Search (BFS): We perform BFS from the target node to explore outward in all directions.
// Keep Track of Visited Nodes: This prevents revisiting nodes and ensures correct distance calculation.
// TC: O(N) + O(N) - hashmap O(NlogN)
// SC: O(N) + O(N) + O(N)
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

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current -> left){
                parent_track[current -> left] = current;
                q.push(current -> left);
            }
            if(current -> right){
                parent_track[current -> right] = current;
                q.push(current -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current -> left && !visited[current -> left]){
                    q.push(current -> left);
                    visited[current -> left] = true;
                }
                if(current -> right && !visited[current -> right]){
                    q.push(current -> right);
                    visited[current -> right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front(); 
            q.pop();
            ans.push_back(node -> val);
        }
        return ans;
    }
};