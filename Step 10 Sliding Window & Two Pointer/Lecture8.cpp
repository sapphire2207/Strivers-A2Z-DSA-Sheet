// Longest Repeating Character Replacement

// Problem Statement
// We are given a string consisting of uppercase letters and an integer K. The integer K signifies that we can replace at most K characters in the string to maximize the length of a substring where all characters are the same.
// Our goal is to determine the longest possible substring with all identical characters after performing at most K replacements.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Brute Force:
// Generate all possible substrings.
// Count how many characters need to be changed. --> changes should be made to minimum freq possible till a particular length(j - i + 1).... So therefore length - maxFreq....
// Check if the number of changes is within K.
// Keep track of the maximum valid substring length.
// TC: O(N*N)
// SC: O(26)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            vector<int> hash(26, 0);
            int maxFreq = 0;
            for(int j = i; j < n; j++){
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);
                int changes = (j - i + 1) - maxFreq;
                if(changes <= k){
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

// Better Approach: Sliding Window
// Since this problem involves substrings and replacements, we can use the sliding window technique with two pointers (left and right)
// Maintain a frequency hash of characters within the current window.
// Keep track of the maximum frequency of any character in the window.
// Calculate required replacements:
// (window length) - (max frequency)
// If replacements exceed K, shrink the window from the left.
// Track the longest valid window.
// TC: O(N + N) + O(26)
// SC: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int maxFreq = 0;
        int left = 0, right = 0;
        vector<int> hash(26, 0);
        while(right < n){
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right] - 'A']);
            while((right - left + 1) - maxFreq > k){    
                hash[s[left] - 'A']--;
                maxFreq = 0;
                for(int k = 0; k < 26; k++){
                    maxFreq = max(maxFreq, hash[k] - 'A');
                }
                left++;
            }
            if((right - left + 1) - maxFreq <= k){ 
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

// Optimised Approach:
// Since we want to increase the maxlen... there is no point in cutting down the left sub array whenever you find someone wrong... you should just try to increase maxLen.... 
// And there's no need to update the maxFreq.... becz to find maxLen more.... to maximize the maxLen.... maxFreq should also be more... there's no point in again calculating the maxFreq for every index....
// TC: O(N)
// SC: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int maxFreq = 0;
        int left = 0, right = 0;
        vector<int> hash(26, 0);
        while(right < n){
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right] - 'A']);
            if((right - left + 1) - maxFreq > k){    
                hash[s[left] - 'A']--;
                left++;
            }
            if((right - left + 1) - maxFreq <= k){ 
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};