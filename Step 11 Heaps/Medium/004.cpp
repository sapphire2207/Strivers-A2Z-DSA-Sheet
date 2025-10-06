// Merge K sorted Lists

// Problem Statement: Given an array of k linked-lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list

// Input Format:
// Lists: 
// 2 4 6 
// 1 5 
// 1 1 3 7 
// 8 
// Output: 1 1 1 2 3 4 5 6 7 8
// Explanation: On merging the linked lists, the value we get are [2, 4, 6, 1, 5, 1, 1, 3, 7, 8] and on sorting them we get [1, 1, 1, 2, 3, 4, 5, 6, 7, 8].
 
// Input: 
// 1 4 5 
// 2 6 
// 1 3 4 
// Output: 1 1 2 3 4 4 5 6
// Explanation: On merging the linked lists, the values we get are [1, 4, 5, 2, 6, 1, 3, 4] and on sorting them we get [1, 1, 2, 3, 4, 4, 5, 6]

// Brute Force Approach
// A brute force approach to merge K sorted linked lists into a single sorted list to extract all node values into a vector. Then we sort this vector and reconstruct the linked list from these sorted node values
// Initialise an empty vector to store the node values of all lists.
// Iterate through the array of K linked lists and for each linked list traverse it using a temporary pointer temp and push the value of each node into the vector.
// Sort the vector containing node values in ascending order.
// Convert the sorted vector back into the merged linked list and return its head.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert a vector to a linked list
// Node* convertArrToLinkedList(vector<int>& arr){
//     // Create a dummy node to serve
//     // as the head of the linked list
//     Node* dummyNode = new Node(-1);
//     Node* temp = dummyNode;

//     // Iterate through the vector and
//     // create nodes with vector elements
//     for(int i = 0; i < arr.size(); i++){
//         // Create a new node with the vector element
//         temp->next = new Node(arr[i]); 
//         // Move the temporary pointer
//         // to the newly created node
//         temp = temp->next; 
//     }
//     // Return the linked list starting
//     // from the next of the dummy node
//     return dummyNode->next; 
// }

// Function to merge K sorted linked lists
Node* mergeKLists(vector<Node*>& listArray){
    // Create a vector to store node values
    vector<int> arr;

    // Iterate through the listArray
    // containing all linked lists
    for(int i = 0; i < listArray.size(); i++){
        // Initialize a temporary pointer to
        // the head of the current linked list
        Node* temp = listArray[i];

        // Traverse through the
        // current linked list
        while(temp != NULL){
            // Store the data of each
            // node in the vector
            arr.push_back(temp->data);

            // Move to the next node
            // in the linked list
            temp = temp->next;
        }
    }

    // Sort the vector containing node
    // values in ascending order
    sort(arr.begin(), arr.end());

    // Convert the sorted vector back to
    // a linked list and return its head
    // return convertArrToLinkedList(arr);
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Create linked lists
    Node* head1 = new Node(2, new Node(4, new Node(6)));
    Node* head2 = new Node(1, new Node(5));
    Node* head3 = new Node(1, new Node(1, new Node(3, new Node(7))));
    Node* head4 = new Node(8);

    // Populate the lists vector
    vector<Node*> lists = {head1, head2, head3, head4};
    
    cout << "Original Linked Lists:" << endl;
    for (int i = 0; i < lists.size(); ++i) {
        cout << "List " << i + 1 << ": ";
        printLinkedList(lists[i]);
    }

    // Merge the linked lists
    Node* mergedList = mergeKLists(lists);
    
    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}

// Original Linked Lists: List 1: 2 4 6 List 2: 1 5 List 3: 1 1 3 7 List 4: 8 Merged Linked List: 1 1 1 2 3 4 5 6 7 8

