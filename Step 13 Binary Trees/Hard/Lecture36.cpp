// Serialize And Deserialize a Binary Tree

// Problem Statement: Given a Binary Tree, design an algorithm to serialise and deserialise it. There is no restriction on how the serialisation and deserialization takes place. But it needs to be ensured that the serialised binary tree can be deserialized to the original tree structure. Serialisation is the process of translating a data structure or object state into a format that can be stored or transmitted (for example, across a computer network) and reconstructed later. The opposite operation, that is, extracting a data structure from stored information, is deserialization.

// ### Optimal Approach
// Serialisation:
// Dequeue a node from the queue.
// If the node is null, append "#" to the string.
// If the node is not null, append its data value along with a ‘,’ (comma) to the string. This comma acts as a delimiter that separates the different node values in the string. Enqueue its left and right children.

// Deserialization:
// Dequeue a node from the queue.
// Read the value for the left child from the stringstream.
// If it is "#", set the left child to null. If it's not "#", create a new node with the value and set it as the left child.
// Read the next value in the stringstream for the right child.
// If it is "#", set the right child to null. If it's not "#", create a new node with the value and set it as the right child.
// Enqueue the left and right children into the queue for further traversal.
// Time Complexity: O(N)
// serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.
// deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.
// Space Complexity: O(N)
// serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.
// deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode == nullptr) s.append("#,");
            else s.append(to_string(currNode -> val) + ",");
            if(currNode != nullptr){
                q.push(currNode -> left);
                q.push(currNode -> right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node -> left = nullptr;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node -> left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                node -> right = nullptr;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node -> right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));