// Problem 2:
// Rotate a Linked List
// Problem Statement: Given the head of a linked list, rotate the list to the right by k places.
// Example 1:
// Input:
// 	head = [1,2,3,4,5] 
// 	k = 2
// Output:
//  head = [4,5,1,2,3]
// Explanation:
//  We have to rotate the list to the right twice.

// Approach:
// We can see that for every k which is multiple of the length of the list, we get back the original list. Try to operate brute force on any linked list for k as a multiple of the length of the list.
// This gives us a hint that for k greater than the length of the list, we have to rotate the list for k%length of the list. This reduces our time complexity.
// Steps to the algorithm:-
// Calculate the length of the list.
// Connect the last node to the first node, converting it to a circular linked list.
// Iterate to cut the link of the last node and start a node of k%length of the list rotated list.

// Time Complexity: O(length of list) + O(length of list - (length of list%k))
// Reason: O(length of the list) for calculating the length of the list. O(length of the list - (length of list%k)) for breaking link.
// Space Complexity: O(1)
// Reason: No extra data structure is used for computation.
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // mover = mover -> next
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *getnthNode(Node *temp, int k)
{
    int count = 1;
    while (temp != NULL)
    {
        if (count == k)
            return temp;
        count++;
        temp = temp->next;
    }
    return temp;
}

Node *rotateRight(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    Node *tail = head;
    int length = 1;
    while (tail->next != NULL)
    {
        length++;
        tail = tail->next;
    }
    if (k % length == 0)
        return head;
    k = k % length;
    tail->next = head;
    Node *lastNode = getnthNode(head, length - k);
    head = lastNode->next;
    lastNode->next = NULL;
    return head;
}