// Complexity Analysis
// Time Complexity: O(K*N) + O((N*K) * log(N*K)) + O(N*K) where K is the number of linked lists and N is the length of each linked list.
// O(K*N) to traverse N nodes of each of the K linked lists.
// O(N*K log (N*K)) to sort the array containing all nodes ie. N nodes in K linked lists.
// O(N*K) to iterate over all the sorted values in the array and convert them to the merged linked list.
// Space Complexity: O(N*K) + O(N*K) where K is the number of linked lists and N is the length of each linked list.
// O(N*K) to store all the N values of K linked lists into an array.
// O(N*K) additional nodes that are created as part of the merged sorted linked list.

// Merging Lists Two At a Time
// A prerequisite to this approach would be the Inplace Merging of 2 sorted Linked Lists. Read more about it Here
// To merge K linked lists, we can merge them two at a time. Start from the first list and iteratively merge pairs of lists until only the one merged list remains.
// Algorithm:
// Initialise the first list as the starting point for merging.
// Loop through the remaining lists in the array and merge each list with the current merged list and store the merged list as the current list.
// To read more about how to implement the function of merging two sorted lists at a time: Read Here
// Keep updating the merge lists until all lists are merged into a single sorted linked list. Return it
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to merge K sorted linked lists
Node* mergeKLists(vector<Node*>& listArray){
    // Consider the first linked list
    // as the starting point for merging
    Node* head = listArray[0];

    // Loop through the remaining
    // linked lists in the 'listArray'
    for(int i = 1; i < listArray.size(); i++){
        // Merge the current 'head' linked
        // list with the next linked list
        head = mergeTwoSortedLinkedLists(head, listArray[i]);
    }
    // Return the head of
    // the merged linked lists
    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Create linked lists
    Node* head1 = new Node(2, new Node(4, new Node(6)));
    Node* head2 = new Node(1, new Node(5));
    Node* head3 = new Node(1, new Node(1, new Node(3, new Node(7))));
    Node* head4 = new Node(8);

    // Populate the lists vector
    vector<Node*> lists = {head1, head2, head3, head4};
    
    cout << "Original Linked Lists:" << endl;
    for (int i = 0; i < lists.size(); ++i) {
        cout << "List " << i + 1 << ": ";
        printLinkedList(lists[i]);
    }

    // Merge the linked lists
    Node* mergedList = mergeKLists(lists);
    
    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}

// Original Linked Lists: List 1: 2 4 6 List 2: 1 5 List 3: 1 1 3 7 List 4: 8 Merged Linked List: 1 1 1 2 3 4 5 6 7 8

// Complexity Analysis
// Time Complexity:
// Everytime two lists are merged the time complexity is proportional to the sum of the number of nodes in them as we iterate over all nodes and merge according to the data values in them.
// Assume the length of each list to be N1, N2, N3 and so on.
// In the first iteration, when merging the first two lists (N1 and N2), the time complexity is N1 + N2.
// In the second iteration, when merging the result of the first iteration with the third list (N3), the time complexity becomes (N1 + N2) + N3.
// In the third iteration, merging the result of the second iteration with the fourth list (N4), the time complexity becomes ((N1 + N2) + N3) + N4.
// This pattern continues until all K lists are merged.
// The total time complexity can be expressed as:
// T = (N1 + N2) + (N1 + N2 + N3) + .... + (N1 + N2 + N3 + .... + Nk)
// For simplification let's assume the length of each linked list to be proportional to N,
// T = N + 2N + 3N + 4N + 5N + .... + kN
// T = N (1 + 2 + 3 + 4 + ... + k)
// The sum of lengths of the lists can be calculated using the formula for the sum of the first N natural numbers:
// T = N (k(k+1))/2
// Hence, the time complexity is O( N*k(k+1)/2) ~ O(N*k^2)
// Space Complexity: O(1) as no additional data structures or space is allocated for storing data, only a constant space for pointers to maintain for traversing the linked list and merging them in place.

