// Shortest Palindrome

// You are given a string s. You can convert s to a palindrome by adding characters in front of it.
// Return the shortest palindrome you can find by performing this transformation.

// Example 1:
// Input: s = "aacecaaa"
// Output: "aaacecaaa"

// Example 2:
// Input: s = "abcd"
// Output: "dcbabcd"

// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of lowercase English letters only.

// Approach — Using KMP Prefix Function
// We can use the KMP (Knuth–Morris–Pratt) prefix table idea to find the longest palindromic prefix.
// Idea:
// Make a new string:
// temp = s + '#' + reverse(s)
// (The # is a separator to avoid overlap.)
// Compute the LPS (Longest Prefix Suffix) array for temp.
// The last value of LPS tells us how many characters at the start of s form a palindrome.
// Add the remaining suffix (non-palindromic part) reversed in front of s.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        string temp = s + "#" + rev;
        int n = temp.size();
        vector<int> lps(n, 0);
        
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j])
                j = lps[j - 1];
            if (temp[i] == temp[j])
                j++;
            lps[i] = j;
        }
        
        int longestPrefix = lps[n - 1];
        string add = rev.substr(0, s.size() - longestPrefix);
        return add + s;
    }
};

// TC and SC: O(N)