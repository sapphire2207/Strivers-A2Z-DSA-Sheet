// Candy Problem

// Problem Statement:
// You are given N children, each with a rating value. Your task is to distribute candies to these children under the following conditions:
// Each child must get at least one candy.
// A child with a higher rating must receive more candies than their immediate neighbors.
// Understanding the Problem with an Example:
// Example 1:
// Ratings: [1, 2, 3]
// Assign 1 candy to the first child.
// Since 2 > 1, the second child gets 2 candies.
// Since 3 > 2, the third child gets 3 candies.
// Total candies: 1 + 2 + 3 = 6.
// Example 2:
// Ratings: [1, 3, 2, 1]
// First pass (Left to Right): [1, 2, 1, 1]
// Second pass (Right to Left): [1, 3, 2, 1]
// Total candies: 1 + 3 + 2 + 1 = 7.

// Approach (Greedy Algorithm)
// Use Two Passes (Left to Right & Right to Left)
// First Pass (Left to Right):
// Ensure each child has more candies than the left neighbor if needed.
// Second Pass (Right to Left):
// Ensure each child has more candies than the right neighbor if needed.
// Take the maximum of both results for each child.
// TC: O(3N)
// SC: O(2N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            else{
                left[i] = 1;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
            else{
                right[i] = 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};


// Better approach:
// We only need the sum of candies, not the exact distribution.
// Instead of storing the right array, compute it on the fly while iterating.
// Use a variable current to track the right side.
// TC: O(2N)
// SC: O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        vector<int> left(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            else{
                left[i] = 1;
            }
        }
        
        int current = 1, rightt = 1;
        int sum = max(1, left[n-1]);
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                current = rightt + 1;
                rightt = current;
            }
            else{
                current = 1;
            }
            sum = sum + max(left[i], current);
        }
        return sum;
    }
};

// Optimal Approach*********:
// Handling Flat Surfaces:
// If ratings[i] == ratings[i - 1], simply give 1 candy and move ahead.
// Handling Increasing Slopes:
// If ratings[i] > ratings[i - 1], increase candies progressively.
// Maintain a peak value.
// Handling Decreasing Slopes:
// If ratings[i] < ratings[i - 1], decrease candies progressively.
// Compare down and peak to adjust the peak when necessary.
// Time Complexity:
// O(N) since we traverse the list only once.
// Space Complexity:
// O(1) since we use only a few integer variables.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int sum = 1; // Start with 1 candy for the first child
        int i = 1;

        while (i < n) {
            // If it's a flat surface, just give 1 candy and move on
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            // Increasing slope: Give more candies progressively
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak = peak + 1;
                sum += peak;
                i++;
            }

            // Decreasing slope: Reduce candies progressively
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;              
                down = down + 1;
                i++;
            }

            if (down > peak) {
                sum += (down - peak);
            }
        }
        return sum;
    }
};
