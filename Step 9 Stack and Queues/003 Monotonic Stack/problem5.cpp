// Sum of subarray minimum

// Given: An array of numbers.
// Task: Find the sum of the minimum values of all possible subarrays.
// Modulo Constraint: Since the result can be large, return the result modulo 10⁹ + 7.

// Brute Force Approach:
// Generate all possible subarrays.
// Find the minimum for each subarray.
// Sum up all the minimum values.
// Use two nested loops:
// Outer loop: Fixes the starting index of the subarray.
// Inner loop: Extends the subarray and updates the minimum value.
// Complexity: O(N²) (since we check all subarrays).
// Space Complexity: O(1) (no extra space used).
// Drawback: Not efficient for large arrays.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int sumSubarrayMins(vector<int> &arr){
        int sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++){
            int mini = arr[i];
            for (int j = i; j < arr.size(); j++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        return sum;
    }
};


// Optimized Approach
// Goal: Find how many subarrays a given element contributes to as the minimum.
// Key Observation: Instead of generating subarrays, determine how many subarrays have a particular element as their minimum.
// Steps:
// Each element contributes as the minimum to several subarrays.
// Count occurrences:
// Example: For an element x, find how many subarrays contain it as their smallest element.
// Multiply element value by the number of subarrays where it is the minimum.
// Formula:
// Each element contributes to left × right subarrays, where:
// Left: Number of subarrays starting from the left where the element is the minimum.
// Right: Number of subarrays ending at the right where the element is the minimum.
// Total Contribution: element_value * left_count * right_count
// Finding Left & Right Counts Efficiently:
// Previous Smaller Element (PSE): Determines how many elements can be on the left.
// Next Smaller Element (NSE): Determines how many elements can be on the right.
// Using stacks, these can be computed in O(N) time.
// Precomputing PSE and NSE Using Stacks: 
// Finding Next Smaller Element (NSE):
// Traverse the array from right to left.
// Maintain a monotonic stack (stores indices).
// If the current element is smaller or equal, pop elements from the stack.
// Store the next smaller element's index in an array.
// If no smaller element is found, store n (array length) as the index.
// Finding Previous Smaller Element (PSE):
// Traverse the array from left to right.
// Maintain a monotonic stack (stores indices).
// If the current element is smaller, pop elements from the stack.
// Store the previous smaller element's index in an array.
// If no smaller element is found, store -1 as the index.
// Handling Edge Cases
// Duplicate Elements:
// If duplicates exist, update PSE logic to consider "Previous Smaller or Equal" instead of just "Previous Smaller".
// Ensures elements are counted only once in the contribution calculation.
// No Smaller Element Exists:
// If no NSE is found, assume it is at index n (array length).
// If no PSE is found, assume it is at index -1.

class Solution {
public:

    vector<int> findNSE(vector<int> & arr){
        vector<int> nse;
        stack<int> st;
        for(int i = arr.size() - 1; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()]>= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int> & arr){
        vector<int> psee;
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()]> arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n,0);
        vector<int> psee(n,0);
        nse = findNSE(arr);
        psee = findPSE(arr);
        int totalSum = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            totalSum = (totalSum + (left * right * 1ll * arr[i]) % mod) % mod;
        }
        return totalSum;
    }
};