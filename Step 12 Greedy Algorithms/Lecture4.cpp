// Jump Game - I

// Problem Statement: Given an array where each element represents the maximum number of steps you can jump forward from that element, return true if we can reach the last index starting from the first index. Otherwise, return false.

// Example 1:
// Input:nums = [2, 3, 1, 0, 4]    
// Output: True
// Explanation:
// We start at index 0, with value 2 this means we can jump to index 1 or 2.
// From index 1, with value 3, we can jump to index 2, 3, or 4. However, if we jump to index 2 with value 1, we can only jump to index 3.
// So we jump to index 1 then index 4 reaching the end of the array.
// Hence, we return true.

// Algorithm / Intuition
// A greedy algorithm makes a series of choices, each of which looks the best at the moment, with the hope that these local optimizations will lead to a globally optimal solution. The key idea is to make the best possible choice at each step without considering the overall problem.
// For this problem, we keep track of the farthest position we can reach at any point in time. We iterate over the array and keep making the greedy choice of reaching the farthest by comparing if the current index can be reached by the previous indices or not.
// If we reach an index that is beyond the farthest position we can reach, we return false. Else, we keep updating the farthest position with the maximum index we can reach from the current index.
// TC: O(n)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;
// Input:nums = [2, 3, 1, 0, 4] 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i = 0; i < n; i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};