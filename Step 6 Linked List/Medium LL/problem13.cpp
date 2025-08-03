// Problem 13:
// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// Example 1:
// Input:
// List 1 = [1,3,1,2,4], List 2 = [3,2,4]
// Output:
// 2
// Explanation: Here, both lists intersecting nodes start from node 2.

// Example 2:
// Input:
//  List1 = [1,2,7], List 2 = [2,8,1]
// Output:
//  Null
// Explanation: Here, both lists do not intersect and thus no intersection node is present.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    public:
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // mover = mover -> next
    }
    return head;
}

void print(Node *head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

// Brute Force Method:
// In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-
// Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
// Iterate through list 2 and search the hashed value in the hash table. If found, return node.
// Time Complexity: O(n+m)
// Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 
// Space Complexity: O(n)
// Reason: Storing list 1 node addresses in unordered_set.
Node* intersectionPresentBrute(Node* head1,Node* head2) {
    unordered_set<Node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}

// Better Approach:
// We will reduce the search length. This can be done by searching the length of the shorter linked list. How? Let’s see the process.
// Find the length of both lists.
// Find the positive difference between these lengths.
// Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
// Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.
// Time Complexity:
// O(n1) +O(n2) + O(n2 - n1) + O(n1) => O(n1 + 2n2)
// Space Complexity: O(1)
// Reason: No extra space is used.
Node* collisionPoint(Node* t1, Node* t2, int d){
    // O(n1-n2)
    while(d){
        d--;
        t2 = t2 -> next;
    }

    // O(n1)
    while(t1 != t2){
        t1 = t1 -> next;
        t2 = t2 -> next;
    }
    return t1;
}

Node* intersectionPresentBetter(Node* head1, Node* head2){
    // O(n1)
    Node* t1 = head1;
    int length1 = 0;
    while(t1 != NULL){
        length1++;
        t1 = t1 -> next;
    }

    // O(n2)
    Node* t2 = head2;
    int length2 = 0;
    while(t2 != NULL){
        length2++;
        t2 = t2 -> next;
    }
    if(length1 < length2) {
        return collisionPoint(head1, head2, length2 - length1);
    }
    else{
        return collisionPoint(head2, head1, length1 - length2);
    }
}

// Optimal Approach:
// The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-
// Take two dummy nodes for each list. Point each to the head of the lists.
// Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.
// Time Complexity: O(2*max(length of list1,length of list2))
// Reason: Uses the same concept of the difference of lengths of two lists.
// Space Complexity: O(1)
// Reason: No extra data structure is used
Node *intersectionPresentOptimal(Node *headA, Node *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        Node* temp1 = headA;
        Node* temp2 = headB;
        while(temp1 != temp2){
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;

            if(temp1 == temp2) return temp1;
            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
        }
        return temp1;
    }



int main(){
    vector<int> arr = {2, 5, 8, 7, 9};
    vector<int> arr = {2, 5, 8, 7, 9};
    Node* head = convertArr2LL(arr);
    Node* newHead = intersectionPresentBrute(head, head);
    Node* newHead = intersectionPresentBetter(head, head);
    Node* newHead = intersectionPresentOptimal(head, head);
    print(newHead);

    return 0;
}