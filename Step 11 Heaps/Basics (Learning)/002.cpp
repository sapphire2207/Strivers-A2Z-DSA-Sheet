/*
====================================================================
        Implementation of Min Heap and Max Heap using
                        Priority Queue in C++
====================================================================

INTRODUCTION:
-------------
The STL (Standard Template Library) in C++ provides a very efficient
container called `priority_queue`, which is implemented as a Binary Heap.

By default:
    → `priority_queue` acts as a MAX HEAP.
    → To make it behave like a MIN HEAP, we use the comparator `greater<T>`.

The internal structure of a priority_queue maintains:
    - Complete Binary Tree property.
    - Heap property (Max or Min depending on comparator).

--------------------------------------------------------------------
OPERATIONS SUPPORTED:
--------------------------------------------------------------------
For both Min Heap and Max Heap, the following operations are supported:

1. push(x)
   → Inserts an element into the heap.
   → Time Complexity: O(log N)

2. pop()
   → Removes the top (maximum or minimum) element from the heap.
   → Time Complexity: O(log N)

3. top()
   → Returns the top element (maximum for max heap / minimum for min heap)
     without removing it.
   → Time Complexity: O(1)

4. empty()
   → Checks if the heap is empty.
   → Time Complexity: O(1)

5. size()
   → Returns the number of elements in the heap.
   → Time Complexity: O(1)

--------------------------------------------------------------------
MAX HEAP:
----------
By default, `priority_queue<int>` in C++ is a MAX HEAP.
Property:
    → The largest element is always at the top.
Syntax:
    priority_queue<int> pq;
Example:
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    Top Element (Maximum): 30
    Elements removed in order: 30, 20, 10, 5
--------------------------------------------------------------------
MIN HEAP:
----------
To create a MIN HEAP using `priority_queue`, we must use
a comparator `greater<int>`.
Property:
    → The smallest element is always at the top.
Syntax:
    priority_queue<int, vector<int>, greater<int>> pq;
Example:
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    Top Element (Minimum): 5
    Elements removed in order: 5, 10, 20, 30
--------------------------------------------------------------------
APPLICATIONS:
--------------
1. Priority-based scheduling.
2. Dijkstra’s shortest path algorithm.
3. Huffman encoding.
4. Event simulation systems.
5. Real-time task management.
--------------------------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------------------------
| Operation | Time Complexity |
|------------|----------------|
| push()     | O(log N)       |
| pop()      | O(log N)       |
| top()      | O(1)           |
| size()     | O(1)           |
| empty()    | O(1)           |
--------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------------
                    MAX HEAP IMPLEMENTATION
------------------------------------------------------------*/
void demonstrateMaxHeap() {
    // By default, priority_queue is a Max Heap
    priority_queue<int> maxHeap;

    // Inserting elements
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(1);

    cout << "Elements in Max Heap (in decreasing order): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Get maximum element
        maxHeap.pop();                // Remove it
    }
    cout << endl;
}

/*------------------------------------------------------------
                    MIN HEAP IMPLEMENTATION
------------------------------------------------------------*/
void demonstrateMinHeap() {
    // Creating a Min Heap using greater<int> comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting elements
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(1);

    cout << "Elements in Min Heap (in increasing order): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Get minimum element
        minHeap.pop();                // Remove it
    }
    cout << endl;
}

/*------------------------------------------------------------
                    MAIN FUNCTION
------------------------------------------------------------*/
int main() {
    cout << "----------- MAX HEAP DEMONSTRATION -----------" << endl;
    demonstrateMaxHeap();

    cout << "\n----------- MIN HEAP DEMONSTRATION -----------" << endl;
    demonstrateMinHeap();

    return 0;
}

/*
====================================================================
OUTPUT:
====================================================================
----------- MAX HEAP DEMONSTRATION -----------
Elements in Max Heap (in decreasing order): 30 20 10 5 1

----------- MIN HEAP DEMONSTRATION -----------
Elements in Min Heap (in increasing order): 1 5 10 20 30

====================================================================
EXPLANATION:
====================================================================
→ In Max Heap:
   The largest element always remains on top, so elements are removed
   in descending order.

→ In Min Heap:
   The smallest element always remains on top, so elements are removed
   in ascending order.

→ Internally, priority_queue manages data as a binary heap structure
   (logarithmic insertion and removal time).

====================================================================
*/
