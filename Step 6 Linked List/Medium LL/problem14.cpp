// Problem 14:
// Add 1 to a number represented by LinkedList
// You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

// Example:
// Input: LinkedList: 4->5->6
// Output: 457
// Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 

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
// Here first reverse the LL, then with the help of a carry variable add the reversed LL, if carry is less than 10 it means that you have reached the last node so break out, else store 0 in the node, and atlast if carry is 1 create a new node and add it to the new reversed LL 
// TC: O(3N)
// SC: O(1)
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

Node* addOnetoLLBrute(Node* head){
    Node* reversedHead = reverseLLOptimal(head); // O(N)
    Node* temp = reversedHead;
    int carry = 1;
    // O(N)
    while(temp != NULL){
        temp -> data = temp -> data + carry;
        if(temp -> data < 10){
            carry = 0;
            break;
        }
        else{
            temp -> data = 0;
            carry = 1;
        }
        temp = temp -> next;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        Node* finalReversedHead = reverseLLOptimal(reversedHead);
        newNode -> next = finalReversedHead;
        return newNode;
    }
    Node* finalReversedHead = reverseLLOptimal(reversedHead); // O(N)
    return finalReversedHead;
}

// Optimal Approach:
// Here we use recursion, we use the concept backtracking, we go till the last node, and then add carry 1 to it, based on the answer we return the carry value to the upper nodes.....
// TC: O(N)
// SC: O(N) => recursive stack space
int helper(Node* temp){
    if(temp == NULL){
        return 1; 
    }
    int carry = helper(temp -> next);
    temp -> data = temp -> data + carry;
    if(temp -> data < 10){
        return 0;
    }
    else{
        temp -> data = 0;
        return 1;
    }
}

Node* addOnetoLLOptimal(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode -> next = head;
        return newNode;
    }
    return head;
}


int main(){
    vector<int> arr = {2, 5, 8, 7, 9};
    vector<int> arr = {2, 5, 8, 7, 9};
    Node* head = convertArr2LL(arr);

    return 0;
}