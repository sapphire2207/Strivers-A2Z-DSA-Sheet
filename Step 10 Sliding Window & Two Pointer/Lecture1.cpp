// Four Patterns of Two Pointers and Sliding Window Techniques

// Four Patterns of Problems
// 1. Constant Window Size
// 2. Longest Subarray/Substring with a Condition
// 3. Number of Subarrays with a Condition
// 4. Shortest/Minimum Window with a Condition

// ### Constant Window Size
// Given: An array with positive and negative integers, and an integer K.
// Task: Find the maximum sum of K consecutive elements.
// Approach:
// Use two pointers: L (left) and R (right).
// Initialize L at the 0th index and R at the (K-1)th index.
// Calculate the sum of the first window (from L to R).
// Move the window by incrementing L and R by 1.
// Update the sum by subtracting the element at L and adding the element at R.
// Track the maximum sum encountered.
// TC: O(N)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class constantWindowSize{
    int maxiumSumOfSubarraySizeK(vector<int>& arr, int k){
        int n = arr.size();
        if (n < k) return -1;

        int windowSum = 0;
        int left = 0, right = k - 1;
        for (int i = left; i <= right; i++) {
            windowSum += arr[i];
        }
        int maxSum = windowSum;

        while(right < n-1){
            windowSum = windowSum - arr[left];
            left++;
            right++;
            windowSum = windowSum + arr[right];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
};

// ### Longest Subarray/Substring with a Condition
// Given: An array and a condition (e.g., sum ≤ K).
// Task: Find the longest subarray that satisfies the condition.
// Brute Force:
// Generate all possible subarrays.
// Check each subarray against the condition.
// Track the maximum length of valid subarrays.
// TC: O(N^2)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Type2{
    int longestSubarrayWithSumLessThanOrEqualK(vector<int>& arr, int k){
        int n = arr.size();
        int maxLenn = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum = sum + arr[j];
                if(sum <= k){
                    maxLenn = max(maxLenn, j - i + 1);
                }
                else if(sum > k){
                    break;
                }
            }
        }
        return maxLenn;
    }
};

// Better Solution:
// Use two pointers: L (left) and R (right).
// Expand the window by moving R and add elements to the sum.
// If the condition is violated, shrink the window by moving L.
// Track the maximum length of valid windows.
// TC: O(N) + O(N)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Type2{
    int longestSubarrayWithSumLessThanOrEqualK(vector<int>& arr, int k){
        int n = arr.size();
        int maxLenn = 0;
        int sum = 0;
        int left = 0, right = 0;
        while(right < n){
            sum = sum + arr[right];
            while(sum > k){
                sum = sum - arr[left];
                left++;
            }

            if(sum <= k) {
                maxLenn = max(maxLenn, right - left + 1);
            }
            right++;
        }
        return maxLenn;
    }
};

// Optimal Approach:
// Here the approach is same as better....
// But here we don't use while loop.... we just make a conditional check....
// Bcz if at a point we get a bigger length subarray.... then why should we keep on removing elements untill sum becomes less than k? since we are focusing on finding maxLen... there is no point in shortening the length.... so if sum > k.... just move the left pointer ahead and try to find a bigger length sub array than the current one....
// TC: O(N)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Type2{
    int longestSubarrayWithSumLessThanOrEqualK(vector<int>& arr, int k){
        int n = arr.size();
        int maxLenn = 0;
        int sum = 0;
        int left = 0, right = 0;
        while(right < n){
            sum = sum + arr[right];
            if(sum > k){
                sum = sum - arr[left];
                left++;
            }

            if(sum <= k) {
                maxLenn = max(maxLenn, right - left + 1);
            }
            right++;
        }
        return maxLenn;
    }
};

// ### Number of Subarrays with a Condition
// Problem Example
// Given: An array and a condition (e.g., sum = K).
// Task: Find the number of subarrays that satisfy the condition.
// Approach:
// Sliding Window:
// Use the same sliding window technique as in Pattern 2.
// Count the valid subarrays.
// Calculate the number of subarrays with sum ≤ K.
// Calculate the number of subarrays with sum ≤ (K - 1).
// Subtract the two results to get the number of subarrays with sum = K.

// ### Shortest/Minimum Window with a Condition
// Here the approach is to maintain two pointers left and right..... and find a valid minimum window...
// Now keep on trying to shrink the window from left and check whether it's a valid minimum window or not
// And atlast the shortest one which satisifies the condition will be the answer