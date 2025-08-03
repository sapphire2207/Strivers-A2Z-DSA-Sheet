// Deletion and Insertion in Linked List:

// 1) Deleting:
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

Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* removetail(Node* head){
    if(head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete(temp -> next);
    temp -> next = nullptr;
    return head;
}

Node* removeKthPosition(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        removesHead(head);
    }
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        count++;
        if(count == k){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

// Another version of removeKthPosition
Node* removeKthPosition(Node* head, int k){
    if(head == NULL) return head;

    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count = 1;
    Node* temp = head;
    while(temp != NULL){
        if(count == k - 1){
            if(temp->next != NULL){
                Node* del = temp->next;
                temp->next = temp->next->next;
                free(del);
            }
            break;
        }
        temp = temp->next;
        count++;
    }
    return head;
}

Node* removeElement(Node* head, int element){
    if(head == NULL) return head;
    if(head -> data == element){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp -> data == element){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* insertHead(Node* head, int value){
    Node* temp = new Node(value, head);
    return temp;
}

Node* insertTail(Node* head, int value){
    if(head == NULL){
        return new Node(value);
    }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node(value);
    temp -> next = newNode;
    return head;
}

Node* insertKthPosition(Node* head, int element, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(element);
        }else{
            return head;
        }
    }
    if(k == 1){
        return new Node(element, head);
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == (k-1)){
            Node* newNode = new Node(element, temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int element, int value){
    if(head == NULL){
        return NULL;
    }
    if(head -> data == value){
        return new Node(element, head);
    }
    Node* temp = head;
    while(temp -> next != NULL){
        if(temp -> next -> data == value){
            Node* newNode = new Node(element, temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    head = removesHead(head);
    // head = removeTail(head);
    head = removeKthPosition(head, 3);
    head = removeElement(head, 8);
    head = insertHead(head, 1);
    head = insertTail(head, 9);
    head = insertKthPosition(head, 6, 3); // here 'k' can be only from 1-5 depending on the size of the Linked List
    head = insertBeforeValue(head, 4, 5);
    print(head);
}