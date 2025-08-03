// Minimum Window Substring

// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
// The testcases will be generated such that the answer is unique.
// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Brute Force:
// Generate all substrings of s.
// Check if each substring contains all characters in t.
// Update the minimum window if a valid substring is found.
// TC: O(N*N)
// SC: O(256)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int n = s.size();
        int m = t.size();
        int minLength = INT_MAX;
        int startIndex = -1;
        string ans = "";
        for(int i = 0; i < n; i++){
            map<char, int> mpp;
            int count = 0;
            for(int j = 0; j < m; j++){
                mpp[t[j]]++;
            }
            for(int j = i; j < n; j++){
                if(mpp[s[j]] > 0) count = count + 1;
                mpp[s[j]]--;
                if(count == m){
                    if(j - i + 1 < minLength){
                        minLength = j - i + 1;
                        startIndex = i;
                        break;
                    }
                }
            }
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minLength);
    }
};


// Optimal Approach:
// Use a frequency map to track character counts in t.
// Expand the window from the right and contract from the left when all characters are matched.
// Keep track of the minimum valid window.
// TC: O(N)
// SC: O(256)
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int n = s.size();
        int m = t.size();

        map<char, int> mpp;
        for (int i = 0; i < m; i++) {
            mpp[t[i]]++;
        }

        int minLength = INT_MAX;
        int startIndex = -1;
        string ans = "";
        int left = 0, right = 0, count = 0;
        while(right < n){
            if(mpp[s[right]] > 0){
                count = count + 1;
            }
            mpp[s[right]]--;
            while(count == m){
                if(right - left + 1 < minLength){
                    minLength = right - left + 1;
                    startIndex = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0) count = count - 1;
                left++;
            }
            right++;
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minLength);
    }
};