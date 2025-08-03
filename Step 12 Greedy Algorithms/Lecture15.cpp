// Merge Overlapping Sub-intervals

// Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
// Example 1:
// Input:
//  intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output:
//  [[1,6],[8,10],[15,18]]
// Explanation:
//  Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
//  intervals.

// Brute Force:
// Intuition:
// The intuition of this approach is pretty straightforward. We are just grouping close intervals by sorting the given array. After that, we merge an interval with the other by checking if one can be a part of the other interval. For this checking, we are first selecting a particular interval using a loop and then we are comparing the rest of the intervals using another loop.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

// Output: [[1,6],[8,10],[15,18]]
// Complexity Analysis
// Time Complexity: O(N*logN) + O(2*N), where N = the size of the given array.
// Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N2.
// Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.

// Optimal Approach: 
// Intuition:
// In the previous approach, while checking the intervals, we first selected an interval using a loop and then compared it with others using another loop. But in this approach, we will try to do the same using a single loop. Let’s understand how:
// We will start traversing the given array with a single loop. At the first index, as our answer list is empty, we will insert the first element into the answer list. While traversing afterward we can find two different cases:
// Case 1: If the current interval can be merged with the last inserted interval of the answer list:
// In this case, we will update the end of the last inserted interval with the maximum(current interval’s end, last inserted interval’s end) and continue moving afterward. 
// Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
// In this case, we will insert the current interval in the answer array as it is. And after this insertion, the last inserted interval of the answer list will obviously be updated to the current interval.
// Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our answer list.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

// Output: [[1,6],[8,10],[15,18]]
// Complexity Analysis
// Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
// Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).
// Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.