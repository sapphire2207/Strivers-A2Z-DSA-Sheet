// Maximum Points You Can Obtain from N Cards

// Problem Statement:
// You are given an array nums containing points of n different cards. Each card has an associated point value. You are also given an integer K, which indicates that you must pick exactly K cards from these n cards. However, there is a condition:
// You can only pick cards from the front or the back, but not from the middle.
// The cards must be picked consecutively from either end.
// Your task is to maximize the number of points obtained by selecting K cards.

// Example
// Input:
// nums = [6, 2, 3, 4, 1, 7, 1, 2]
// K = 4
// Possible ways to pick cards:
// Pick first 4 cards: 6 + 2 + 3 + 4 = 15
// Pick last 4 cards: 1 + 7 + 1 + 2 = 11
// Pick 3 from the front and 1 from the back: 6 + 2 + 3 + 1 = 12
// Pick 2 from the front and 2 from the back: 6 + 2 + 1 + 7 = 16 (Maximum)
// Output: 16

// Brute Force Approach:
// Try all possible combinations of picking cards from the left and right.
// Compute the sum for each case.
// Return the maximum sum obtained.

// Optimized Approach (Sliding Window):
// The problem can be optimized using the sliding window technique:
// Compute the sum of the first K elements (i.e., picking all from the left).
// Gradually shift the window by removing one element from the left and adding one element from the right.
// Keep track of the maximum sum encountered.
// Time Complexity: O(K + K)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxScore(vector<int> &cardPoints, int k){
        int n = cardPoints.size();
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;
        for (int i = 0; i <= k - 1; i++){
            leftSum = leftSum + cardPoints[i];
        }
        maxSum = leftSum;

        int right = n - 1;
        for (int i = k - 1; i >= 0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[right];
            right--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};