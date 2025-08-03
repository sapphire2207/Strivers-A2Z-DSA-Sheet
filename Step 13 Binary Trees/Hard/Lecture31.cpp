// Amount of Time for Binary Tree to Be Infected

// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
// Each minute, a node becomes infected if:
// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

// Approach:
// Step 1: Store Parent Pointers
// Since a binary tree only has downward pointers (left and right children), we cannot move upwards (to the parent). So, we first perform a level-order traversal (BFS) and store parent pointers in a hash map.
// Step 2: Start BFS from the Given Node
// Now that we can move in all three directions (left, right, and parent), we:
// Use a queue for BFS.
// Maintain a visited set to avoid re-burning nodes.
// Keep track of time taken.
// Step 3: BFS Traversal to Simulate Burning
// We:
// Start with the given node.
// Burn all adjacent nodes (left, right, parent).
// Repeat the process while increasing time at each level.
// TC: O(N) + O(N) + O(NlogN)
// SC: O(N) 

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

    int findMinTime(map<TreeNode*, TreeNode*>& mpp, TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> vis;
        vis[target] = 1;
        int mini = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                if(node -> left && !vis[node -> left]){
                    flag = 1;
                    vis[node -> left] = 1;
                    q.push(node -> left);
                }
                if(node -> right && !vis[node -> right]){
                    flag = 1;
                    vis[node -> right] = 1;
                    q.push(node -> right);
                }
                if(mpp[node] && !vis[mpp[node]]){
                    flag = 1;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            if(flag){
                mini++;
            }
        }
        return mini;
    }

    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*>& mpp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node -> val == start){
                res = node;
            }
            q.pop();
            if(node -> left){
                mpp[node -> left] = node;
                q.push(node -> left);
            }
            if(node -> right){
                mpp[node -> right] = node;
                q.push(node -> right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = bfsToMapParents(root, mpp, start);
        int mini = findMinTime(mpp, target);
        return mini;
    }
};