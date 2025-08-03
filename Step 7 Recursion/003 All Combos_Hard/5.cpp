// Word Break

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Intuition:
// We want to split the string into parts such that each part exists in the dictionary.
// Try to break the string at every position and recursively check both parts.
// Use memoization to avoid recomputation of subproblems.

// Approach Steps:
// Convert the word dictionary into a Set for O(1) lookup.
// Use a recursive function solve(start, end):
// Try forming a substring from start to end.
// If it's in the dictionary, recursively call solve(end+1, end+1).
// Also try to extend the current substring (end++).
// Use a 2D DP array dp[start][end] to memoize results.
// If we reach the end of the string with valid splits, return true.

// Dry Run:
// start = 0, end = 0, checking s[0:1] = "a" → not in dictionary
// end = 1, s[0:2] = "ap" → not in dict
// ...
// end = 4, s[0:5] = "apple" → present in dict
// → Recurse solve(5, 5, ...) for "penapple"
// s[5:8] = "pen" → present in dict
// → Recurse solve(8, 8, ...) for "apple"
// s[8:13] = "apple" → reached end
// → Return true
// Memoization:
// dp[i][j] caches results for substrings s[i...j]
// Avoids re-checking same substrings (saves time)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int start, int end, string &s, unordered_set<string> &wd, vector<vector<int>> &dp) {
        if (dp[start][end] != -1) return dp[start][end] == 1;

        if (end == s.length() - 1) {
            if (wd.count(s.substr(start, end - start + 1))) return dp[start][end] = 1;
            return dp[start][end] = 0;
        }

        if (wd.count(s.substr(start, end - start + 1))) {
            if (solve(end + 1, end + 1, s, wd, dp)) {
                return dp[start][end] = 1;
            }
        }

        return dp[start][end] = solve(start, end + 1, s, wd, dp) ? 1 : 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        return solve(0, 0, s, wd, dp);
    }
};

// Time Complexity:
// O(n²) for the number of substring combinations (start to end) × average time to check substrings and dictionary (O(1) for set lookup). So overall time is O(n²).

// Space Complexity:
// O(n²) for the 2D DP table and O(k) for storing the dictionary in a set, where n is the string length and k is the total length of words in wordDict. Also, recursion depth goes up to O(n).

