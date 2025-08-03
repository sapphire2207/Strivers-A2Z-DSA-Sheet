// Linked List:-

// Creation of a Linked List:
#include<bits/stdc++.h>
using namespace std;

// You can define it as struct / class, bcz struct doesn't offer you the OOPs concepts, but using a class solves the problem
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // The above thing can also be done like this:
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {2,5,8,7};
    Node* y = new Node(arr[0], nullptr);
    cout << y; // Gives you address of the node created
    cout << y->data // Gives you the data stored at that address
    Node y = new Node(arr[0], nullptr); // Here you are creating an object, so we can't directly print the object, we need to tap into it
    cout << y.data;
    cout << y.next;
}

// Converting an Array into a Linked List, Traversing thorugh Lkinked List, Finding the Length of the Linked List, Searching an Element in the Linked List:-
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

int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head, int value){
    Node* temp = head;
    while(temp){
        if(temp -> data == value) return 1;
        temp = temp -> next;
    }
    return 0;
}

void print(Node* head){
    while(head != NULL){
        cout << head -> data <<" ";
        head = head -> next;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    // cout << head->data; 

    // Traversing takes a Time Complexity of O(N)
    // Traversing through Linked List:
    // Node* temp = head;
    // while(temp){
    //     cout << temp -> data <<" ";
    //     temp = temp -> next;
    // }

    // Finding the Length of Linked List takes a Time Complexity of O(N)
    // Finding the Length of Linked List:
    // cout<< lengthOfLL(head);

    // Checking if an element takes Time Complexity of O(N) in the worst case, and O(1) in the best case
    // Checking if an element is present in the Linked List:
    cout << checkIfPresent(head,8);
}