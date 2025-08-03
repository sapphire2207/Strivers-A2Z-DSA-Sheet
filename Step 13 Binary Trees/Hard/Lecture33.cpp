// Unique Binary Tree Requirements

// Geek wants to know the traversals required to construct a unique binary tree. Given a pair of traversal, return true if it is possible to construct unique binary tree from the given traversals otherwise return false.
// Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.   

// Case 1:
// If you are given two traversals of preorder and postorder, can you create a unique binary tree with them?
// The answer is no, because there are chances that there may be a couple of new trees, but you won't get unique ones.
// It's basically because, you are not aware of the left and right positions of a particular node... leading to many possible binary trees.

// Case 2:
// If you are given two traversals of preorder / postorder and inorder, can you create a unique binary tree with them?
// The answer is yes, because the inorder traversal let's you know about it's left and right elements of a particular node, and as you take elements from preorder / postorder you get an idea of the following elements in the front....

// So the main idea is, while constructing a tree you need to know it's left and right children, so it's compulsory to have an inorder traversal to create a unique binary tree.