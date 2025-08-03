// Problem 5:-
//  Given the head of a linked list that may contain a cycle, return the starting point of that cycle. If there is no cycle in the linked list return null.

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

// Brute Force Method Using Hashing
// The starting point of a loop of the linked list is the first node we visit twice during its traversal. It's the point where we realise that we are no longer moving forward in the list but rather entering a cycle.
// TC:- O(N)
// SC:- O(N)
Node* findStartingNodeinLoopBrute(Node* head){
    Node* temp = head;
    unordered_map<Node*, int> mpp;

    while(temp != NULL){
        if(mpp.count(temp) != 0){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp -> next;
    }
    return NULL;
}

// Optimal Method:
// Tortoise and Hare Algorithm
// Intution:
// In the "tortoise and hare" algorithm for detecting loops in a linked list, when the slow pointer (tortoise) reaches the starting point of the loop, the fast pointer (hare) is positioned at a point that is twice the distance travelled by the slow pointer. This is because the hare moves at double the speed of the tortoise.
// If slow has travelled distance L1 then fast has travelled 2 x L1. Now that slow and fast have entered the loop, the distance fast will have to cover to catch up to slow is the total length of loop minus L1. Let this distance be d.
//                             Distance travelled by slow = L1
//                             Distance travelled by fast = 2 * L1
//                             Total length of loop = L1 + d
// In this configuration, the fast pointer advances toward the slow pointer with two jumps per step, while the slow pointer moves away with one jump per step. As a result, the gap between them decreases by 1 with each step. Given that the initial gap is d, it takes exactly d steps for them to meet.
//                             Total length of loop = L1 + d
//                             Distance between slow and fast= d
// During these d steps, the slow pointer effectively travels d steps from the starting point within the loop and fast travels 2 x d and they meet a specific point. Based on our previous calculations, the total length of the loop is L1 + d. And since the distance covered by the slow pointer within the loop is d, the remaining distance within the loop is equal to L1.
// Therefore, it is proven that the distance between the starting point of the loop and the point where the two pointers meet is indeed equal to the distance between the starting point and head of the linked list.
// Intution:
// Normally while iterating the slow pointer will be at the starting point of that cycle... so means it has covered a distance of L1... then it also means that the fast pointer is ahead of slow by a distance of L1....
// Now since the distance between fast and slow pointers is d.... then in the next iteration the d reduces by 1.... So after few iterations both the pointers meet at a point... (lenth of loop is l1 + d)
// Since the difference became zero.... (initially it was d)... it means that the slow pointer took d steps to reach fast and the fast pointer took 2d steps to reach the slow pointer making the net reduction zero....
// Now when the slow was initially at the starting point of that cycle, it took d steps to reach the collision point.. so the distance remaining between collision and slow is L1... and the distance from start of the LL to the starting point is also L1.... hence they meet...
// TC:- O(N)
// SC:- O(1)
Node* findStartingNodeinLoopOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != NULL && fast != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    head = findStartingNodeinLoopBrute(head);
    head = findStartingNodeinLoopOptimal(head);
    print(head);

    return 0;
}