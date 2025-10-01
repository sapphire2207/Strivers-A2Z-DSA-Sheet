// Isomorphic String

// Problem Statement: Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1
// Input: s = "paper", t = "title"
// Output: true
// Explanation: The characters in "s" can be mapped one-to-one to characters in "t": 
// 'p' → 't', 'a' → 'i', 'e' → 'l', 'r' → 'e'
// Since the mapping is consistent and unique for each character, the strings are isomorphic.

// Example 2
// Input: s = "foo", t = "bar"
// Output: false
// Explanation: 'f' → 'b' is fine, 'o' → 'a' for the first 'o', But the second 'o' in "s" would need to map to 'r' in "t", which conflicts with the earlier mapping of 'o' → 'a'
// This inconsistency makes it impossible to convert "s" to "t" using a one-to-one character mapping.

// Solution Approach:
// Think of isomorphism as a consistent one-to-one mapping between characters of two strings.
// The goal is to ensure the pattern of appearances and repetitions is identical in both strings.
// Use two fixed-size arrays (size 256) to track the last-seen positions of characters from each string.
// While scanning both strings together, compare if the characters at the current position have been seen at the same relative positions before.
// If not, it indicates inconsistent mapping — one character maps to multiple others — return false.
// If consistent, update the last seen position of both characters to ensure future checks remain valid.
// This approach confirms isomorphic structure by comparing character occurrence patterns, not the characters themselves.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256, 0);
        vector<int> m2(256, 0);

        int n = s.size();

        for(int i = 0; i < n; i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

// Time Complexity: O(N) where N is the length of the input strings, due to the single loop iterating through each character.
// Space Complexity: O(1) since the space used by the arrays is constant (256 fixed size) regardless of input size