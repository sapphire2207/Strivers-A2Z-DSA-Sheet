// Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

// Approach:
// The goal is to find the longest palindromic substring by treating each character (and each pair) as a potential center.
// Every palindrome is symmetric, so we expand outward from a center to check for symmetry.
// There are two types of centers to consider: one at a character (odd-length) and one between characters (even-length).
// For each center, expand left and right while the characters on both sides match.
// Keep track of the maximum length palindrome found by updating its start and end indices.
// The final result is the substring between the recorded boundaries of the longest expansion.
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int expandFromCenter(const string& str, int left, int right) {
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int n = s.size();

        for(int center = 0; center < n; center++){
            int oddLength = expandFromCenter(s, center, center);
            int evenLength = expandFromCenter(s, center, center + 1);
            int maxLen = max(oddLength, evenLength);

            if(maxLen > end - start){
                start = center - (maxLen - 1) / 2;
                end = center + maxLen / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

// Time Complexity: O(N²) For each character, expanding could take up to O(N)
// Space Complexity: O(1) No extra space used.