// Problem 10:
// Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

// Example 1:
// Input Format:
// LL: 1  2  3  4  5 
// Output: 1 2 4 5
// Explanation: Node with value 3 is at the middle node and deleted.
// Example 2:
// Input Format:
// LL: 1  2  3  4
// Output: 1 2 4
// Explanation: In this example, the linked list has an even number of nodes hence we return the second middle node which is 3.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp; // mover = mover -> next
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

// Brute Force:
// Using the brute force approach, the middle node of a linked list can be determined by traversing the entire linked list initially to find the total number of nodes, denoted as `n`. Then we reset the temporary node `temp` to the head of the linked list and proceed to traverse to the node positioned at index `[n/2]`, which represents either the middle node in an odd-lengthed list or the node just before the middle node in an even-lengthed linked list.
// Time Complexity: O(N + N/2) The loop traverses the entire linked list once to count the total number of nodes then the loop iterates halfway through the linked list to reach the middle node. Hence, the time complexity is O(N + N/2) ~ O(N).
// Space Complexity : O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 

Node* deleteMiddleBrute(Node* head){
    // Initialize a temporary node
    // to traverse the linked list
    Node* temp = head;
    
    // Variable to hold the number
    // of nodes in the linked list
    int n = 0;
    
    // Loop to count the number of
    // nodes in the linked list
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    
    // Calculate the index of the middle node
    int res = n/2;
    
    // Reset the temporary node to
    // the beginning of the linked list
    temp = head;
    
    // Loop to find the
    // middle node to delete
    while(temp!=NULL){
        
        res--;
        
        // If the middle node is found
        if(res==0){
            
            // Create a pointer
            // to the middle node
            Node* middle = temp->next;
            
            // Adjust pointers to
            // skip the middle node
            temp->next = temp->next->next;
            
            // Free the memory allocated
            // to the middle node
            free(middle);
            
            // Exit the loop after
            // deleting the middle node
            break;
        }
        // Move to the next node
        // in the linked list
        temp = temp->next;
    }
    // Return the head of the
    // modified linked list
    return head;
}

// Optimal Approach:
// The previous method requires the traversal of the linked list twice. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization where the middle node can be found in just one traversal.
// The 'slow' pointer advances one node at a time while the 'fast' pointer moves two nodes at a time. By doing so, when the 'fast' pointer reaches the end of the list, the 'slow' pointer will be at the middle node.
// Since we require `slow` to reach the node before the middle node, we give `fast` a head start!
// Time Complexity: O(N/2) The algorithm traverses the linked list using the Tortoise and Hare approach. The code increments both 'slow' and 'fast' pointers at different rates, effectively covering about half the list before reaching the midpoint, hence the time complexity of the algorithm is O(N/2) ~ O(N).
// Space Complexity: O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 

Node* deleteMiddleOptimal(Node* head) {
    if(head == NULL || head -> next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = fast -> next -> next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node* middleNode = slow -> next;
    slow -> next = slow -> next -> next;
    delete(middleNode);
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7,9};
    Node* head = convertArr2LL(arr);
    head = deleteMiddleBrute(head);
    head = deleteMiddleOptimal(head);
    print(head);

    return 0;
}