// Length of Longest Substring without any Repeating Character

// Problem Statement: Given a String, find the length of longest substring without any repeating character.
// Examples:
// Input: s = ”abcabcbb”
// Output: 3
// Explanation: The answer is abc with length of 3.

// Brute force Approach:
// This approach consists of taking the two loops one for traversing the string and another loop - nested loop for finding different substrings and after that, we will check for all substrings one by one and check for each and every element if the element is not found then we will store that element in HashMap otherwise we will break from the loop and count it.
// TC: O(N*N)
// SC: O(256)
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            vector<int> hashMap(256, 0);
            for(int j = i; j < n; j++){
                if(hashMap[s[j]] == 1) break;
                int length = j - i + 1;
                maxLen = max(length, maxLen);
                hashMap[s[j]] = 1;
            }
        }
        return maxLen;
    }
};

// Optimal Appraoch:
// In this approach, we will make a map that will take care of counting the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.
// TC: O(N)
// SC: O(256)
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        vector<int> hashMap(256, -1);
        while (right < n){
            if (hashMap[s[right]] != -1){
                if (hashMap[s[right]] >= left){
                    left = hashMap[s[right]] + 1;
                }
            }
            int length = right - left + 1;
            maxLen = max(maxLen, length);
            hashMap[s[right]] = right;
            right++;
        }
        return maxLen;
    }
};