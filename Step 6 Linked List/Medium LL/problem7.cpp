// Problem 7 : Check if the given Linked List is Palindrome
// Example 1:
// Input Format:
// LL: 1  2  3  2  1
// Output: True
// Explanation: A linked list with values "1 2 3 2 1" is a palindrome because its elements read the same from left to right and from right to left, making it symmetrical and mirroring itself.
// Example 2:
// Input Format:
// LL: 1 2 3 3 2 1 
// Output: True
// Explanation: A linked list with values "1 2 3 3 2 1" is a palindrome because it reads the same forwards and backwards.

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


// Brute Force Method:
// A straightforward approach to checking if the given linked list is a palindrome or not is to temporarily store the values in an additional data structure. We can use a stack for this. By pushing each node onto the stack as we traverse the list, we effectively store the data values in the reverse order. Once all the nodes are stored in the stack, we traverse the linked list again comparing each node's value with the values popped from the top of the stack.
// Time Complexity: O(2 * N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.
// Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list. 
bool isPalindromeBrute(Node* head) {
    // Create an empty stack
    // to store values
    stack<int> st;

    // Initialize a temporary pointer
    // to the head of the linked list
    Node* temp = head;

    // Traverse the linked list and
    // push values onto the stack
    while (temp != NULL) {
        
        // Push the data from the
        // current node onto the stack
        st.push(temp->data); 
        
         // Move to the next node
        temp = temp->next;  
    }

    // Reset the temporary pointer back
    // to the head of the linked list
    temp = head;

    // Compare values by popping from the stack
    // and checking against linked list nodes
    while (temp != NULL) {
        if (temp->data != st.top()) {
            
            // If values don't match,
            // it's not a palindrome
            return false; 
        }
        
        // Pop the value from the stack
        st.pop();         
        
        // Move to the next node
        // in the linked list
        temp = temp->next; 
    }

     // If all values match,
     // it's a palindrome
    return true;
}

// Optimal Method:
// The previous approach uses O(N) additional space, which can be avoided by reversing only half of the linked list and comparing the first and second halves. If they match, reverse the portion that was originally reversed, and then return true else return false.
// To implement this in-order reversal of the second half and its comparison with the first half has to be done in phases. The first step is dividing the first and second half of the linked list by recognizing the middle node using the Tortoise and Hare Algorithm.
// Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves. During the first traversal, it reverses one-half of the list, and during the second traversal, it compares the elements of both halves. As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N). 
// Space Complexity: O(1) The approach uses a constant amount of additional space regardless of the size of the input linked list. It doesn't allocate any new data structures that depend on the input size, resulting in a space complexity of O(1).

Node* reverseLinkedList(Node* head) {
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
        // No change is needed;
        // return the current head
        return head; 
    }

    // Recursive step: Reverse the remaining 
    // part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front'
    // to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to
    // point to the current head, effectively
    // reversing the link direction
    front->next = head;

    // Set the 'next' pointer of the
    // current head to 'null' to
    // break the original link
    head->next = NULL;

    // Return the new head obtained
    // from the recursion
    return newHead;
}

bool isPalindromeOptimal(Node* head) {
    // Check if the linked list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
         // It's a palindrome by definition
        return true; 
    }
    
    // Initialize two pointers, slow and fast,
    // to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the linked list to find the
    // middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        
        // Move slow pointer one step at a time
        slow = slow->next;  
        
        // Move fast pointer two steps at a time
        fast = fast->next->next;  
    }
    
    // Reverse the second half of the
    // linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);
    
    // Pointer to the first half
    Node* first = head;  
    
     // Pointer to the reversed second half
    Node* second = newHead; 
    while (second != NULL) {
        
        // Compare data values of 
        // nodes from both halves
        
        // If values do not match,
        // the list is not a palindrome
        if (first->data != second->data) {
            
            // Reverse the second half 
            // back to its original state
            reverseLinkedList(newHead);  
            
            // Not a palindrome
            return false;
        }
        
         // Move the first pointer
        first = first->next; 
        
        // Move the second pointer
        second = second->next;  
    }
    
    // Reverse the second half
    // back to its original state
    reverseLinkedList(newHead);  
    
    // The linked list is a palindrome
    return true;  
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    if (isPalindromeBrute(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    if (isPalindromeOptimal(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}