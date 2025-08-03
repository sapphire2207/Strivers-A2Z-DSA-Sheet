// Problem 1:-
// Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

// Naive Approach:-
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


// Approach:
// Using the brute force approach, we can find the middle node of a linked list by traversing the linked list and finding the total number of nodes as `count`. Then we reset the traversal pointer and traverse to the node at the [count/2 + 1]th position. That will be the middle node.
// TC:- O(N+N/2) 
// SC:- O(1)
Node* middleNodeUsingNaive(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    int middleNode = (count/2) + 1;
    Node* temp = head;
    while(temp != NULL){
        middleNode = middleNode - 1;
        if(middleNode == 0){
            break;
        }
        temp = temp -> next;
    }
    return temp;
}

// Approach:
// The previous method requires the traversal of the linked list twice. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization where the middle node can be found in just one traversal. The Tortoise and Hare algorithm leverages two pointers, 'slow' and 'fast', initiated at the beginning of the linked list. The 'slow' pointer advances one node at a time, while the 'fast' pointer moves two nodes at a time.
// Intution: 
// Imagine a person p1 is travelling at a speed of x, and the person p2 is travelling at a speed of x/2, so if p1 covers a distance of d, then it's obvious that p2 has covered at a distance of d/2. So in the similar way, the fast pointer travels twice the speed of slow pointer..... hence when fast pointer reaches the end, the slow pointer would have exactly covered the half of the fast's distance...
// TC:- O(N/2)
// SC:- O(1)
Node* middleNodeUsingOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast -> next != NULL && fast != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2LL(arr);

    Node* middleNode = middleNodeUsingNaive(head);
    cout << "The middle Node value is: " << middleNode -> data << endl;
    Node* middleNode = middleNodeUsingOptimal(head);
    cout << "The middle Node value is: " << middleNode -> data << endl;
    return 0;
}

