// Problem 4:
// Clone Linked List with Random and Next Pointer
// Problem Statement: Given a linked list where every node in the linked list contains two pointers:
// ‘next’ which points to the next node in the list.
// ‘random’ which points to a random node in the list or ‘null’.
// Create a ‘deep copy’ of the given linked list and return it.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node class to represent
// elements in the linked list
class Node {
public:
    // Data stored in the node
    int data;           
     // Pointer to the next node
    Node *next;        
    // Pointer to a random
    // node in the list
    Node *random;       

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};

// Function to print the cloned linked list
void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

// Brute Force:
// To create a deep copy of the original linked list we can use a map to establish a relationship between original nodes and their copied nodes.
// We traverse the list first to create a copied node for each original node then traverse and establish the correct connections between the copied nodes similar to the arrangement of next and random pointers of the original pointers. In the end, return the head of the copied list obtained from the map.

// Time Complexity: O(2N) where N is the number of nodes in the linked list. The linked list is traversed twice, once for creating copies of each node and for the second time to set the next and random pointers for each copied node. The time to access the nodes in the map is O(1) due to hashing.
// Space Complexity : O(N)+O(N)where N is the number of nodes in the linked list as all nodes are stored in the map to maintain mappings and the copied linked lists takes O(N) space as well.

// Function to clone the linked list
Node *cloneLL(Node *head){
    Node* temp = head;
    // Create an unordered_map to map original
    // nodes to their corresponding copied nodes
    unordered_map<Node*, Node*> mpp;

    // Step 1: Create copies of each node
    // and store them in the map
    while(temp != NULL){
        // Create a new node with the
        // same data as the original node
        Node* newNode = new Node(temp->data);
        // Map the original node to its
        // corresponding copied node in the map
        mpp[temp] = newNode;
        // Move to the next node in the original list
        temp = temp->next;
    }
    
    temp = head;
    // Step 2: Connect the next and random
    // pointers of the copied nodes using the map
    while(temp != NULL){
        // Access the copied node corresponding
        // to the current original node
        Node* copyNode = mpp[temp];
        // Set the next pointer of the copied node
        // to the copied node mapped to the
        // next node in the original list
        copyNode->next = mpp[temp->next];
        // Set the random pointer of the copied node
        // to the copied node mapped to the
        // random node in the original list
        copyNode->random = mpp[temp->random];
        // Move to the next node
        // in the original list
        temp = temp->next;
    }
    
    // Return the head of the
    // deep copied list from the map
    return mpp[head];
}

// Optimal Approach:
// The previous approach uses an extra space complexity of creating mappings between the original and copied nodes. Instead of creating duplicate nodes and storing them in a map, insert it in between the original node and the next node for quick access without the need for additional space.
// Traverse the list again to set the random pointer of copied nodes to the corresponding copied node duplicating the original arrangement. As a final traversal, separate the copied and original nodes by detaching alternate nodes.
// Time Complexity: O(3N)where N is the number of nodes in the linked list. The algorithm makes three traversals of the linked list, once to create copies and insert them between original nodes, then to set the random pointers of the copied nodes to their appropriate copied nodes and then to separate the copied and original nodes.
// Space Complexity : O(N) where N is the number of nodes in the linked list as the only extra additional space allocated it to create the copied list without creating any other additional data structures.

void insertCopyInBetweenHead(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nextElement = temp -> next;
            Node* copyNode = new Node(temp -> data);
            copyNode -> next = nextElement;
            temp -> next = copyNode;
            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = temp -> next;
            if(temp -> random){
                copyNode -> random = temp -> random -> next;
            }
            else{
                copyNode -> random = nullptr;
            }
            temp = temp -> next -> next;
        }
    }

    Node* getDeepCopyList(Node* head){
        Node* dummyNode = new Node(-1);
        Node* result = dummyNode;
        Node* temp = head;
        while(temp != NULL){
            result -> next = temp -> next;
            temp -> next = temp -> next -> next;

            result = result -> next;
            temp = temp -> next;
        }
        return dummyNode -> next;
    }

    Node* copyRandomList(Node* head) {
        insertCopyInBetweenHead(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }

// Main function
int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}

