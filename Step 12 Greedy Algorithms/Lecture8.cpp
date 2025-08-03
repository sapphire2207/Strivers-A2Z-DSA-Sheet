// Non-overlapping Intervals

// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
// Example 1:
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:
// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:
// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Intuition and Approach
// This problem is similar to the N Meetings in One Room problem but in reverse.
// Understanding N Meetings in One Room
// In the N Meetings in One Room problem, we try to maximize the number of non-overlapping meetings.
// How it Helps Here?
// Instead of counting the maximum number of non-overlapping intervals, we count the minimum removals required.
// The number of removals is simply:
// total intervals − max non-overlapping intervals

// Greedy Algorithm Approach:
// Step 1: Sort by End Time
// Since we want to minimize overlaps, we sort the intervals by their end time in ascending order.
// Sort intervals by (end,start)
// Step 2: Select Maximum Non-Overlapping Intervals
// Start with the first interval (since it has the earliest end time).
// Iterate through the rest of the intervals and select only those intervals whose start time is greater than or equal to the last selected interval's end time.
// Keep counting the selected intervals.
// Step 3: Calculate the Minimum Removals
// Removals = n − count of selected intervals
// TC: O(n logn + n)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(const vector<int>& val1, const vector<int>& val2) {
        return val1[1] < val2[1]; 
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;  
        sort(intervals.begin(), intervals.end(), comparator);

        int lastEndTime = intervals[0][1]; 
        int count = 1;  
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= lastEndTime) { 
                count++;
                lastEndTime = intervals[i][1];
            }
        }
        return intervals.size() - count; 
    }
};
