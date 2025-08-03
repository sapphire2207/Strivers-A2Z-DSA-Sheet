// Problem 6:-
// Finding the length of a loop in a Linked List

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

// Brute Force Method:
// While traversing the linked list, employ a timer against each node to keep track of the number of nodes you've visited before it. Once a previously visited node is encountered again, the length of the loop can be determined by subtracting the timer values at the two instances of visiting that particular node.
// Hence it's important to keep track of nodes and the timer value associated with them. This can be implemented using a hashmap with nodes as the key and the timer as the value.
// TC:- O(N * 2 * log(N) )The algorithm traverses the linked list once, performing hashmap insertions and searches in the while loop for each node. The insertion and search operations in the unordered_map have a worst-case time complexity of O(log(N)). As the loop iterates through N nodes, the total time complexity is determined by the product of the traversal (O(N)) and the average-case complexity of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)). 
// SC:- O(N)
int findLengthofLoopBrute(vector<int>& arr, Node* head){
    Node* temp = head;
    int value = 0;
    int timer = 1;
    unordered_map<Node*, int> mpp;

    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            value = mpp[temp];
            return (timer - value);
        }
        mpp[temp] = timer;
        timer++;
        temp = temp -> next;
    }
    return 0;
}

// Optimal Method:
// Tortoise and Hare Algorithm
// Approach:
// Step 1: Initialise two pointers, `slow` and `fast`, to the head of the linked list. `slow` will advance one step at a time, while `fast` will advance two steps at a time. These pointers will move simultaneously.
// Step 2: Traverse the linked list with the `slow` and `fast` pointers. While traversing, repeatedly move `slow` one step and `fast` two steps at a time.
// Step 3: Continue this traversal until one of the following conditions is met:
// `fast` or `fast.next` reaches the end of the linked list (i.e., becomes null). In this case, there is no loop in the linked list hence it is linear, and the algorithm terminates by returning 0.
// `fast` and `slow` pointers meet at the same node. This indicates the presence of a loop in the linked list as we have seen in the detection of loop.
// This is the point where the slow and fast have met proving that there is a loop in the linked list. From here onwards we start counting for the length of this loop.
// Step 4: Initialise a counter with zero and traverse the linked list using the `fast` pointer again, but this time only move one step at a time while incrementing the counter with each node visited. As the fast pointer reaches back at the slow pointer, the value of the counter will represent the length of the loop.
// TC:- O(N)
// SC:- O(1)

int findLength(Node* slow, Node* fast){
    int count = 1;
    fast = fast -> next;
    while(slow != fast){
        count++;
        fast = fast -> next;
    }
    return count;
}

int findLengthofLoopOptimall(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != NULL && fast != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return findLength(slow, fast);
        }
    }
    return NULL;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    int length1 = findLengthofLoopBrute(arr,head);
    int length2 = findLengthofLoopOptimall(head);
    print(head);

    return 0;
}