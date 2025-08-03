// Minimum Window Subsequence

// Problem Description
// In this problem, you are given two strings s1 and s2. Your task is to find the shortest contiguous substring in s1 such that the entire string s2 is a subsequence of that substring. A subsequence is a sequence that can be derived from the other sequence by deleting some or no elements without changing the order of the remaining elements.
// For example, if s1 is "abcdebdde" and s2 is "bde", you have to find the shortest part of s1 that contains all the characters in s2 in the same order.
// Here are the conditions you need to satisfy:
// If no such window exists, return an empty string "".
// If there are multiple substrings of s1 that satisfy the condition, return the one with the left-most starting index.
// In the example given, the minimum window in s1 where s2 is a subsequence is "bcde".

// Brute Force:
// isSubsequence(window, s2): checks if s2 is a subsequence of the current substring window.
// We iterate all substrings of s1 starting from each i and ending at each j ≥ i.
// If a valid subsequence is found, we update the minLength and startIndex.
// TC: O(N^3) in worst case: O(N^2) for all substrings × O(M) for isSubsequence() where M = length of s2.
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) j++;
            i++;
        }
        return j == t.size();
    }

    string minWindow(string s1, string s2) {
        if (s1.empty() || s2.empty()) return "";

        int n = s1.size();
        int m = s2.size();
        int minLength = INT_MAX;
        int startIndex = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string window = s1.substr(i, j - i + 1);
                if (isSubsequence(window, s2)) {
                    if ((j - i + 1) < minLength) {
                        minLength = j - i + 1;
                        startIndex = i;
                    }
                    break; // No need to check longer substrings starting at i
                }
            }
        }

        return (startIndex == -1) ? "" : s1.substr(startIndex, minLength);
    }
};

// Optimal Approach:
// For each starting point i, we try to match the whole s2 in s1 (forward).
// Once matched, we backtrack to find the smallest window containing s2 in correct order.
// We keep track of the minimum length and its start index.
// TC: Worst-case: O(N * M) - For each position in s1, we scan forward to find a match of s2, then scan backward to tighten the window.
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int minLength = INT_MAX;
        int startIndex = -1;

        for (int i = 0; i < n; i++) {
            // Move forward to find a match
            int j = 0;
            int right = i;
            while (right < n) {
                if (s1[right] == s2[j]) {
                    j++;
                    if (j == m) break;
                }
                right++;
            }

            // If full s2 matched
            if (j == m) {
                // Now move backward to find the minimal left boundary
                int left = right;
                j = m - 1;
                while (left >= i) {
                    if (s1[left] == s2[j]) {
                        j--;
                        if (j < 0) break;
                    }
                    left--;
                }
                left++; // move to the actual start of window

                if ((right - left + 1) < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }

                // // Optional early stopping: if we already found a window starting from left = 0
                // if (minLength == m) break;
            }
        }

        return (startIndex == -1) ? "" : s1.substr(startIndex, minLength);
    }
};
