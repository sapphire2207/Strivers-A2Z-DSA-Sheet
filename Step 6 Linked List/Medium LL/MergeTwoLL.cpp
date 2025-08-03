// Problem:
// Merge Two Sorted Linked Lists

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
// Here you are adding the elements of both the lists into a temporary vector and then sort it using a algorithm and then convert the array into a LL
// TC: [O(N) here N = O(n1) + O(n2)]+ O(NLogN) + O(N)
// SC: O(N)
Node* sortTwoListsBrute(Node* first, Node* second){
    vector<int> arr;
    Node* temp1 = first;
    Node* temp2 = second;
    while(temp1 != NULL){
        arr.push_back(temp1 -> data);
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL){
        arr.push_back(temp2 -> data);
        temp2 = temp2 -> next;
    }

    // sort(arr);
    Node* head = convertArr2LL(arr);

    return head;
}

// Optimal Approach:
// First Take two pointers, one at first list, second at the second list, now start comparing the pointers, for the first comparision store the answer using a help of dummy node (create it and then store a temp for moving it), store the answer of the first comparision in the temp -> next 's value, then move the pointer, then again compare the rest of the lists....
// TC: O(N1 + N2)
// SC: O(1)
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

    Node* finalAns = dummyNode -> next;

    free(dummyNode);

    return finalAns;
}

int main(){
    vector<int> arr1 = {2,5,8,7};
    vector<int> arr2 = {3,4,5,9};
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    Node* head = sortTwoListsOptimal(head1, head2);

    print(head);

    return 0;
}