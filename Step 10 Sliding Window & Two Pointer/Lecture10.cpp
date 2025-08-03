// Count Number of Nice Subarrays

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

// Example 1:
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

// Optimal Approach:
// This problem is similar to Binary Subarrays with Sum.
// Convert odd numbers to 1 and even numbers to 0.
// nums = [1, 1, 2, 1, 1]  →  [1, 1, 0, 1, 1]
// Now, the problem reduces to counting subarrays where the sum is exactly K
// TC: O(2*2N)
// SC: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helperFunction(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int left = 0, right = 0, count = 0, sum = 0;
        while(right < n){
            sum = sum + (nums[right] % 2);
            while(sum > k){
                sum = sum - (nums[left] % 2);
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int numSubarraysWithSumLessThanGoal = helperFunction(nums, k);
        int numSubarraysWithSumLessThanGoalMinusOne = helperFunction(nums, k - 1);
        return numSubarraysWithSumLessThanGoal - numSubarraysWithSumLessThanGoalMinusOne;
    }
};