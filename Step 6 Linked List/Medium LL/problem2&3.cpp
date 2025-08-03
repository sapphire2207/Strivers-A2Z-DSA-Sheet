// Problem 2:-
// Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

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
        cout << head -> data <<" ";
        head = head -> next;
    }
    cout << endl;
}


// Brute Force Method:
// By swapping the data inside the nodes with help of a STACK data structure
// A straightforward approach to reversing a singly linked list requires an additional data structure to temporarily store the values. We can use a stack for this. By pushing each node onto the stack as we move through the list, we effectively reverse the order of the nodes. Once all the nodes are stored in the stack, we rebuild the reversed linked list by popping nodes from the stack and assigning them to the nodes. The result is a new linked list with the elements in the opposite order of the original list.
// TC:- O(N) + O(N)
// SC:- O(N)
Node* reverseLLBrute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp -> data);
        temp = temp -> data;
    }

    Node* temp = head;
    while(temp != NULL){
        temp -> data = st.top();
        st.pop();
        temp = temp -> data;
    }
    return head;
}

// Optimal Method:
// By swapping the pointers
// The main idea is to flip the order of connections in the linked list, which changes the direction of the arrows. When this happens, the last element becomes the new first element of the list. This in-place reversal allows us to efficiently transform the original list without using extra space.
// TC:- O(N)
// SC:- O(1)
Node* reverseLLOptimal(Node* head){
    Node* temp = head;
    Node* prevNode = NULL;
    while(temp != NULL){
        Node* frontNode = temp -> next;
        temp -> next = prevNode;
        prevNode = temp;
        temp = frontNode;
    }
    return prevNode;
}

// Using Recursive Method:
// In this case, tackling the larger problem involves reversing a linked list with N = 4 nodes. Recursion allows us to break this task down into progressively smaller subproblems, starting with the case of 3 nodes, then the last 2 nodes, and ultimately reaching the base case where only 1 node remains. In the base case, reversing the linked list is straightforward, as a list with just one node is already in its reversed form, and we can simply return it as is.
// Base Case: Check if the linked list is empty or contains only one node. Return the head as it's already reversed in these cases.
// Recursive Function: The core of the algorithm lies in implementing a recursive function responsible for reversing the linked list. This function operates based on the following principle: If the base case conditions are not met, the function invokes itself recursively. This recursion continues until it reaches the base case, gradually reversing the linked list starting from the second node (node after it) onward.
// Return: Following the recursion, the function returns the new head of the reversed linked list. This head marks the last node of the original list before reversal, now the first node in the reversed sequence.
// TC:- O(N)
// SC:- O(N)
Node* reverseLLRecursion(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* newHead = reverseLLRecursion(head -> next);
    Node* frontNode = head -> next;
    frontNode -> next = head;
    head -> next = NULL;
    return newHead;
} 

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    Node* head = reverseLLBrute(head);
    Node* head = reverseLLOptimal(head);
    Node* head = reverseLLRecursion(head);
    print(head);
    return 0;
}