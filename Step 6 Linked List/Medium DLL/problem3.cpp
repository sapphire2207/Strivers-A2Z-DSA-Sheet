// Problem 3: 
// Remove duplicates from a sorted doubly linked list
// Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.
// Input:
// n = 6
// 1<->1<->1<->2<->3<->4
// Output:
// 1<->2<->3<->4
// Explanation:
// Only the first occurance of node with value 1 is 
// retained, rest nodes with value = 1 are deleted.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        prev = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev  = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = prev -> next;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}


// Optimal Approach:
// First put a pointer at the start, now keep a second pointer next to the first one, now keep on moving the second pointer until you reach a position such that both pointers have different values (means you have skipped all the duplicate nodes), now delete the duplicate nodes and make the required link changes, and then again move the pointer forward for further traversal..
// TC: O(N)
// SC: O(1)
// 1<->1<->1<->2<->3<->4<->4
Node* removeDuplicates(struct Node *head){
        Node* temp = head;
        while(temp != NULL && temp -> next != NULL){
            Node* nextNode = temp -> next;
            while(nextNode != NULL && temp -> data == nextNode -> data){
                Node* duplicate = nextNode;
                nextNode = nextNode -> next;
                delete(duplicate);
            }
            temp -> next = nextNode;
            if(nextNode) nextNode -> prev = temp;
            temp = temp -> next;
        }
        return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    print(head);
}