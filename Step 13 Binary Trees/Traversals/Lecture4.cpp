// Binary Tree Traversal : Inorder Preorder Postorder

// Traversals in hierarchical data structures like Binary Trees can be broadly classified into two categories: Depth-First Search (DFS) and Breadth-First Search (BFS). Each of them utilises a different strategy to visit the nodes within the tree.

// Depth-First Search (DFS) explores a binary tree by going as deeply as possible along each branch before backtracking.
// It starts from the root and explores as deeply as possible along each branch, visiting nodes until it reaches a leaf node. It then backtracks to the most recent unexplored node and continues until all nodes are visited.
// The order in which we visit a node determines if that traversal would be preorder, inorder and postorder.
// DFS uses recursion or a stack to traverse deeper levels of the tree before visiting nodes at the same level.

// Breadth-First Search (BFS) explores a binary tree level by level, visiting all nodes at a given level before processing to the next level.
// It starts from the root and visits all nodes at level 0, then proceeds to level 1, level 2, and so on. Nodes at a level are visited from left to right.
// BFS uses a queue data structure to maintain nodes at each level, ensuring that nodes at higher levels are visited moving to lower levels.

// Inorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Root, Right.
// It's named "inorder" because it traverses the nodes in a sequence where the "Visit" step occurs between the left and right child nodes.
// Procedure of Inorder Traversal:
// Visit the Left Subtree: Recursively traverse the left subtree until a leaf node or a node with no left child is reached.
// Visit the Current Node: Once at a node, perform the visitation operation (such as printing the node's value or performing an operation with the node's data).
// Traverse the Right Subtree: After visiting the current node, recursively traverse the right subtree, following the same steps as the left subtree.

// Preorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Root, Left then Right.
// It's named "preorder" because the "Visit" step occurs before traversing the left and right child nodes.
// Procedure of Preorder Traversal:
// Visit the Current Node: Begin by visiting the current node, performing the visitation operation (such as printing the node's value or performing an operation with the node's data).
// Traverse the Left Subtree: Recursively traverse the left subtree, following the same steps starting from step 1.
// Traverse the Right Subtree: After fully traversing the left subtree, recursively traverse the right subtree, following the same steps starting from step 1.


// Postorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Right then Root.
// It's named "postorder" because the "Visit" step occurs after traversing the left and right child nodes.
// Procedure of Postorder Traversal:
// Traverse the Left Subtree: Recursively traverse the left subtree, following the same steps starting from step 1.
// Traverse the Right Subtree: Similarly, recursively traverse the right subtree, following the same steps starting from step 1.
// Visit the Current Node: After fully traversing both left and right subtrees, visit the current node, performing the visitation operation (such as printing the node's value or performing an operation with the node's data).