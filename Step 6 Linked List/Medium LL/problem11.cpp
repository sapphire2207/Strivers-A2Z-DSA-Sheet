// Problem 11: Sort the LL
// Problem Statement: Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.

// Example 1:
// Input:Linked List: 3 4 2 1 5
// Output:Sorted List: 1 2 3 4 5
// Explanation:  The input linked list when sorted from [3, 4, 2, 1, 5] results in a linked list with values: [1, 2, 3, 4, 5].


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
// A naive solution could be converting the linked list into an array, sorting the array, and then creating a new linked list from the sorted array's values.
// Time Complexity: O(N) + O(N log N) + O(N)where N is the number of nodes in the linked list.
// O(N) to traverse the linked list and store its data values in an additional array.
// O(N log N) to sort the array containing the node values.
// O(N) to traverse the sorted array and convert it into a new linked list.
// Space Complexity : O(N)where N is the number of nodes in the linked list as we have to store the values of all nodes in the linked list in an additional array to sort them.

Node* sortListBrute(Node* head){
    // Create a vector to
    // store node values
    vector<int> arr;
    
    // Temporary pointer to
    // traverse the linked list
    Node* temp = head;
    
    // Traverse the linked list and
    // store node values in the vector
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    
    // Sort the array
    // containing node values
    sort(arr.begin(), arr.end());
    
    // Reassign sorted values to
    // the linked list nodes
    temp = head;
    for(int i = 0; i < arr.size(); i++){
        // Update the node's data
        // with the sorted values
        temp->data = arr[i]; 
        // Move to the next node
        temp = temp->next; 
    }
    
    // Return the head of the
    // sorted linked list
    return head; 
}

// Optimal Approach:
// Instead of using an external array to store node values, we can employ a sorting algorithm without using any extra space. An in-place sorting algorithm like Merge Sort or Quick Sort adapted for linked lists can achieve this.
// A modified version of merge sort can operate directly on the linked list without using any additional space. This algorithm would divide the linked list into halves recursively until single nodes remain. These sorted halves of the linked list are merged back together in a sorted order.
// This approach employs the divide-and-conquer strategy:
// Divides the linked list into smaller parts until they become trivial to sort (single node or empty list).
// Merges and sorts the divided parts while combining them back together.
// Time Complexity: O(N log N)where N is the number of nodes in the linked list. Finding the middle node of the linked list requires traversing it linearly taking O(N) time complexity and to reach the individual nodes of the list, it has to be split log N times (continuously halve the list until we have individual elements).
// Space Complexity : O(1) as no additional data structures or space is allocated for storage during the merging process. However, space proportional to O(log N) stack space is required for the recursive calls. THe maximum recursion depth of log N height is occupied on the call stack.
Node* findMiddleOptimal(Node* head) {
    if(head == NULL || head -> next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = fast -> next -> next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* sortTwoListsOptimal(Node* first, Node* second){
    Node* t1 = first;
    Node* t2 = second;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(t1 != NULL && t2 != NULL){
        if(t1 -> data <= t2 -> data){
            temp -> next = t1;
            temp = t1;
            t1 = t1 -> next;
        }
        else{
            temp -> next = t2;
            temp = t2;
            t2 = t2 -> next;
        }
    }

    if(t1){
        temp -> next = t1;
    }
    else{
        temp -> next = t2;
    }

    return dummyNode -> next;
}

Node* sortListOptimal(Node* head) {
    if(head == NULL || head -> next == NULL) return head;
    Node* middle = findMiddleOptimal(head);
    Node* right = middle -> next;
    middle -> next = NULL;
    Node* left = head;

    left = sortListOptimal(head);
    right = sortListOptimal(right);

    return sortTwoListsOptimal(left, right);
}

int main(){
    vector<int> arr = {2,5,8,7,9};
    Node* head = convertArr2LL(arr);
    head = sortListBrute(head);
    head = sortListOptimal(head);
    print(head);

    return 0;
}