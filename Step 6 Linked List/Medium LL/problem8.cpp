// Problem 8:
// Problem Statement : Segregate even and odd nodes in LinkedList
// Given a LinkedList of integers. Modify the LinkedList in such a way that in Modified LinkedList all the even numbers appear before all the odd numbers in LinkedList.
// Also, note that the order of even and odd numbers should remain the same. 
// Example 1:
// Input: 1→2→3→4→5→6→Null
// Output: 2→4→6→1→3→5→Null
// Explanation : 
// Odd Nodes in LinkedList are 1,3,5 and 
// Even Nodes in LinkedList are 2,4,6
// In Modified LinkedList all even Nodes comes before 
// all Odd Nodes. So Modified LinkedList looks like 
// 2→4→6→1→3→5→Null. Order of even and odd Nodes is 
// maintained in modified LinkedList.


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
// Here first you add the odd nodes into a temporary vector, then add the even nodes into the temporary vector by keeping in mind of the edge cases, after that reassign the values in the linked list which you have stored in the temporary vector
// TC: O(N/2 *2) + O(N) = O(2N)
// SC: O(N)
Node* oddEvenListBrute(Node* head){
    vector<int> arr;
    Node* temp = head;

    if(head == NULL || head -> next == NULL) return head;
    while(temp != NULL && temp -> next != NULL){
        arr.push_back(temp -> data);
        temp = temp -> next -> next;
    }
    if(temp) {
        arr.push_back(temp -> data);
    }

    Node* temp = head -> next;
    while(temp != NULL && temp -> next != NULL){
        arr.push_back(temp -> data);
        temp = temp -> next -> next;
    }
    if(temp) {
        arr.push_back(temp -> data);
    }

    int i = 0;
    Node* temp = head;
    while(temp != NULL){
        temp -> data = arr[i];
        i++;
        temp = temp -> next;
    }

    return head;
}


// Optimal Approach:
// The Intuition is to Split the LinkedList into two parts. One Contains all the Even Nodes and the other contains all the Odd Ends. After obtaining two LinkedLists we attach odd LinkedList at the end of the Even LinkedList.
// To split the LinkedList take two dummy Nodes which act as the Heads of the odd and Even LinkedList. Traverse the original LinkedList. While traversing if the Node is odd remove the Node from the original LinkedList and add to odd LinkedList. Similarly for the Even Node too.
// After Traversing we obtain two LinkedList with all odd and all Even Nodes. Attach odd LinkedList at the end of Even LinkedList. As we are appending nodes to Odd and Even LinkedLists one by one the order of Nodes is undisturbed. 
// Time Complexity: O(N) N is the number of Nodes in LinkedList. As we are traversing LinkedList once.
// Space Complexity: O(1) We are just Manipulating the Links, not using any extra space.
Node* oddEvenListOptimal(Node* head) {
        Node* odd = head;
        Node* even = head -> next;
        Node* evenHead = head -> next;
        while(even != nullptr && even -> next != nullptr){
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;

            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = evenHead;
        return head;
    }



int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    head = oddEvenListOptimal(head);
    print(head);

    return 0;
}