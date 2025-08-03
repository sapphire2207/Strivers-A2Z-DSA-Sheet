// Problem 2:
// Find pairs with given sum in doubly linked list
// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

// Input:  
// 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
// target = 7
// Output: (1, 6), (2,5)
// Explanation: We can see that there are two pairs 
// (1, 6) and (2,5) with sum 7.

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

// Brute Force Method:
// Do linear searching, i.e take a pointer at first (temp1), and take another pointer(temp2) next to it (next to temp1), after that keep on tarversing till both the sum is less, if sum is less and you find a pair then add it to the ans, if not move the pointer (temp1) to next node
// TC: O(N^2)
// SC: O(1) => No extra space used
vector<pair<int,int>> findPairsWithGivenSumBrute(Node* head, int target){
    Node* temp1 = head;
    vector<pair<int,int>> arr;
    while(temp1 != NULL){
        Node* temp2 = temp1 -> next;
        while(temp2 != NULL && temp1 -> data + temp2 -> data <= target){    
            if(temp1 -> data + temp2 -> data == target){
                arr.push_back(make_pair(temp1 -> data, temp2 -> data));
            }
            temp2 = temp2 -> next;
        }
        temp1 = temp1 -> next;
    }
    return arr;
}

// Optimal Solution:
// Firt keep a pointer at the head, another at the tail, now if sum is greater than pointers it means we should decrease the sum, so decrease the right pointer, if the sum is less increase the left pointer.... do this until both pointers don't cross, if they cross break out...., if sum is equal add to the list...
// TC: O(N)
// SC: O(1)
Node* getTail(Node* head){
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        return temp;
    }

vector<pair<int, int>> findPairsWithGivenSumOptimal(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        if(head == NULL) return ans;
        Node* left = head;
        Node* right = getTail(head);
        while(left -> data < right -> data){
            if(left -> data + right -> data == target){
                ans.push_back(make_pair(left -> data, right -> data));
                left = left -> next;
                right = right -> prev;
            }
            else if(left -> data + right -> data < target){
                left = left -> next;
            }
            else{
                right = right -> prev;
            }
        }
        return ans;
    }
int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    print(head);
}