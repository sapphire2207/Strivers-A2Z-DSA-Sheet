// Find Median from Data Stream

// Problem Statement: Implement a class that finds the median from a data stream. The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
// Implement the MedianFinder class as follows:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
// Examples
// Input : [MedianFinder(), addNum(1), addNum(2), addNum(3), findMedian()]
// Output : [null, null, null, null, 2]
// Explanation : MedianFinder() initializes the object. addNum(1) adds 1 to the data stream → [1] addNum(2) adds 2 → [1, 2] addNum(3) adds 3 → [1, 2, 3] findMedian() returns 2 as the median of [1, 2, 3]

// Input : [MedianFinder(), addNum(1), addNum(6), findMedian(), addNum(3), findMedian()]
// Output : [null, null, null, 3.5, null, 3]
// Explanation : MedianFinder() initializes the object. addNum(1) → [1] addNum(6) → [1, 6] findMedian() returns (1+6)/2 = 3.5 addNum(3) → [1, 3, 6] findMedian() returns 3 as the median

// Brute Force Approach
// We maintain a list of all numbers inserted so far. Every time we want the median, we sort the entire list and return either the middle element (odd size) or the average of the two middle elements (even size). This is simple to implement but inefficient for large inputs.
// Create an empty list to store all incoming numbers.
// On calling addNum, insert the number into the list.
// On calling findMedian:
// Sort the list.
// If size is odd, return the middle element.
// If size is even, return average of the two middle elements.
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 1) {
            return nums[n / 2];
        }
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Complexity Analysis
// Time Complexity: O(N log N),Every call to findMedian() sorts the list of N numbers, which takes O(N log N) time. Adding a number is O(1). Hence, the median query is the bottleneck.
// Space Complexity:O(N) , We store all elements in a list, which uses linear space.

// Optimal Approach
// To efficiently find the median after each insertion, we can use two heaps: A max-heap to store the smaller half of the numbers. A min-heap to store the larger half of the numbers. The max-heap gives access to the largest element of the smaller half, and the min-heap gives access to the smallest element of the larger half. This way, the median will always be either: The top of the max-heap (if total size is odd), or The average of the tops of both heaps (if even). We maintain the following invariants: The size of the max-heap is either equal to or 1 greater than the min-heap. All elements in the max-heap are less than or equal to those in the min-heap.
// Initialize two heaps: a max-heap for the smaller half and a min-heap for the larger half.
// When inserting a new number:
// If it's less than or equal to the top of the max-heap, insert it into the max-heap.
// Otherwise, insert it into the min-heap.
// Balance the heaps if their sizes differ by more than 1.
// To find the median:
// If both heaps are of equal size, return the average of the tops of both heaps.
// Otherwise, return the top of the heap that has one extra element.
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Complexity Analysis
// Time Complexity:O(N log N + M) , Because each call to addNum() takes O(log N), and each call to findMedian() is O(1).
// Space Complexity: O(N) , We store all the numbers across two heaps. The max-heap stores the smaller half of numbers (up to N/2) and the min-heap stores the larger half (up to N/2) So, the total space used is O(N), where N is the number of elements added to the data structure.