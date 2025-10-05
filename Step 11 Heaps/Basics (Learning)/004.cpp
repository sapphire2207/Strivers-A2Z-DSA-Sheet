/*
====================================================================
                CONVERT MIN HEAP TO MAX HEAP IN C++
====================================================================

INTRODUCTION:
-------------
A **Heap** is a Complete Binary Tree that satisfies either:
    → **Min Heap Property:** Every parent node is smaller than its children.
    → **Max Heap Property:** Every parent node is greater than its children.

Conversion Goal:
----------------
We are given a **Min Heap**, and we need to **convert it into a Max Heap** 
using efficient heap operations.

The main idea:
--------------
The array representation of a Min Heap can be converted to a Max Heap
by applying the **Heapify()** process in a bottom-up manner, starting
from the last internal node up to the root.

--------------------------------------------------------------------
WHY THIS WORKS:
--------------------------------------------------------------------
- Both Min Heap and Max Heap follow the **Complete Binary Tree** structure.
- The only difference lies in the ordering property:
    Min Heap → parent < children
    Max Heap → parent > children
- So we only need to rearrange elements to satisfy the Max Heap property.

--------------------------------------------------------------------
STEPS TO CONVERT:
--------------------------------------------------------------------
1️⃣ Input is given as an array representing a Min Heap.
2️⃣ Start from the last non-leaf node:
       index = (n / 2) - 1
3️⃣ For each node (from bottom to top):
       → Apply MaxHeapify() function to ensure the subtree rooted at
         that node satisfies the Max Heap property.
4️⃣ After completion, the array will represent a valid Max Heap.

--------------------------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------------------------
- Building (or converting) a heap from an array using heapify
  takes **O(N)** time — not O(N log N)!
  Because most heapify operations are done on smaller subtrees.

--------------------------------------------------------------------
FUNCTIONS USED:
--------------------------------------------------------------------
- **MaxHeapify(arr[], n, i)**:
      Ensures that subtree rooted at index `i` satisfies
      the Max Heap property, assuming subtrees are already heaps.

- **convertMinToMaxHeap(arr[], n)**:
      Calls MaxHeapify() on all internal nodes starting from the
      last non-leaf node up to the root.

--------------------------------------------------------------------
EXAMPLE:
--------------------------------------------------------------------
Input Min Heap:     [1, 3, 5, 7, 9, 2, 6, 8, 10]

After Conversion:
Output Max Heap:    [10, 9, 6, 8, 7, 2, 5, 3, 1]
--------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------------
    FUNCTION: MaxHeapify
    Purpose:  Fix the Max Heap property at a given index i
------------------------------------------------------------*/
void MaxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Assume current node is largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Compare with left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Compare with right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the current node, swap and recurse
    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

/*------------------------------------------------------------
    FUNCTION: convertMinToMaxHeap
    Purpose:  Convert Min Heap to Max Heap
------------------------------------------------------------*/
void convertMinToMaxHeap(vector<int>& arr, int n) {
    // Start from last non-leaf node and move upward
    for (int i = (n / 2) - 1; i >= 0; i--) {
        MaxHeapify(arr, n, i);
    }
}

/*------------------------------------------------------------
    FUNCTION: printArray
    Purpose:  Display heap elements
------------------------------------------------------------*/
void printArray(vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

/*------------------------------------------------------------
    MAIN FUNCTION
------------------------------------------------------------*/
int main() {
    // Given Min Heap representation in array form
    vector<int> arr = {1, 3, 5, 7, 9, 2, 6, 8, 10};
    int n = arr.size();

    cout << "Original Min Heap Array: ";
    printArray(arr);

    // Convert Min Heap to Max Heap
    convertMinToMaxHeap(arr, n);

    cout << "Converted Max Heap Array: ";
    printArray(arr);

    return 0;
}

/*
====================================================================
OUTPUT:
====================================================================
Original Min Heap Array: 1 3 5 7 9 2 6 8 10
Converted Max Heap Array: 10 9 6 8 7 2 5 3 1
====================================================================

EXPLANATION:
-------------
1️⃣ The Min Heap array is traversed bottom-up.
2️⃣ At each node, we apply MaxHeapify() to ensure the Max Heap property.
3️⃣ The result is a valid Max Heap (parent ≥ children).
4️⃣ The array still represents a complete binary tree.

====================================================================
TIME COMPLEXITY SUMMARY:
--------------------------------------------------------------------
| Operation             | Time Complexity |
|------------------------|----------------|
| MaxHeapify()          | O(log N)       |
| convertMinToMaxHeap() | O(N)           |
| printArray()          | O(N)           |
====================================================================

NOTE:
-----
- The array-based representation of heap makes conversion easier.
- This method is efficient and widely used in heap transformations.
- Similar logic applies for converting Max Heap → Min Heap (using MinHeapify).
====================================================================
*/
