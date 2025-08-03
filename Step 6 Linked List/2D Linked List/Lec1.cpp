// Doubly Linked List:-

// Converting an array into a Double Linked List:
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prevNode  = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prevNode);
        prevNode -> next = temp;
        prevNode = prevNode -> next;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node* deleteHead(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* prevNode = head;
    head = head -> next;
    head -> back = nullptr;
    prevNode -> next = nullptr;
    delete(prevNode);
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }

    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* newTail = tail -> back;
    newTail -> next = nullptr;
    tail -> back = nullptr;
    delete tail;
    return head; 
}

// If arr is {2,5,8,7} 'k' can only be from 1 - 4
Node* removeKthPosition(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    int count = 0;
    Node* kthNode = head;
    while(kthNode != NULL){
        count++;
        if(count == k) break;
        kthNode = kthNode -> next;
    }

    Node* prevNode = kthNode -> back;
    Node* frontNode = kthNode -> next;

    if(prevNode == NULL && frontNode == NULL){
        return NULL;
    }else if(prevNode == NULL){
        return deleteHead(head);
    }else if(frontNode == NULL){
        return deleteTail(head);
    }

    prevNode -> next = frontNode;
    frontNode -> back = prevNode;
    kthNode -> back = nullptr;
    kthNode -> next = nullptr;
    delete(kthNode);
    return head;
}

void deleteParticularNode(Node* temp){
    Node* prevNode = temp -> back;
    Node* frontNode = temp -> next;

    if(frontNode == NULL){
        prevNode -> next = nullptr;
        temp -> back = nullptr;
    }

    prevNode -> next = frontNode;
    frontNode -> back = prevNode;

    temp -> back = nullptr;
    temp -> next = nullptr;

    delete(temp);
}

Node* insertBeforeHead(Node* head, int value){
    Node* newHead = new Node(value, head, nullptr);
    head -> back = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int value){
    if(head -> next == NULL){
        return insertBeforeHead(head, value);
    }

    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* prevNode = tail -> back;
    Node* newNode = new Node(value, tail, prevNode);
    prevNode -> next = newNode;
    tail -> back = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int value){
    if(k == 1){
        return insertBeforeHead(head, value);
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp -> next;
    }
    Node* prevNode = temp -> back;
    Node* newNode = new Node(value, temp, prevNode);
    prevNode -> next = newNode;
    temp -> back = newNode;
    return head;
}

void insertBeforeParticularNode(Node* node, int value){
    Node* prevNode = node -> back;
    Node* newNode = new Node(value, node, prevNode);
    prevNode -> next = newNode;
    node -> back = newNode;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2DLL(arr);
    head = deleteHead(head);
    head = deleteTail(head);
    head = removeKthPosition(head, 2); // here you are deleting a position from the given Linked List
    deleteParticularNode(head -> next); // here you are sending a node to delete that particular node
    head = insertBeforeHead(head, 1); // inserting a node (new head) before the old head
    head = insertBeforeTail(head, 6);
    head = insertBeforeKthElement(head, 2, 4);
    insertBeforeParticularNode(head -> next -> next, 6);
    print(head);
    return 0;
}