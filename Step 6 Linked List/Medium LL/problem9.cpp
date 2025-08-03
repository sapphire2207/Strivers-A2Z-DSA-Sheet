// Problem 9:
// Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.

// Example 1:
// Input Format: 5->1->2, N=2
// Result: 5->2
// Explanation: The 2nd node from the end of the linked list is 1. Therefore, we get this result after removing 1 from the linked list.
// Example 2:
// Input Format: 1->2->3->4->5, N=3
// Result: 1->2->4->5
// Explanation: The 3rd node from the end is 3, therefore, we remove 3 from the linked list.

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
// The simplest way to delete the Nth node from the end is to delete the (L-N+1)th node from the start of the linked list, where L is the total length of the linked list. 
// Therefore, this problem can be broken down into two sub-problems:
// The first part involves the calculation of the length of the linked list. You can read about finding the length here.
// The second part involves the deletion of the (L-N+1)th node from the start of the linked list. You can read about the deletion of a node here.
// There are two edge cases to consider:
// If N equals 1, this means we have to delete the tail of the linked list.  You can read about the deletion of the tail here.
// If N equals the length of the linked list, we have to delete the head of the linked list. You can read about the deletion of the head here.
// Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.
// Space Complexity:  O(1), as we have not used any extra space.
Node* DeleteNthNodefromEndBrute(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - N;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

// Optimal Approach:
// The brute force, in the worst case, has a time complexity of O(2*L), where L is the length of the linked list. Therefore, it is not the most efficient algorithm, as we are traversing the entire list twice.
// To enhance efficiency, we will involve two pointers, a fast pointer and a slow pointer. The fast-moving pointer will initially be exactly N nodes ahead of the slow-moving pointer. After which, both of them will move one step at a time. When the fast pointer reaches the last node, i.e., the L-th node, the slow is guaranteed to be at the (L-N)-th node, where L is the total length of the linked list.
// Time Complexity: O(N) since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
// Space Complexity: O(1), as we have not used any extra space.
Node* DeleteNthNodefromEndOptimal(Node* head, int n) {
    Node* fast = head;
    for(int i = 0; i < n ; i++){
        fast = fast -> next;
    }
    Node* slow = head;
    if(fast == NULL) return head -> next;
    while(fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }
    Node* deletionNode = slow -> next;
    slow -> next = slow -> next -> next;
    delete(deletionNode);
    return head;
    }

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    head = DeleteNthNodefromEndBrute(head, 2);
    head = DeleteNthNodefromEndOptimal(head, 2);
    print(head);

    return 0;
}