// Check if an array represents a min heap

// Problem Statement: Given an array of integers nums. Check whether the array represents a binary min-heap or not. Return true if it does, otherwise return false.
// A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

// Examples
// Input: nums = [10, 20, 30, 21, 23]
// Output: true
// Explanation: Each node has a lower or equal value than its children.

// Input: nums = [10, 20, 30, 25, 15]
// Output: false
// Explanation: The node with value 20 has a child with value 15, thus it is not a min-heap.

// Approach:
// We store a binary heap in an array because it simplifies the way we access parent and child nodes.
// for a node at index i
// 1. left child is always at 2*i + 1
// 2. right child is at 2*i + 2.
// Since we're checking whether the array represents a min heap, we need to ensure that every parent node is less than or equal to both of its children. That's the key rule for min heaps. We don’t have to check every element in the array. Leaf nodes don’t have children, so they can’t violate the heap property. In an array of size n, leaf nodes start from index n/2, so the only nodes we actually need to check are from index 0 to n/2 - 1. These are the non-leaf nodes. For each of these, we compute their children’s indices and compare values. If any parent node is found to be greater than one of its children, we can immediately return false because the heap rule is broken. If all the parent nodes satisfy the condition, then the array is a valid min heap.
// Iterate over all non-leaf nodes.
// For each index:
// Compute the index of the left child.
// Compute the index of the right child.
// If the left child exists and its value is less than the current node’s value, return false.
// If the right child exists and its value is less than the current node’s value, return false.
// If the loop finishes without any violations, return true.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if the given array is a min-heap
    bool isMinHeap(vector<int>& nums) {
        int n = nums.size();

        // Iterate through all non-leaf nodes
        for (int i = 0; i <= (n / 2) - 1; i++) {

            // Calculate the left child index
            int left = 2 * i + 1;

            // If left child exists and is smaller than parent, not a min-heap
            if (left < n && nums[i] > nums[left]) {
                return false;
            }

            // Calculate the right child index
            int right = 2 * i + 2;

            // If right child exists and is smaller than parent, not a min-heap
            if (right < n && nums[i] > nums[right]) {
                return false;
            }
        }

        // If no violations found, it is a min-heap
        return true;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> nums = {10, 20, 30, 21, 23};

    // Output result
    cout << (obj.isMinHeap(nums) ? "true" : "false") << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n), where n is the number of elements in the array. We only iterate through the non-leaf nodes, which are at most n/2, so it's still O(n) in terms of asymptotic complexity. Each comparison (at most two per node) is constant time.
// Space Complexity: O(1), no extra space is used. We only use a few variables.