// Jump Game II

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

// Recursive approach (Brute Force):
// We start at index 0 with jumps = 0.
// From each index, explore all possible jumps.
// Keep track of the minimum jumps required to reach the last index.
// Use recursion to try all possibilities.
// helper(nums, 0, 0)
//  ├── helper(nums, 1, 1)
//  │    ├── helper(nums, 2, 2)
//  │    │    ├── helper(nums, 3, 3)
//  │    │    │    ├── helper(nums, 4, 4) → 4 jumps (Not optimal)
//  │    ├── helper(nums, 3, 2)
//  │    │    ├── helper(nums, 4, 3) → 3 jumps (Better)
//  │    ├── helper(nums, 4, 2) → 2 jumps (Best)
//  ├── helper(nums, 2, 1) → 4 jumps (Not optimal)
// Time Complexity:
// Exponential (O(n^n)) since every index can lead to multiple recursive calls.
// Each call has multiple choices, leading to a branching factor of n.
// Space Complexity:
// O(n) (due to recursion stack depth).
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(vector<int>& nums, int index, int jumps){
        if(index >= nums.size() - 1) return jumps;
        int mini = INT_MAX;
        for(int i = 1; i <= nums[index]; i++){
            mini = min(mini, helper(nums, index + i, jumps + 1));
        }
        return mini;
    }

    int jump(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};

// Greedy approach:
// Track the farthest position you can reach at each step.
// Expand the reachable range as you move forward.
// Count the number of times you extend the range (these are the jumps).
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int jumps = 0;
        while(right < n - 1){
            int farthest = 0;
            for(int i = left; i <= right; i++){
                farthest = max(farthest, i + nums[i]);
            }
            left = right + 1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
};