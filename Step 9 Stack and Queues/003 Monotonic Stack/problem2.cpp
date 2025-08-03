// Next Greater Element II
// Problem Statement:
// You are given a circular array of integers. The task is to find the Next Greater Element (NGE) for each element.
// The Next Greater Element of an element X is the first element to its right that is greater than X.
// If no such element exists, return -1.
// Since the array is circular, after reaching the last index, we continue checking from the beginning.

// Example
// Input:
// arr = [2, 10, 12, 1, 11]
// Output:
// NGE = [10, 12, -1, 11, 12]
// Explanation:
// 2 → 10 (first greater element on the right)
// 10 → 12
// 12 → -1 (no greater element)
// 1 → 11
// 11 → 12

// Extreme Brute Force
// Iterate over each element arr[i] and look for the next greater element.
// First, check the elements to the right (i+1 to n-1).
// If no greater element is found, check the left side (0 to i-1).
// If no greater element exists in the full circular traversal, return -1.
// TC: O(N^2)
// SC: O(N)
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1); // Initialize with -1

    for (int i = 0; i < n; i++) {
        // Check to the right (i+1 to n-1)
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                nge[i] = nums[j];
                break;
            }
        }

        // If not found, check from start (0 to i-1)
        if (nge[i] == -1) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) {
                    nge[i] = nums[j];
                    break;
                }
            }
        }
    }
    return nge;
}

int main() {
    vector<int> arr = {2, 10, 12, 1, 11};
    vector<int> result = nextGreaterElements(arr);
    
    for (int num : result) cout << num << " ";
    return 0;
}

// Better Solution:
// We traverse the array twice (virtual doubling)
// i.e by modularizing the indexes with the size of the array....(i % N)
// TC: O(N^2)
// SC: O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums){
    int n = nums.size();
    vector<int> nge(n, -1);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < i + n - 1; j++){
            int index = j % n;
            if(nums[index] > nums[i]){
                nge[i] = nums[index];
                break;
            }
        }
    }

    return nge;
}

int main(){
    vector<int> arr = {2, 10, 12, 1, 11};
    vector<int> result = nextGreaterElements(arr);
    
    for (int num : result) cout << num << " ";
    return 0;
}

// Optimised Approach:
// We traverse the array twice (virtual doubling).
// We maintain a stack to keep track of elements in decreasing order.
// If a greater element is found, we pop the stack and update the NGE.
// Use a monotonic decreasing stack (stores elements in decreasing order).
// Traverse the array from right to left (reverse order).
// If the stack is non-empty, check for next greater elements.
// Push elements into the stack while maintaining monotonic order.
// Use modulo to simulate circular behavior.
// Time Complexity: O(n) (each element is pushed/popped once).
// Space Complexity: O(n) (for stack and output array).
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1); // Store NGE results
    stack<int> st; // Monotonic decreasing stack

    // Traverse twice to simulate circular array
    for (int i = 2 * n - 1; i >= 0; i--) {
        int index = i % n; // Circular index

        // Remove smaller elements from stack
        while (!st.empty() && st.top() <= nums[index]) {
            st.pop();
        }

        // Assign NGE if stack is not empty
        if(i < n){
            nge[i] = st.empty() ? -1 : st.top();
        }

        // Push current element into stack
        st.push(nums[index]);
    }
    return nge;
}

int main() {
    vector<int> arr = {2, 10, 12, 1, 11};
    vector<int> result = nextGreaterElements(arr);

    for (int num : result) cout << num << " ";
    return 0;
}