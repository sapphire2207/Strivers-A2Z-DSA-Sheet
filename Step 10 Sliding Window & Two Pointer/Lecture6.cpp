// Longest Substring with At Most K Distinct Characters

// Problem Statement
// You are given:
// A string S consisting of lowercase/uppercase letters.
// An integer K (K ≥ 1), representing the maximum number of distinct characters allowed in the substring.
// Your goal:
// Find the longest contiguous substring that contains at most K distinct characters.

// Example:
// Input:
// S = "aabbcc"
// K = 2
// Output:
// 4

// Brute Force Approach
// Algorithm
// Generate all possible substrings.
// Check the number of distinct characters in each substring.
// If the number of distinct characters ≤ K, update the maximum length.
// TC: O(N*N) * log256
// SC: O(256)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        map<char, int> mpp;
        for(int i = 0; i < n; i++){
            mpp.clear();
            for(int j = i; j < n; j++){
                mpp[s[j]]++;
                if(mpp.size() <= k){
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
// Use a two-pointer (left and right) sliding window.
// Expand the window by moving right pointer.
// If the number of distinct characters exceeds K, shrink the window by moving left.
// Store and update the maximum valid window length.
// TC: O(N+N) + O(log256)
// SC: O(256)
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        map<char, int> mpp;
        while(right < n){
            mpp[s[right]]++;
            while(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            if(mpp.size() <= k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

// Optimal Solution:
// Here we are not letting the window size decrease than the maxLen calculated till a point.... since we need to maximize the length we just make a conditional check to keep the window length same and check for a larger size instead of continously removing elements....
// TC: O(N) + O(log256)
// SC: O(256)
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        map<char, int> mpp;
        while(right < n){
            mpp[s[right]]++;
            if(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            if(mpp.size() <= k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};