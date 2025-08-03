// Fruit Into Baskets

// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.
// Example 1:
// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:
// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].

// Brute Force:
// Generate all possible subarrays and check which one contains at most two unique numbers.
// Time Complexity Analysis:
// The outer loop runs O(N) times.
// The inner loop runs at most O(N) times.
// Overall Complexity = O(N^2).
// Space Complexity Analysis:
// The set stores at most 3 elements.
// Space Complexity = O(1) (since the set size is constant).
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            set<int> st;
            for(int j = i; j < n; j++){
                st.insert(fruits[j]);
                if(st.size() <= 2){
                    maxLen = max(maxLen, j - i + 1);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};

// Better Solution:
// Initialize Two Pointers:
// Left Pointer (L) at index 0.
// Right Pointer (R) at index 0.
// Use a Map (or Hash Table) to Track Frequency:
// Keep track of the count of unique elements.
// This helps check if the window is valid.
// Use a Variable to Track Maximum Length:
// maxLength = 0 to store the maximum valid subarray length.
// Expand the Window (Move R Right):
// Add arr[R] to the frequency map.
// Check if the window is valid (i.e., contains at most K unique elements).
// If the Window is Valid:
// Update maxLength as R - L + 1.
// If the Window is Not Valid:
// Shrink the window by moving L right until the condition is met.
// Reduce frequency or remove elements from the map.
// Continue Until R Traverses the Array.
// TC: O(N + N)
// SC: O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        int maxLen = 0;
        map<int, int> mpp;
        while(right < n){
            mpp[fruits[right]]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[left]]--;
                    if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                    left++;
                }
            }
            if(mpp.size() <= 2){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

// Optimised Approach:
// Instead of moving L all the way in one step using a while loop, We trim the window gradually by moving L one step at a time when the window becomes invalid. This ensures the total number of movements for both pointers is at most N.....
// TC: O(N)
// SC: O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        int maxLen = 0;
        map<int, int> mpp;
        while(right < n){
            mpp[fruits[right]]++;
            if(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }
            
            if(mpp.size() <= 2){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};