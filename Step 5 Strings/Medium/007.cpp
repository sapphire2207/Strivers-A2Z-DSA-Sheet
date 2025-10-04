// Sum of Beauty of All Substrings

// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

// Example 1:
// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

// Example 2:
// Input: s = "aabcbaa"
// Output: 17
 
// Constraints:
// 1 <= s.length <= 500
// s consists of only lowercase English letters.

// Approach:
// Loop through all substrings of the string.
// Maintain a frequency map of characters for each substring.
// For each substring:
// Find the most frequent character's count.
// Find the least frequent non-zero character's count.
// Calculate the difference between the two counts.
// Add the difference to the running sum.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char, int> mpp;
            for(int j = i; j < n; j++){
                mpp[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto it: mpp){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                beauty += (maxi - mini);
            }
        }
        return beauty;
    }
};

// Time Complexity:
// Outer loop: O(n) (for each starting index)
// Inner loop: O(n) (for each ending index)
// Computing max and min for frequencies: O(26) in the worst case (since only lowercase letters), O(n^2 * 26) ≈ O(n^2) because 26 is constant.
// Space Complexity:
// Frequency map uses at most 26 characters → O(26) = O(1).
// No extra data structures apart from that.