// Maximal Rectangle:
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Input: matrix = 
// [
//  ["1","0","1","0","0"],
//  ["1","0","1","1","1"],
//  ["1","1","1","1","1"],
//  ["1","0","0","1","0"]
// ]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.


// Optimal Approach:
// The problem can be reduced to the Largest Rectangle in Histogram problem.
// Convert each row of the matrix into heights (like histogram bars).
// Use prefix sum to compute the height of 1s at each column.
// Apply the Largest Rectangle in Histogram algorithm to each row.
// TC: O(N*M*2M)
// SC: O(N*M) + O(N);
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<int> st;
            int maximumArea = 0;
            for(int i = 0; i < n; i++){
                while (!st.empty() && heights[st.top()] > heights[i]) {
                    int element = st.top();
                    st.pop();
                    int nse = i;
                    int pse = st.empty() ? -1 : st.top();
                    maximumArea = max(maximumArea, heights[element] * (nse - pse - 1));
                }
                st.push(i);
            }
    
            while(!st.empty()){
                int nse = n;
                int element = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maximumArea = max(maximumArea, (heights[element] * (nse - pse - 1)));
            }
            return maximumArea;
        }
    
        int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> prefixSum(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    prefixSum[j]++;
                }
                if(matrix[i][j] == '0') {
                    prefixSum[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(prefixSum));
        }
        return maxArea;
        }
    };