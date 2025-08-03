// Problem 12:
// Sort LL of 0's 1's and 2's

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

// Brute Force:
// First count the number of 0's 1's 2's, then iterate again and replace the data according the counts
// TC: O(2N)
// SC: O(1)
Node* segregateBrute(Node* head){
    Node* temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    while(temp != NULL){
        if(temp -> data == 0){
            count0++;
        }
        else if(temp -> data == 1){
            count1++;
        }
        else{
            count2++;
        }
        temp = temp -> next;
    }

    Node* temp = head;
    while(temp != NULL){
        if(count1){
            temp -> data = 0;
            count0--;
        }
        else if(count1){
            temp -> data = 1;
            count1--;
        }
        else{
            temp -> data = 2;
            count2--;
        }
        temp = temp -> next;
    }
}

// Optimal Method:z
// Approach is use the help of dummyNodes and interchange the links while iterating through the linked list
// TC: O(N)
// SC: O(1)
Node *segregateOptimal(Node *head){
    if (head == NULL || head->next == NULL)
        return head;
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;
    while (temp != NULL){
        if (temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    Node *finalAns = zeroHead->next;

    delete (zeroHead);
    delete (oneHead);
    delete (twoHead);

    return finalAns;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7, 9};
    Node *head = convertArr2LL(arr);
    head = segregateBrute(head);
    head = segregateOptimal(head);
    print(head);

    return 0;
}