// Optimal Approach
// The previous approach of merging two lists at a time, the number of operations grows exponentially with ‘k’ the number of lists in the list array. With a large number of lists, the number of redundant and repeated comparisons increases substantially affecting the overall efficiency.
// To optimise the process of merging K sorted lists, we can utilise a min heap-based approach where we define a priority queue to maintain the sorted order based on node values. Push all the heads of all K linked lists into a priority queue.
// While the priority queue is not empty, extract the head ie. node with the minimum value, append it to our merged list and push it’s next node into the priority queue.
// This iterative process ensures that at each step, the algorithm selects the smallest available node value among the heads of the linked lists. This minimum value is appended to the merged list, and we then move to the next node from the same list for further merging until all lists are merged into a single sorted linked list.
// Algorithm:
// Initialise a priority queue such that each element is a pair/tuple consisting of an integer (int) representing the node’s data value and a pointer to the node
// This is done because a priority queue maintains a collection of elements with a priority, allowing operations to access and manipulate the element with the highest (or lowest) priority efficiently.
// Using a pair as its elements allows the priority queue to order elements in ascending order of the integer values ie. based on the node data.
// Push the heads of all K linked lists into the priority queue.
// Create a dummy node to build the merge list.
// Iterate while the priority queue is not empty and extract from the top of the priority queue ie. node with the minimum node value.
// If the current extracted node has a next node, push the next node into the priority queue and set the next pointer of the current node in the merged list.
// Return the merged linked list starting from the next of the dummy nodes
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to merge K sorted linked lists
Node* mergeKLists(vector<Node*>& listArray){
    // Priority queue to maintain
    // sorted order based on node values
    // Pairs store node value and pointer to the node
    priority_queue<pair<int, Node*>,
        vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    
    // Push the heads of all the
    // linked lists into the priority queue
    for(int i = 0; i < listArray.size(); i++){
        // Check if the current linked list exists
        if(listArray[i]){
            // Push the pair of node data and
            // node pointer into the priority queue
            pq.push({listArray[i]->data, listArray[i]});
        }
    }
    
    // Create a dummy node to build the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    
    // Merge the lists present
    // in the priority queue
    while(!pq.empty()){
        // Get the top element (minimum node value)
        // from the priority queue
        auto it = pq.top();
        pq.pop();
        
        // Check if the current
        // node has a next node
        if(it.second->next){
            // Push the next node
            // into the priority queue
            pq.push({it.second->next->data, it.second->next});
        }
        
        // Set the next pointer of the
        // current node in the merged list
        temp->next = it.second;
        temp = temp->next;
    }
    
    // Return the merged linked list
    return dummyNode->next;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Create linked lists
    Node* head1 = new Node(2, new Node(4, new Node(6)));
    Node* head2 = new Node(1, new Node(5));
    Node* head3 = new Node(1, new Node(1, new Node(3, new Node(7))));
    Node* head4 = new Node(8);

    // Populate the lists vector
    vector<Node*> lists = {head1, head2, head3, head4};
    
    cout << "Original Linked Lists:" << endl;
    for (int i = 0; i < lists.size(); ++i) {
        cout << "List " << i + 1 << ": ";
        printLinkedList(lists[i]);
    }

    // Merge the linked lists
    Node* mergedList = mergeKLists(lists);
    
    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}

// Original Linked Lists: List 1: 2 4 6 List 2: 1 5 List 3: 1 1 3 7 List 4: 8 Merged Linked List: 1 1 1 2 3 4 5 6 7 8

// Complexity Analysis
// Time Complexity: O(K log K) + O(N*K*(3*log K))where K is the number of linked lists and N is the number of nodes in each list.
// O(K log K) as inserting an element into the priority queue takes log K time and is repeated K times for each list head.
// Considering there are N nodes in each of the K linked lists, the overall number of nodes to be processed is N * K. For each of these N * K nodes:
// Pop: Removing the smallest element (top of the priority queue) takes log K time.
// Add: Adding the next element from the same list (when available) also takes log K time.
// Access top: Accessing the top of the priority queue for extraction or comparison also takes log K time.
// Hence, the total time complexity for the merging process across all nodes is ~ O(N * K * log K).
// Space Complexity : O(K) where K is the number of linked lists. The main contributor to space usage is the priority queue which holds a node from each of these lists. Regardless of the number of nodes within each list, priority queue only holds a reference to one of its nodes at a time hence the space complexity is proportional to the number of input linked lists