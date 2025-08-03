// Binary Subarrays With Sum

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.
// Example 1:
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,_,_]
// [1,0,1,0,_]
// [_,0,1,0,1]
// [_,_,1,0,1]

// Brute Force:
// Hashing with Prefix Sum (Optimal for Any Integers)
// Used in the "Subarrays with sum K" problem.
// Uses a Hash Map (Dictionary) to store prefix sums.
// Time Complexity: O(N)
// Space Complexity: O(N)
// This works for arrays with positive & negative numbers.
// But since we have a binary array, we can optimize space.


// Optimal Solution:
// Sliding Window / Two-Pointer
// Since we are given 1s and 0s, we can avoid using extra space.
// Key Idea
// Find subarrays where sum ≤ goal
// → Count of such subarrays = countAtMost(goal)
// Find subarrays where sum ≤ (goal - 1)
// → Count of such subarrays = countAtMost(goal - 1)
// Final Answer: - countAtMost(goal - 1)
// This removes extra subarrays with sums less than goal.
// TC: O(2 * 2N)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helperFunction(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int left = 0, right = 0, count = 0, sum = 0;
        while(right < n){
            sum += nums[right];
            while(sum > goal){
                sum = sum - nums[left];
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int numSubarraysWithSumLessThanGoal = helperFunction(nums, goal);
        int numSubarraysWithSumLessThanGoalMinusOne = helperFunction(nums, goal - 1);
        return numSubarraysWithSumLessThanGoal - numSubarraysWithSumLessThanGoalMinusOne;
    }
};