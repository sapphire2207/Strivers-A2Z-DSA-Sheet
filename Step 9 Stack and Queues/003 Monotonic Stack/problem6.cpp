// Sum of Subarray Ranges
// Given an array of numbers, generate all possible subarrays.
// For each subarray, calculate its range.
// Return the sum of all these subarray ranges.

// Brute Force Approach:
// Generate all subarrays:
// Use a nested loop to generate all subarrays.
// The outer loop (i) fixes the starting index.
// The inner loop (j) extends the subarray from index i to n-1.
// Find the largest and smallest element in each subarray:
// Initialize largest = arr[i] and smallest = arr[i].
// As j moves, update largest = max(largest, arr[j]).
// Update smallest = min(smallest, arr[j]).
// Compute the range and update sum:
// sum += largest - smallest
// Time Complexity:
// Since we generate all subarrays using two nested loops, the complexity is O(N²).
// Space Complexity:
// Uses only a few extra variables → O(1).
class Solution{
    public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long maxi = nums[i];
            long long mini = nums[i];
            for(int j=i;j<n;j++){
                maxi = max(maxi,(long long)nums[j]); 
                mini = min(mini,(long long)nums[j]);
                sum += maxi - mini;
            }
        }
        return sum;
    }
}


// Optimized Approach Using Stack:
// The problem is related to sum of subarray minimums and sum of subarray maximums.
// Instead of generating all subarrays explicitly, we can compute these sums separately and subtract them.
// Key Insight:
// The result can be written as:
// ∑(max of all subarrays)−∑(min of all subarrays)
// We already know how to solve sum of subarray minimums efficiently using monotonic stacks.
// Similarly, we can solve sum of subarray maximums.
// Steps to Solve:
// Implement a function sumSubarrayMax(arr) to compute sum of max elements.
// Implement a function sumSubarrayMin(arr) to compute sum of min elements.
// Return the difference between these two sums.
// Time Complexity:
// The optimized solution takes O(N) time using monotonic stacks.
// Much better than the brute force O(N²) approach.
// Space Complexity:
// O(N) due to the use of stacks.
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findNSE(vector<int>& nums) {
            int n = nums.size();
            vector<int> nse(n);
            stack<int> st;
            for(int i=n-1; i>=0; i--) {
                while(!st.empty() && nums[st.top()] >= nums[i])
                    st.pop();
                nse[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            return nse;
        }
    
        vector<int> findPSEE(vector<int>& nums) {
            int n = nums.size();
            vector<int> psee(n);
            stack<int> st;
            for(int i=0; i<n; i++) {
                while(!st.empty() && nums[st.top()] > nums[i])
                    st.pop();
                psee[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return psee;
        }
    
        long long sumSubarrayMins(vector<int>& nums) {
            vector<int> nse = findNSE(nums);
            vector<int> psee = findPSEE(nums);
    
            long long total = 0;
            for(int i=0; i<nums.size(); i++) {
                int left = i - psee[i];
                int right = nse[i] - i;
    
                total += right * left * 1LL * nums[i];
            }
            return total;
        }
    
        vector<int> findNGEE(vector<int>& nums) {
            int n = nums.size();
            vector<int> ngee(n);
            stack<int> st;
            for (int i = n-1; i>=0; i--) {
                while (!st.empty() && nums[st.top()] <= nums[i])
                    st.pop();
                ngee[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            return ngee;
        }
    
        vector<int> findPGE(vector<int>& nums) {
            int n = nums.size();
            vector<int> pge(n);
            stack<int> st;
            for (int i=0; i<n; i++) {
                while (!st.empty() && nums[st.top()] < nums[i])
                    st.pop();
                pge[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return pge;
        }
    
        long long sumSubarrayMax(vector<int>& nums) {
            vector<int> ngee = findNGEE(nums);
            vector<int> pge = findPGE(nums);
    
            long long total = 0;
            for (int i=0; i<nums.size(); i++) {
                int left = i - pge[i];
                int right = ngee[i] - i;
                
                total += right * left * 1LL * nums[i];
            }
            return total;
        }
    
        long long subArrayRanges(vector<int>& nums) {
            long long maxSum = sumSubarrayMax(nums);
            long long minSum = sumSubarrayMins(nums);
            return maxSum - minSum;
        }
};