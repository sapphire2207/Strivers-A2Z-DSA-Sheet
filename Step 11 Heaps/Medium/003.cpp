// Sort K sorted array

// Problem Statement: Given an array arr[] and a number k . The array is sorted in a way that every element is at max k distance away from it sorted position. It means if we completely sort the array, then the index of the element can go from i - k to i + k where i is index in the given array. Our task is to completely sort the array.

// Examples
// Input :  arr = [6, 5, 3, 2, 8, 10, 9], k = 3  
// Output :  [2, 3, 5, 6, 8, 9, 10]  
// Explanation :  The element 2 was at index 3, it moved to index 0. The element 3 was at index 2, it moved to index 1. The element 5 moved from index 1 to index 2. The element 6 moved from index 0 to index 3. The rest (8, 9, 10) were near their correct spots and shifted slightly.

// Input :  arr = [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2  
// Output :  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  
// Explanation :  The element 2 moved from index 3 to index 1. The element 3 moved from index 4 to index 2. The element 4 moved from index 1 to index 3. The element 5 moved from index 2 to index 4. All others remained in or near their correct positions.

// Brute Force Approach
// In a brute force approach, we ignore the fact that the array is nearly sorted. We treat it like any unsorted array and apply a general sorting algorithm to get the correct output. This works because sorting guarantees the correct position of every element, regardless of their initial distance from their target index.
// Take the entire array as input
// Apply a full sorting algorithm to the array (like quicksort or mergesort)
// Return the fully sorted array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array using brute force
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
        // Sort the entire array
        sort(arr.begin(), arr.end());

        // Return the sorted array
        return arr;
    }
};

// Driver code
int main() {
    // Define the input array
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};

    // Define the value of k
    int k = 3;

    // Create object of Solution class
    Solution obj;

    // Call the function to sort the array
    vector<int> result = obj.sortNearlySortedArray(arr, k);

    // Print the sorted array
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// Complexity Analysis
// Time Complexity: O(n log n),This is because we sort the entire array of size n, using a general-purpose sorting algorithm.
// Space Complexity: O(1) for in-place sorting (if using in-place sort)However, some built-in sorts may use O(log n) stack space for recursion or O(n) if not in-place.

// Optimal Approach
// This approach is built around the core idea of a k-sorted array — where each element is at most k positions away from its correct place. This means that the smallest element in the array must exist somewhere in the first k + 1 elements.
// So instead of sorting the entire array, we can use a min heap to efficiently keep track of the smallest elements in a moving window of size k + 1.
// By inserting the first k + 1 elements into the heap, we ensure the smallest element among them bubbles to the top. We then remove it and append it to the result. As we move forward, we keep adding new elements into the heap while removing the smallest (root). This way, we always process the next smallest valid number and build the sorted result — while leveraging the k-distance constraint for efficiency. This drastically reduces the time complexity compared to sorting the entire array.
// Initialize an empty min heap
// Insert the first k + 1 elements from the array into the heap
// Start from the (k + 1)th element and iterate through the array
// In each step, remove the smallest element from the heap and append it to the result
// Push the current array element into the heap
// After processing the full array, remove all remaining elements from the heap and append them to the result
// Return the final result array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort a k-sorted array using a min heap
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
        // Create a min heap using priority_queue with greater comparator
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Store the final sorted result
        vector<int> result;

        // Push first k+1 elements into the heap
        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }

        // Process the remaining elements of the array
        for (int i = k + 1; i < arr.size(); i++) {
            // Push the smallest element from the heap to the result
            result.push_back(minHeap.top());
            minHeap.pop();

            // Push the current element into the heap
            minHeap.push(arr[i]);
        }

        // Pop remaining elements from the heap
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        // Return the sorted array
        return result;
    }
};

// Driver code
int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    Solution obj;
    vector<int> sortedArr = obj.sortNearlySortedArray(arr, k);

    for (int num : sortedArr) {
        cout << num << " ";
    }

    return 0;
}

// Complexity Analysis
// Time Complexity: O(n log k),We insert n elements into a min heap of size k + 1. Each insertion/removal from heap costs O(log k). So total time = O(n log k).
// Space Complexity: O(k),We maintain a min heap of size at most k + 1 at all times.