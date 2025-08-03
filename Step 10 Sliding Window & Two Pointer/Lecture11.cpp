// Subarrays with K Different Integers

// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

// Brute Force:
// Generate all possible subarrays.
// Use a hashmap to track distinct elements.
// Count only those subarrays where the number of distinct elements is exactly K
// TC: O(N*N)
// SC: O(N)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            map<int, int> mpp;
            for(int j = i; j < n; j++){
                mpp[nums[j]]++;
                if(mpp.size() == k){
                    count = count + 1;
                }
                else if(mpp.size() > k){
                    break;
                }
            }
        }
        return count;
    }
};

// Optimal Solution:
// Instead of counting subarrays with exactly K distinct elements directly,
// we count:
// Subarrays with at most K distinct elements.
// Subarrays with at most K-1 distinct elements.
// Result = (Subarrays with ≤ K) - (Subarrays with ≤ K-1)
// Why This Works?
// Subarrays with exactly K distinct elements are found by subtracting extra subarrays that have fewer than K distinct elements.
// This ensures we only count the valid ones.
// TC: O(2*2N)
// SC: O(2*N)
// Input: nums = [1,2,1,2,3], k = 2
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helperFunction(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int left = 0, right = 0, count = 0;
        map<int, int> mpp;
        while(right < n){
            mpp[nums[right]]++;
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int numSubarraysWithLessThanKDistinct = helperFunction(nums, k);
        int numSubarraysWithLessThanKMinusOneDistinct = helperFunction(nums, k - 1);
        return numSubarraysWithLessThanKDistinct - numSubarraysWithLessThanKMinusOneDistinct;
    }
};