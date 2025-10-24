// Kth largest element in a stream of running integers

// Problem Statement: Implement a class KthLargest to find the kth largest number in a stream. It should have the following methods:
// KthLargest(int k, int [] nums) Initializes the object with the integer k and the initial stream of numbers in nums
// int add(int val) Appends the integer val to the stream and returns the kth largest element in the stream.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Examples
// Input: [KthLargest(3, [1, 2, 3, 4]), add(5), add(2), add(7)]
// Output: [null, 3, 3, 4]
// Explanation: initial stream = [1, 2, 3, 4], k = 3.
// add(5): stream = [1, 2, 3, 4, 5] -> returns 3
// add(2): stream = [1, 2, 2, 3, 4, 5] -> returns 3
// add(7): stream = [1, 2, 2, 3, 4, 5, 7] -> returns 4

// Input: [KthLargest(2, [5, 5, 5, 5], add(2), add(6), add(60)]
// Output: [null, 5, 5, 6]
// Explanation: initial stream = [5, 5, 5, 5], k = 2.
// add(2): stream = [5, 5, 5, 5, 2] -> returns 5
// add(6): stream = [5, 5, 5, 5, 2, 6] -> returns 5
// add(60): stream = [5, 5, 5, 5, 2, 6, 60] -> returns 6

// Algorithm
// To keep track of the kth largest element in real-time, we don’t need to sort the entire list each time. Instead, we can maintain a Min-Heap of size k. This way, the top of the heap always gives us the kth largest element so far. Each time a new element is added, we check if it’s large enough to enter the heap. If it is, we add it and remove the smallest to maintain only the top k elements.
// Create a min-heap.
// Insert the first k elements from the initial stream into the heap.
// For the remaining elements in the initial stream:
// If the element is greater than the smallest in heap, insert it and remove the smallest.
// When a new element is added via add()
// Insert it into the heap.
// If heap size exceeds k, remove the smallest.
// Return the top of the heap (kth largest).
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int num: nums){
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > size) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Time Complexity: O(log k), per insertion each insertion into the min-heap takes O(log k) time. Since we maintain a heap of at most k elements, both inserting a new number and removing the smallest (if needed) are log k operations.

// Space Complexity:O(k),The min-heap stores only the top k largest elements at any time. So space usage is proportional to k.