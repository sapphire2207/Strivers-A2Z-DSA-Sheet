// Problem 4:-
// Detect a cycle in a Linked List:

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

// Approach:
// it's important to keep track of nodes that have already been visited so that loops can be detected. One common way to do this is by using hashing.
// Note: Storing the entire node in the map is essential to distinguish between nodes with identical values but different positions in the list. This ensures accurate loop detection and not just duplicate value checks.
// TC:- O(N * 2 * log(N) )The algorithm traverses the linked list once, performing hashmap insertions and searches in the while loop for each node. The insertion and search operations in the unordered_map have a worst-case time complexity of O(log(N)). As the loop iterates through N nodes, the total time complexity is determined by the product of the traversal (O(N)) and the average-case complexity of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)). 
// SC:- O(N)
bool detectCycleBrute(Node* head){
    Node* temp = head;
    std::unordered_map<Node*,int> mpp;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        mpp[temp] = 1;
        temp = temp -> next;
    }
    return false;
}

// Optimal Method:
// Tortoise and Hare Algorithm
// In a linked list with a loop, consider two pointers: one that moves one node at a time (slow) and another that moves two nodes at a time (fast). If we start moving these pointers with their defined speed they will surely enter the loop and might be at some distance 'd' from each other within the loop.
// The key insight here is the relative speed between these pointers. The fast pointer, moving at double the speed of the slow one, closes the gap between them by one node in every iteration. This means that with each step, the distance decreases by one node.
// Imagine a race where one runner moves at twice the speed of another. The faster runner covers the ground faster and closes the gap, resulting in a reduction in the distance between them. Similarly, the fast pointer catches up to the slow pointer in the looped linked list, closing in the gap between them until it reaches zero.
// The relative speed between them causes the gap to decrease by one node in each iteration (fast gains two nodes while slow gains one node). This continuous reduction ensures that the difference between their positions decreases steadily. Mathematically, if the fast pointer gains ground twice as fast as the slow pointer, the difference in their positions reduces by one node after each step. Consequently, this reduction in the distance between them continues until the difference becomes zero.
// Hence, the proof lies in this iterative process where the faster rate of the fast pointer leads to a continual decrease in the gap distance, ultimately resulting in their collision within the looped linked list.
// Intution:
// Now In any loop and there are slow and fast pointers inside it....
// So at the present moment.... the distance between fast and slow is x,
// And the next moment... the distance between fast and slow will be x-1, because since fast is moving towards slow by 2... and slow is moving away from fast by 1.... the net reduction boils down to x-1... and at a moment it will be zero... where they meet
// TC:- O(N)
// SC:- O(1)
bool detectCycleOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return true;
        }
    }
    return false;
    
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    print(head);
    return 0;
}