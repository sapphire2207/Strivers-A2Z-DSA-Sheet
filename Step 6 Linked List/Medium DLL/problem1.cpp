// Problem 1:
// Delete all occurrences of a given key in a doubly linked list
// You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

// Example:
// Input:
// 2<->2<->10<->8<->4<->2<->5<->2
// 2
// Output:
// 10<->8<->4<->5
// Explanation:
// All Occurences of 2 have been deleted.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        prev = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

// Optimal Approach:
// You are just traversing the DLL while checking whether every node has the given occurence, if present you make the link changes and free the node, else move forward...
// TC: O(N)
// SC: O(1)
void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    // Write your code here
    Node *temp = *head_ref;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            if (temp == *head_ref)
            {
                *head_ref = (*head_ref)->next;
            }
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;
            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;
            delete (temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
}