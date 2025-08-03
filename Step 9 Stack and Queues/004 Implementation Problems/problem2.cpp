// Sliding Window Maximum

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.
// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// Brute Force:
// Iterate over the array and consider each subarray (window) of size k.
// Find the maximum element in each window.
// Store the maximum in a result list.
// TC: O(N - K) * K
// SC: O(N - K)
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> ans;
            for(int i = 0; i <= n - k; i++){
                int maximum = nums[i];
                for(int j = i; j < i + k; j++){
                    maximum = max(maximum, nums[j]);
                }
                ans.push_back(maximum);
            }
            return ans;
        }
    };

// Optimised approach:
// We need an efficient way to maintain the maximum of the window.
// A deque (double-ended queue) can help efficiently keep track of maximums.
// The deque should maintain elements in decreasing order to always get the max in O(1) time.
// Algorithm:
// Use a deque to store indices of elements, ensuring it maintains a decreasing order.
// At each step:
// Remove elements from the back of the deque that are smaller than the current element.
// Remove elements from the front if they are out of the current window.
// The front of the deque always contains the max of the window.
// Store the maximum element from the deque for each window.
// TC: O(N) + O(N)
// SC: O(K) + O(N-K)
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> ans;
            deque<int> dq;
            for(int i = 0; i < n; i++){
                if(!dq.empty() && dq.front() <= i - k){
                    dq.pop_front();
                }
                while(!dq.empty() && nums[dq.back()] <= nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
                if(i >= k - 1) ans.push_back(nums[dq.front()]);
            }
            return ans;
        }
    };