// Area of largest rectangle in Histogram

// Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.


// Brute Force:
// The intuition behind the approach is the same as finding the smaller element on both sides but in an optimized way using the concept of the next greater element and the next smaller element.
// TC: 2 * O(2N) => for finding nse and pse + O(N) => O(5N)
// SC: O(2n) + O(2n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findNSE(vector<int>& heights){
            int n = heights.size();
            vector<int> nse(n, 0);
            stack<int> st;
            for(int i = n - 1; i >= 0; i--){
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                nse[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            return nse;
        }
    
        vector<int> findPSE(vector<int>& heights) {
            int n = heights.size();
            vector<int> pse(n, 0);
            stack<int> st;
            for(int i = 0; i< n; i++) {
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                pse[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return pse;
        }
    
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> nse(n, 0);
            vector<int> pse(n, 0);
            nse = findNSE(heights);
            pse = findPSE(heights);
            int maximumArea = 0;
            for(int i = 0; i < n; i++){
                maximumArea = max(maximumArea, heights[i] * (nse[i] - pse[i] - 1));
            }
            return maximumArea;
        }
};

// Optimised Approach:
// This approach is a single pass approach instead of a two-pass approach. When we traverse the array by finding the next greater element, we found that some elements were inserted into the stack which signifies that after them the smallest element is themselves
// So we can find the area of the rectangle by using arr[i] * (right smaller - left smaller -1 ).
// TC: O(N) + O(N) => O(2N)
// SC: O(N)
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
    };