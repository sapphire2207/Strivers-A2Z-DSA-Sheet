// Minimum and Maximum element in BST

// Problem statement
// You are given a Binary Search Tree (BST).
// Find both the minimum and maximum values in it.
// Note:
// All the values in the given BST are unique.

// Example:
// Input: 6 4 7 2 5 N N
// Output:
// Minimum: 2  
// Maximum: 7
// Explanation:
// For the given input, the BST is:

//       6
//      / \
//    4    7
//   / \
//  2   5
// Minimum value in this tree is 2.
// Maximum value in this tree is 7.

// Approach:
// Minimum in BST → keep going leftmost until nullptr.
// Maximum in BST → keep going rightmost until nullptr.
// Return that node’s value.
// Time: O(H), where H = height of tree.
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr){};
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int minVal(Node* root){
	if (root == nullptr) return -1;
    
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data; 
}

int maxVal(Node* root) {
    if (root == nullptr) return -1;

    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}
