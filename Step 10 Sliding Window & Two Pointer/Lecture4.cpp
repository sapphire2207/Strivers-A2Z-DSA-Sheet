// Max Consecutive Ones Part III

// Problem Statement
// You are given a binary array consisting of 1s and 0s and an integer K. Your task is to determine the maximum length of consecutive 1s that can be obtained by flipping at most K zeros to 1s.

// Example:
// Input: nums = [1,1,1,1,0,0,0,1,1,1,1,0], K = 2
// Possible flips:
// Flipping two 0s to 1s can give a maximum consecutive sequence of 6 ones.
// Output: 6

// Brute Force Approach:
// Generate all possible subarrays.
// Count the number of zeros in each subarray.
// If the count of zeros is ≤ K, calculate the length of that subarray.
// Keep track of the maximum valid length found.
// Time Complexity:
// O(n²) (nested loops)
// Space Complexity
// O(1) (no extra space used)
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestOnes(vector<int> &nums, int k){
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++){
            int zeroes = 0;
            for (int j = i; j < n; j++){
                if (nums[j] == 0){
                    zeroes++;
                }
                else if (zeroes <= k){
                    int length = j - i + 1;
                    maxLen = max(length, maxLen);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};


// Better Approach:
// The sliding window technique helps find the longest contiguous subarray that contains at most k zeros.
// We maintain two pointers (left and right) to track the window boundaries.
// A variable (zeros) keeps track of the number of zeros in the current window
// If the zeros increarse more than k.... we keep on shrinking left pointer and calculate the maxLen for each and every left pointer's iteration until the zeros are taken care according to the condition i.e zeros should atmost be k....
// TC: O(N + N)
// SC: O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int left = 0, right = 0, zeroes = 0;
        while(right < n){ 
            if(nums[right] == 0){
                zeroes++;
            }
            while(zeroes > k){
                if(nums[left] == 0) zeroes--;
                left++;
            }
            if(zeroes <= k){
                int length = right - left + 1;
                maxLen = max(length, maxLen);
            }
            right++;
        }
        return maxLen;
    }
};

// Optimal Approach:
// Here the approach is same as the better... but here we don't change the maxLen variable.... since we need a higher maxLen.... we just keep on moving forward by making changes to the left and right pointers... here we are trying to stay fixed on our goal....
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int left = 0, right = 0, zeroes = 0;
        while(right < n){ 
            if(nums[right] == 0){
                zeroes++;
            }
            if(zeroes > k){
                if(nums[left] == 0) zeroes--;
                left++;
            }
            // if(zeroes <= k){
            //     int length = right - left + 1;
            //     maxLen = max(length, maxLen);
            // }
            int length = right - left + 1;
            maxLen = max(length, maxLen);
            right++;
        }
        return maxLen;
    }
};