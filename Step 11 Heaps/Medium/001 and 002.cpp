// Kth largest/smallest element in an array

// Problem Statement: Given an unsorted array, print Kth Largest and Smallest Element from an unsorted array.

// Example 1:
// Input: Array = [1,2,6,4,5,3] , K = 3 
// Output: kth largest element = 4, kth smallest element = 3

// Example 2:
// Input: Array = [1,2,6,4,5] , k = 3
// Output : kth largest element = 4,  kth smallest element = 4

// Brute Force: Sorting the Array
// The most naive approach is to sort the given array in descending order.
// The index of kth Largest element = k-1 ( zero-based indexing ) 
// The index of kth Smallest element = n-k 
// The array can also be sorted in ascending order.
// The index of kth Largest element = n-k 
// The index of kth Smallest element = k-1 ( zero based indexing )
#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:

void kth_Largest_And_Smallest_By_AscOrder(vector<int>&arr, int k) {

        sort(arr.begin(), arr.end())  ;
        int n = arr.size()  ;

        cout << "kth Largest element " << arr[n - k] << ", " << 
        "kth Smallest element " << arr[k - 1];
    }
} ;

int main() {

    vector<int>arr = {1, 2, 6, 4, 5, 3}  ;

    Solution obj ;
    
    // obj.kth_Largest_And_Smallest_By_AscOrder(arr, 3);

    return 0 ;
}

// Output: kth Largest element 4, kth Smallest element 3

// Time complexity: O(nlogn)
// Space complexity: O(1)

// Approach: Using Heap
// The idea is to construct a max-heap of elements. Since the top element of the max heap is the largest element of the heap, we will remove the top K-1 elements from the heap.  The top element will be Kth's Largest element.
// To get the Kth Smallest element, we will use a min-heap. After the removal of the top k-1 elements, the Kth Smallest element is top of the Priority queue.
// Let the array be
// [17,7,2,30,21] and k = 3
// Similarly, for the smallest kth element we will be using Min-Heap. After, extracting the top k-1 values will be having Kth Smallest element.
#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:

    void kth_Largest_MaxHeap(vector<int>&arr, int k) {

        priority_queue<int>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Largest element " << pq.top() << "\n"  ;
    }

    void kth_Smallest_MinHeap(vector<int>&arr, int k) {

        priority_queue<int, vector<int>, greater<int>>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Smallest element " << pq.top() << "\n"  ;
    }
} ;

int main() {

    vector<int>arr = {1, 2, 6, 4, 5, 3}  ;

    Solution obj ;
    obj.kth_Largest_MaxHeap(arr, 3)  ;
    obj.kth_Smallest_MinHeap(arr, 3)  ;

    return 0 ;
}

// Output:
// Kth Largest element 4
// Kth Smallest element 3

// Time complexity: O(k+(n-k)*log(k))  , n = size of array
// Space complexity: O(k)